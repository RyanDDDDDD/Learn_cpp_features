#include <chrono>
#include <condition_variable>
#include <coroutine>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <thread>

//////////////////////////////////////
// Event Loop
//////////////////////////////////////
class EventLoop {
public:
    using TaskFn = std::function<void ()>;

    void post (TaskFn fn) {
        {
            std::lock_guard<std::mutex> lock (mtx_);
            queue_.push (std::move (fn));
        }
        cv_.notify_one ();
    }

    void run () {
        while (true) {
            TaskFn fn;
            {
                std::unique_lock<std::mutex> lock (mtx_);
                cv_.wait (lock, [this] () { return !queue_.empty (); });
                fn = std::move (queue_.front ());
                queue_.pop ();
            }
            fn ();
        }
    }

    static EventLoop& instance () {
        static EventLoop loop;
        return loop;
    }

private:
    std::queue<TaskFn> queue_;
    std::mutex mtx_;
    std::condition_variable cv_;
};

//////////////////////////////////////
// Task coroutine type
//////////////////////////////////////
struct Task {
    struct promise_type {
        Task get_return_object () {
            return Task{ std::coroutine_handle<promise_type>::from_promise (*this) };
        }
        std::suspend_never initial_suspend () {
            return {};
        }
        std::suspend_always final_suspend () noexcept {
            return {};
        }
        void return_void () {
        }
        void unhandled_exception () {
            std::terminate ();
        }
    };

    std::coroutine_handle<promise_type> handle;
    Task (std::coroutine_handle<promise_type> h) : handle (h) {
    }

    ~Task () {
        if (handle)
            handle.destroy ();
    }
};

//////////////////////////////////////
// Asynchronous file read awaitable
//////////////////////////////////////
struct AsyncFileRead {
    std::string filename;
    std::string content;
    std::coroutine_handle<> handle;

    bool await_ready () {
        return false;
    } // Always suspend

    void await_suspend (std::coroutine_handle<> h) {
        handle = h;
        // Simulate asynchronous file I/O using a thread,
        // then resume the coroutine via the event loop
        std::thread ([this, h] () {
            std::ifstream file (filename);
            if (file.is_open ()) {
                content.assign ((std::istreambuf_iterator<char> (file)),
                std::istreambuf_iterator<char> ());
                file.close ();
            } else {
                content = "Failed to open file";
            }

            // After I/O completes, post resume operation to the event loop
            EventLoop::instance ().post ([h] () {
                h.resume (); // Resume the coroutine
            });
        })
        .detach ();
    }

    std::string await_resume () {
        return content;
    }
};

//////////////////////////////////////
// Coroutine usage: read file
//////////////////////////////////////
Task readFileCoroutine (const std::string& path) {
    std::cout << "[Coroutine] Start reading file: " << path << "\n";
    std::string content = co_await AsyncFileRead{ path };
    std::cout << "[Coroutine] File content:\n" << content << "\n";
    std::cout << "[Coroutine] Continue after file read\n";
}

//////////////////////////////////////
// main
//////////////////////////////////////
int main () {
    // Start the event loop in a separate thread
    std::thread ([] () { EventLoop::instance ().run (); }).detach ();

    // Start coroutine to read file
    Task t = readFileCoroutine ("/Users/wuruidong/Desktop/testCpp/example.txt");

    // Keep the main thread alive long enough to observe coroutine output
    std::this_thread::sleep_for (std::chrono::seconds (5));
}
