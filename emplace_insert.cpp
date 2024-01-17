#include <iostream>
#include <vector>

struct A
{
    A() = default ;

    A( int ii, const std::string& ss ) : i(ii), str(ss)
    { std::cout << "construct object from args\n" ; }

    A( const A& that ) : i(that.i), str(that.str)
    { std::cout << "copy object\n" ; }

    int i = 0 ;
    std::string str ;
};

int main ()
{
    std::vector<A> seq ;
    
    // resize container
    seq.reserve(10) ;

    A a ;

    seq.push_back(a) ; // copy object into the container
    seq.insert( seq.end(), a ) ; // copy object into the container
    std::cout << "-------------\n" ;

    seq.push_back( A( 10, "hello" ) ) ; // construct an anonymous object
                                        // copy (or move) the anonymous object into the container
                                        // destroy the anonymous object
    std::cout << '\n' ;

    seq.insert( seq.end(), A( 10, "hello" ) ) ; // construct an anonymous object
                                                // copy (or move) the anonymous object into the container
                                                // destroy the anonymous object
    std::cout << "-------------\n" ;
    
    // when passing an object to container, copy object into container
    seq.emplace_back( a ) ;
    seq.emplace_back( 10, "hello" ) ; // construct the object in-place in the container
    seq.emplace( seq.end(), 10, "hello" ) ; // construct the object in-place in the container
    std::cout << "-------------\n" ;
}