#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

class Y: public enable_shared_from_this<Y>
{
public:

    shared_ptr<Y> f()
    {
        // 1.
        // this will create a shared_ptr with new control block, to manage resource
        // which means, there will exist multiple shared ptr using different control block which 
        // reference the same memory resource 
        // 2. 
        // on the other hand, it is not safe to return a raw this ptr to user when we use a raw pointer
        // to reference resource, "this" could be released when the object goes out of the scope
        // return std::shared_ptr<Y>(this);
        
        return shared_from_this();
    }

    void print() {
        std::cout << "hello world" << std::endl;
    }

};

int main()
{
    shared_ptr<Y> p(new Y);
    shared_ptr<Y> q = p->f();

    p->print();
    q->print();

    std::cout << p.use_count() << std::endl;
    std::cout << q.use_count() << std::endl;

    assert(p == q);
    assert(!(p < q || q < p)); // p and q must share ownership


    std::cout << "end of program" << std::endl;
}



