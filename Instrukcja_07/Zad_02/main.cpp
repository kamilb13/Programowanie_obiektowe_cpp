#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    T* arr; // tablica przechowuj�ca elementy stosu
    int capacity; // pojemno�� stosu
    int top; // indeks szczytowego elementu stosu

public:
    // konstruktor tworz�cy pusty stos o zadanej pojemno�ci
    Stack(int size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    // destruktor zwalniaj�cy pami�� zajmowan� przez tablic�
    ~Stack() {
        delete[] arr;
    }

    // metoda dodaj�ca element na stos
    void push(T item) {
        if (top == capacity-1) {
            cout << "Stos jest pelny!" << endl;
            return;
        }
        top++;
        arr[top] = item;
    }

    // metoda usuwaj�ca element ze stosu i zwracaj�ca jego warto��
    T pop() {
        if (top == -1) {
            cout << "Stos jest pusty!" << endl;
            return T();
        }
        T item = arr[top];
        top--;
        return item;
    }

    // metoda zwracaj�ca warto�� szczytowego elementu stosu
    T peek() {
        if (top == -1) {
            cout << "Stos jest pusty!" << endl;
            return T();
        }
        return arr[top];
    }

    // metoda sprawdzaj�ca, czy stos jest pusty
    bool isEmpty() {
        return (top == -1);
    }

    // metoda sprawdzaj�ca, czy stos jest pe�ny
    bool isFull() {
        return (top == capacity-1);
    }
};

int main() {
    // Tworzenie stosu typu int o pojemno�ci 5
    Stack<int> stack1(5);

    // Dodawanie element�w na stos
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);

    // Usuwanie i wy�wietlanie element�w ze stosu
    cout << stack1.pop() << endl; // 50
    cout << stack1.pop() << endl; // 40
    cout << stack1.pop() << endl; // 30
    cout << stack1.pop() << endl; // 20
    cout << stack1.pop() << endl; // 10

    // Tworzenie stosu typu double o pojemno�ci 3
    Stack<double> stack2(3);

    // Dodawanie element�w na stos
    stack2.push(3.14);
    stack2.push(2.718);
    stack2.push(1.618);

    // Wy�wietlanie szczytowego elementu stosu
    cout << stack2.peek() << endl; // 1.618

    // Usuwanie i wy�wietlanie element�w ze stosu
    cout << stack2.pop() << endl; // 1.618
    cout << stack2.pop() << endl; // 2.718
    cout << stack2.pop() << endl; // 3.14
}
