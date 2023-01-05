#include <iostream>

template <class T>
struct Node {
    T Head;
    Node<T> *Tail;

    T GetValue() {
        return Head;
    }
};

int main() {
    std::cout << "Hello World\n";
    return 1;
}