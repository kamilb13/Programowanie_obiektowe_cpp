#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    T* arr; // tablica przechowuj¹ca elementy stosu
    int capacity; // pojemnoœæ stosu
    int top; // indeks szczytowego elementu stosu

public:
    // konstruktor tworz¹cy pusty stos o zadanej pojemnoœci
    Stack(int size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    // destruktor zwalniaj¹cy pamiêæ zajmowan¹ przez tablicê
    ~Stack() {
        delete[] arr;
    }

    // metoda dodaj¹ca element na stos
    void push(T item) {
        if (top == capacity-1) {
            cout << "Stos jest pelny!" << endl;
            return;
        }
        top++;
        arr[top] = item;
    }

    // metoda usuwaj¹ca element ze stosu i zwracaj¹ca jego wartoœæ
    T pop() {
        if (top == -1) {
            cout << "Stos jest pusty!" << endl;
            return T();
        }
        T item = arr[top];
        top--;
        return item;
    }

    // metoda zwracaj¹ca wartoœæ szczytowego elementu stosu
    T peek() {
        if (top == -1) {
            cout << "Stos jest pusty!" << endl;
            return T();
        }
        return arr[top];
    }

    // metoda sprawdzaj¹ca, czy stos jest pusty
    bool isEmpty() {
        return (top == -1);
    }

    // metoda sprawdzaj¹ca, czy stos jest pe³ny
    bool isFull() {
        return (top == capacity-1);
    }
};

int main() {
    // Tworzenie stosu typu int o pojemnoœci 5
    Stack<int> stack1(5);

    // Dodawanie elementów na stos
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);

    // Usuwanie i wyœwietlanie elementów ze stosu
    cout << stack1.pop() << endl; // 50
    cout << stack1.pop() << endl; // 40
    cout << stack1.pop() << endl; // 30
    cout << stack1.pop() << endl; // 20
    cout << stack1.pop() << endl; // 10

    // Tworzenie stosu typu double o pojemnoœci 3
    Stack<double> stack2(3);

    // Dodawanie elementów na stos
    stack2.push(3.14);
    stack2.push(2.718);
    stack2.push(1.618);

    // Wyœwietlanie szczytowego elementu stosu
    cout << stack2.peek() << endl; // 1.618

    // Usuwanie i wyœwietlanie elementów ze stosu
    cout << stack2.pop() << endl; // 1.618
    cout << stack2.pop() << endl; // 2.718
    cout << stack2.pop() << endl; // 3.14
}
