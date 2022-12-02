#include "vec.hpp"
#include <iterator>
 
// using namespace std;

int main()
{
    // Create a vector containing integers
    // vector<int> v = {7, 5, 16, 8}; 
    vec<int> v;

    // int* toto = new int[8];

    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);
 

    // Print out the vector
    std::cout << "v = { ";
    for (auto n = std::begin(v); n != std::end(v); ++n)
        std::cout << *n << ", "; 
    std::cout << "}; \n";

    v.reverse();
    std::cout << "v = { ";
    for (auto n = std::begin(v); n != std::end(v); ++n)
        std::cout << *n << ", "; 
    std::cout << "}; \n";

    std::cout << v[1] << std::endl;
}