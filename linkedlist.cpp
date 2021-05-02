#include <iostream>

template <class T>
class Chain;

template <class T>
class ChainNode {
friend class Chain<T>;
private:
    T data;
};

int main()
{
    std::cout << "Hello, world!\n";
}
