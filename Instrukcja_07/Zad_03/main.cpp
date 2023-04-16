#include <iostream>

using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head; // wskaŸnik na pocz¹tek listy

public:
    // konstruktor tworz¹cy pust¹ listê
    List() {
        head = nullptr;
    }

    // destruktor usuwaj¹cy wszystkie elementy listy
    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // metoda dodaj¹ca element na koniec listy
    void add(T item) {
        Node* newNode = new Node();
        newNode->data = item;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // metoda usuwaj¹ca pierwszy element o wartoœci podanej jako argument
    void remove(T item) {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != item) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Nie znaleziono elementu do usuniecia!" << endl;
            return;
        }
        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
    }

    // metoda zwracaj¹ca liczbê elementów w liœcie
    int count() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // metoda wyœwietlaj¹ca wszystkie elementy listy
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Tworzenie listy typu int
    List<int> list1;

    // Dodawanie elementów do listy
    list1.add(10);
    list1.add(20);
    list1.add(30);

    // Wyœwietlanie elementów listy
    list1.print(); // 10 20 30

    // Usuwanie elementów z listy
    list1.remove(20);
    list1.remove(40);

    // Wyœwietlanie elementów listy
    list1.print(); // 10 30

    // Tworzenie listy typu double
    List<double> list2;

    // Dodawanie elementów do listy
    list2.add(3.14);
    list2.add(2.718);
    list2.add(1.618);

    // Wyœwietlanie elementów listy
    list2.print(); // 3.14 2.718 1.618

    // Usuwanie elementów z listy
    list2.remove(2.718);
    list2.remove(4.56);

    // Wyœwietlanie elementów listy
    list2.print(); // 3.14 1.618

    // Tworzenie listy typu string
    List<string> list3;

    // Dodawanie elementów do listy
    list3.add("ala");
    list3.add("ma");
    list3.add("kota");

    // Wyœwietlanie elementów listy
    list3.print(); // ala ma kota

    // Usuwanie elementów z listy
    list3.remove("ma");
    list3.remove("pies");

    // Wyœwietlanie elementów listy
    list3.print(); // ala kota

    return 0;

}
