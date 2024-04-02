#include <iostream>
#include <string> // Include <string> header for string usage

using namespace std;

class Node {
public:
    string name;
    int age;
    Node *next;
    
    Node(string n, int a) : name(n), age(a), next(nullptr) {} // Constructor to initialize name, age, and next pointer
};

class LinkedList {
public:
    Node *head;
    
    LinkedList() : head(nullptr) {} // Constructor to initialize head to nullptr
    
    ~LinkedList() { // Destructor to release dynamically allocated memory
        clearAll();
    }

    void insertAtFront(string name, int age) {
        Node *newNode = new Node(name, age);
        newNode->next = head;
        head = newNode;
    }
    
    void insertAtEnd(string name, int age) {
        Node *newNode = new Node(name, age);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(string name, int age, string keyName) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->name == keyName) {
                Node *newNode = new Node(name, age);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << keyName << " not found in the list." << endl;
    }
    
    void updateNode(string name, int age) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                temp->age = age;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in the list." << endl;
    }
    
    void deleteNode(string name) {
        Node *temp = head;
        Node *prev = nullptr;
        while (temp != nullptr) {
            if (temp->name == name) {
                if (prev == nullptr) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << name << " not found in the list." << endl;
    }
    
    void clearAll() {
        Node *temp = head;
        while (temp != nullptr) {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->name << ", Age: " << temp->age << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    int choice;
    string name, keyName;
    int age;
    do {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Add data at the front" << endl;
        cout << "2. Add data at the end" << endl;
        cout << "3. Insert data after a specific name" << endl;
        cout << "4. Update data" << endl;
        cout << "5. Delete data" << endl;
        cout << "6. Clear all data" << endl;
        cout << "7. Display data" << endl;
        cout << "8. Exit" << endl;
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
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                list.insertAtEnd(name, age);
                break;
            case 3:
                cout << "Enter name to insert after: ";
                cin >> keyName;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                list.insertAfter(name, age, keyName);
                break;
            case 4:
                cout << "Enter name to update: ";
                cin >> name;
                cout << "Enter new age: ";
                cin >> age;
                list.updateNode(name, age);
                break;
            case 5:
                cout << "Enter name to delete: ";
                cin >> name;
                list.deleteNode(name);
                break;
            case 6:
                list.clearAll();
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 8);

    return 0;
}
