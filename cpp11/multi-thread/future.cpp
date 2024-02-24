#include <future>
#include <iostream>
#include <unistd.h>

void future_task() {
	sleep(2);

	std::cout << "Task is done" << std::endl;
}

int main() {
	std::future<void> ft = std::async(future_task);

	std::cout << "Do some stuff" << std::endl;
}
