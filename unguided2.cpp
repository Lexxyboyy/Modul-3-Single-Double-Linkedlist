#include <iostream>
using namespace std;


class Node {
public:
    string productName;
    int price;
    Node* next;
    Node* prev;

    Node(string _productName, int _price) {
        productName = _productName;
        price = _price;
        next = NULL;
        prev = NULL;
    }
};


class DoubleLinkedList {
public:
    Node* head;

    DoubleLinkedList() {
        head = NULL;
    }

    
    void insertFront(string productName, int price) {
        Node* newNode = new Node(productName, price);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    
    void insertEnd(string productName, int price) {
        Node* newNode = new Node(productName, price);
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

    
    void insertAfter(string productName, int price, string keyProductName) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->productName == keyProductName) {
                Node* newNode = new Node(productName, price);
                newNode->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                newNode->prev = temp;
                return;
            }
            temp = temp->next;
        }
        cout << keyProductName << " not found in the list." << endl;
    }

   
    void deleteNode(string productName) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->productName == productName) {
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
        cout << productName << " not found in the list." << endl;
    }

   
    void updateNode(string productName, int price) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->productName == productName) {
                temp->price = price;
                return;
            }
            temp = temp->next;
        }
        cout << productName << " not found in the list." << endl;
    }

    
    void display() {
        Node* temp = head;
        cout << "Nama Produk\tHarga" << endl;
        while (temp != NULL) {
            cout << temp->productName << "\t\t" << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoubleLinkedList productList;

    // Menambahkan data awal
    productList.insertEnd("Originote", 60000);
    productList.insertEnd("Somethinc", 150000);
    productList.insertEnd("Skintific", 100000);
    productList.insertEnd("Wardah", 50000);
    productList.insertEnd("Hanasui", 30000);

    int choice;
    string productName, keyProductName;
    int price;
    do {
        cout << endl;
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Masukkan nama produk: ";
                cin >> productName;
                cout << "Masukkan harga: ";
                cin >> price;
                productList.insertEnd(productName, price);
                break;
            case 2:
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> productName;
                productList.deleteNode(productName);
                break;
            case 3:
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> productName;
                cout << "Masukkan harga baru: ";
                cin >> price;
                productList.updateNode(productName, price);
                break;
            case 4:
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> productName;
                cout << "Masukkan harga: ";
                cin >> price;
                cout << "Masukkan nama produk setelahnya: ";
                cin >> keyProductName;
                productList.insertAfter(productName, price, keyProductName);
                break;
            case 5:
                // Tidak diimplementasikan sesuai permintaan
                cout << "Fitur belum diimplementasikan." << endl;
                break;
            case 6:
                productList.display();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 8);

    return 0;
}
