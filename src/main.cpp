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

        size_t size() {
            size_t count = 0;
            Node<T> *Current = Head;
            while (Current != NULL) {
                count += 1;
                Current = Current->Tail;
            }
            return count;
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
    LinkedList<int> t = {};
    std::cout << t.size() << std::endl;
    std::cout << "Hello World\n";
    return 1;
}