#include <iostream>

struct Node {
    int data;
    Node* next;
};

void createCircularList(Node*& head, Node*& tail, int values[], int size) {
    head = nullptr; // ����������� ����������� ����� �� nullptr

    for (int i = 0; i < size; i++) { // ����������� �� ��� ��������� ������
        Node* newNode = new Node(); // ��������� ������ �����
        newNode->data = values[i]; // ��������� �������� ����� � ������
        newNode->next = nullptr; // ����������� ��������� �� ��������� ����� �� nullptr

        if (head == nullptr) { // ���� ������ �������
            head = newNode; // ������������ ����������� �� �������� �����
            tail = newNode;
        }
        else {
            tail->next = newNode; // ��������� ������ ����� ���� �������� �����
            tail = newNode; // ��������� �������� �����
        }
    }

    if (head != nullptr) { // ���� ������ �� �������
        tail->next = head; // ������� ������� ������� ���������� �� ������ �������
    }
}

int countPositiveElements(Node* head) {
    int count = 0;
    if (head == nullptr) // �������� �� ������ ������
        return count;

    Node* current = head;
    do {
        if (current->data > 0) // ���� �������� �������� ������
            count++; // �������� ��������
        current = current->next;
    } while (current != head); // �����������, ���� �� ����������� �� �������

    return count;
}

void displayCircularList(Node* head) {
    if (head == nullptr) // �������� �� ������ ������
        return;

    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head); // �����������, ���� �� ����������� �� �������
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
