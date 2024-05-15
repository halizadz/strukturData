#include <iostream>
#include <vector>
using namespace std;

// Implementasi queue menggunakan array
class ArrayQueue {
private:
    vector<char> queue;
    int front;
    int rear;
    int capacity;
public:
    ArrayQueue(int size) {
        queue.resize(size);
        front = -1;
        rear = -1;
        capacity = size;
    }
    void enqueue(char x) {
        if ((rear + 1) % capacity == front) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = x;
    }
    char dequeue() {
        if (front == -1) {
            return '\0';
        }
        char x = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return x;
    }
};

// Berfungsi untuk memeriksa apakah data dalam queue membentuk palindrom
bool isPalindrome(ArrayQueue &q, const vector<char> &data, int n) {
    for (int i = 0; i < n; i++) {
        if (q.dequeue() != data[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    cin.ignore(); // untuk mengabaikan karakter baris baru setelah masukan bilangan bulat

    vector<char> data(n);
    ArrayQueue q(n);

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

    cout << "\nProgram selesai." << endl;
    cout << "===========================================" << endl;
    cout << "Tugas Ini di Buat Oleh : " << endl;
    cout << "1. Haliza Adzikia Sukarno (2310631170087)" << endl << "2. Indira Ayu Anggraeni (2310631170021)" << endl << "3. Cindy Priaulia M.P (2310631170129)" << endl;
    cout << "==========================================" << endl;
    return 0;
}

