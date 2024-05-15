#include <iostream>
#include <vector>
using namespace std;

// Struktur node untuk implementasi linked list
struct Node {
    char data;
    Node* next;
};

// Implementasi queue menggunakan linked list
class LinkedListQueue {
private:
    Node* front;
    Node* rear;
public:
    LinkedListQueue() {
        front = NULL;
        rear = NULL;
    }
    void enqueue(char x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (front == NULL && rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    char dequeue() {
        if (front == NULL) {
            return '\0';
        }
        Node* temp = front;
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
        }
        char x = temp->data;
        delete(temp);
        return x;
    }
    void clear() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete(temp);
        }
        rear = NULL;
    }
};

// Berfungsi untuk memeriksa apakah data dalam queue membentuk palindrom
bool isPalindrome(LinkedListQueue &q, const vector<char> &data, int n) {
    for (int i = 0; i < n; i++) {
        if (q.dequeue() != data[n - i - 1]) {
            return false;
        }
    }
    return true;
}

// Berfungsi untuk memasukkan data dan memeriksa palindrom
void inputDataAndCheckPalindrome() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    cin.ignore(); // untuk mengabaikan karakter baris baru setelah masukan bilangan bulat

    vector<char> data(n);
    LinkedListQueue q;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data : ";
        cin >> data[i];
        q.enqueue(data[i]);
        cout << "Data berhasil ditambahkan" << endl;
    }

    if (isPalindrome(q, data, n)) {
        cout << "\nMerupakan Palindrome" << endl;
    } else {
        cout << "\nBukan merupakan palindrome" << endl;
    }

    q.clear(); // Kosongkan antrean untuk input berikutnya
}

int main() {
    inputDataAndCheckPalindrome();
    cout << "\nProgram selesai." << endl;
    cout << "===========================================" << endl;
    cout << "Tugas Ini di Buat Oleh : " << endl;
    cout << "1. Haliza Adzikia Sukarno (2310631170087)" << endl << "2. Indira Ayu Anggraeni (2310631170021)" << endl << "3. Cindy Priaulia M.P (2310631170129)" << endl;
    cout << "==========================================" << endl;
    return 0;
}
