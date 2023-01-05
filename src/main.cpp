#include <iostream>


// Node structure for the linked list
// Contains a getter for the value it holds
template <class T>
struct Node {
    T Head;
    Node<T> *Tail;

    T GetValue() {
        return Head;
    }
};

template <class T>
class LinkedList {
    public:
        LinkedList() {
            Head = NULL;
        }

        ~LinkedList() {
            if (Head != NULL) {
                Node<T> *Current = Head;

                while (Current != NULL) {
                    Node<T> *temp = Current;
                    Current = Current->Tail;
                    delete temp;
                }
            }
        }

    private:
        Node<T> *Head;
};

int main() {
    std::cout << "Hello World\n";
    return 1;
}