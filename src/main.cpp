#include <iostream>
#include <stdexcept>

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

        // Contructor
        LinkedList() {
            Head = NULL;
        }

        // Linked list access operation at position i
        T operator [](int i) {
            if (i < 0) {
                throw std::invalid_argument("Negative indicie passed. ");
            }

            int j = 0;
            Node<T> *Current = Head;
            while (j < i) {
                if (Current->Tail == NULL) {
                    throw std::invalid_argument("Index out of bounds");
                }

                Current = Current->Tail;
                j++;

            }

            return Current->GetValue();
        }

        // Inserts elements at the end of the list
        void insertAtTail(T Item) {
            Node<T> *temp = new Node<T>;
            temp->Head = Item;
            Node<T> *Current = Head;

            if (Current == NULL) {
                Head = temp;
            } else {
                while (Current->Tail != NULL) {
                    Current = Current->Tail;
                }
                Current->Tail = temp;
            }
            temp->Tail = NULL;
        }

        // Returns the size of the linked list
        size_t size() {
            size_t count = 0;
            Node<T> *Current = Head;
            while (Current != NULL) {
                count += 1;
                Current = Current->Tail;
            }
            return count;
        }

        // Displays the contents of the list
        void displayList() {
            if (Head != NULL) {
                Node<T> *Current = Head;
                while (Current != NULL) {
                    std::cout << "| " << Current->GetValue() << " \t| " << Current->Tail << " |\n";
                    Current = Current->Tail;
                }
            } else {
                std::cout << "The list is empty\n";
            }
        }

        // Deconstructor
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
    for (int i = 0; i < 20; i++) {
        t.insertAtTail(i);
    }
    t.insertAtTail(77);
    t.displayList();

    std::cout << t[20] << std::endl;
    return 1;
}