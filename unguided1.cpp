#include <iostream>
using namespace std;

class Node {
public:
    string name;
    int age;
    Node* next;
    Node* prev;

    Node(string _name, int _age) {
        name = _name;
        age = _age;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    // Fungsi untuk menambahkan node di depan
    void insertAtFront(string name, int age) {
        Node* newNode = new Node(name, age);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Fungsi untuk menambahkan node di belakang
    void insertAtEnd(string name, int age) {
        Node* newNode = new Node(name, age);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Name: " << temp->name << ", Age: " << temp->age << endl;
            temp = temp->next;
        }
    }

    
    void deleteNode(string name) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == name) {
                if (temp == head) {
                    head = temp->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next != NULL) {
                        temp->next->prev = temp->prev;
                    }
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in the list." << endl;
    }

    
    void updateNode(string name, int age) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == name) {
                temp->age = age;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in the list." << endl;
    }

    
    void clearAll() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
    }
};

int main() {
    DoublyLinkedList list;
    int choice;
    string name;
    int age;
    do {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Add data" << endl;
        cout << "2. Update data" << endl;
        cout << "3. Delete data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                list.insertAtFront(name, age);
                break;
            case 2:
                cout << "Enter name to update: ";
                cin >> name;
                cout << "Enter new age: ";
                cin >> age;
                list.updateNode(name, age);
                break;
            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                list.deleteNode(name);
                break;
            case 4:
                list.clearAll();
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 6);
    return 0;
}
