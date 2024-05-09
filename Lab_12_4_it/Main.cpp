#include <iostream>

struct Node {
    int data;
    Node* next;
};

void createCircularList(Node*& head, Node*& tail, int values[], int size) {
    head = nullptr; // Ініціалізація початкового вузла як nullptr

    for (int i = 0; i < size; i++) { // Проходження по усім елементам масиву
        Node* newNode = new Node(); // Створення нового вузла
        newNode->data = values[i]; // Присвоєння значення вузлу з масиву
        newNode->next = nullptr; // Ініціалізація вказівника на наступний вузол як nullptr

        if (head == nullptr) { // Якщо список порожній
            head = newNode; // Встановлення початкового та кінцевого вузла
            tail = newNode;
        }
        else {
            tail->next = newNode; // Додавання нового вузла після кінцевого вузла
            tail = newNode; // Оновлення кінцевого вузла
        }
    }

    if (head != nullptr) { // Якщо список не порожній
        tail->next = head; // Зробити останній елемент посиланням на перший елемент
    }
}

int countPositiveElements(Node* head) {
    int count = 0;
    if (head == nullptr) // Перевірка на пустий список
        return count;

    Node* current = head;
    do {
        if (current->data > 0) // Якщо значення елемента додатнє
            count++; // Збільшуємо лічильник
        current = current->next;
    } while (current != head); // Повторювати, поки не повернемося до початку

    return count;
}

void displayCircularList(Node* head) {
    if (head == nullptr) // Перевірка на пустий список
        return;

    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head); // Повторювати, поки не повернемося до початку
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int values[] = { 1, -2, 3, -4, 5, };
    int size = sizeof(values) / sizeof(values[0]);

    createCircularList(head, tail, values, size);
    std::cout << "Original List: ";
    displayCircularList(head);
    std::cout << std::endl;

    int count = countPositiveElements(head);
    std::cout << "Number of positive elements: " << count << std::endl;

    return 0;
}
