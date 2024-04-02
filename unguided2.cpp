#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    int harga;
    Node *prev;
    Node *next;
};

class DoubleLinkedList {
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Functions for adding, deleting, updating, and displaying data...

};

int main() {
    DoubleLinkedList dll;
    int choice;
    string nama;
    int harga;
    int index;
    
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data pada Urutan Tertentu" << endl;
        cout << "5. Hapus Data pada Urutan Tertentu" << endl;
        cout << "6. Hapus Semua Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Code for adding data...
                break;
            case 2:
                // Code for deleting data...
                break;
            case 3:
                // Code for updating data...
                break;
            case 4:
                // Code for adding data at a specific index...
                break;
            case 5:
                // Code for deleting data at a specific index...
                break;
            case 6:
                // Code for clearing all data...
                break;
            case 7:
                // Code for displaying data...
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
        cout << endl;

    } while (choice != 8);

    return 0;
}
