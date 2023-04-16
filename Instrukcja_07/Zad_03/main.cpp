#include <iostream>

using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head; // wska�nik na pocz�tek listy

public:
    // konstruktor tworz�cy pust� list�
    List() {
        head = nullptr;
    }

    // destruktor usuwaj�cy wszystkie elementy listy
    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // metoda dodaj�ca element na koniec listy
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

    // metoda usuwaj�ca pierwszy element o warto�ci podanej jako argument
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

    // metoda zwracaj�ca liczb� element�w w li�cie
    int count() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // metoda wy�wietlaj�ca wszystkie elementy listy
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

    // Dodawanie element�w do listy
    list1.add(10);
    list1.add(20);
    list1.add(30);

    // Wy�wietlanie element�w listy
    list1.print(); // 10 20 30

    // Usuwanie element�w z listy
    list1.remove(20);
    list1.remove(40);

    // Wy�wietlanie element�w listy
    list1.print(); // 10 30

    // Tworzenie listy typu double
    List<double> list2;

    // Dodawanie element�w do listy
    list2.add(3.14);
    list2.add(2.718);
    list2.add(1.618);

    // Wy�wietlanie element�w listy
    list2.print(); // 3.14 2.718 1.618

    // Usuwanie element�w z listy
    list2.remove(2.718);
    list2.remove(4.56);

    // Wy�wietlanie element�w listy
    list2.print(); // 3.14 1.618

    // Tworzenie listy typu string
    List<string> list3;

    // Dodawanie element�w do listy
    list3.add("ala");
    list3.add("ma");
    list3.add("kota");

    // Wy�wietlanie element�w listy
    list3.print(); // ala ma kota

    // Usuwanie element�w z listy
    list3.remove("ma");
    list3.remove("pies");

    // Wy�wietlanie element�w listy
    list3.print(); // ala kota

    return 0;

}
