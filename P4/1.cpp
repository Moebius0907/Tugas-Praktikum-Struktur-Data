#include <iostream>
using namespace std;

void line () { //fungsi untuk mencetak garis horizontal
    for (int i = 0 ; i < 65; i++) {
        cout << "=" ;
    }
    cout << "\n";
}

void identitas() {//fungsi untuk mencetak nama dan npm
    cout << "Program dibuat oleh :\n";
    cout << "Nama : Delia Nur Ilmi Salam\n";
    cout << "NPM  : 2310631170069\n";
}

//membuat struct node
struct Node {
    int data;
    Node* next;
};

int main() {
    line ();
    cout << "|\tProgram Membalikkan Data Menggunakan Linked List\t|\n";// Judul Program
    line();

    Node* head = NULL;//inisialisasi node head dengan null

    int n;//deklarasi variabel n yang bertipe data int untuk menyimpan input pengguna
    cout << "Masukkan jumlah elemen : ";//perintah untuk memasukkan jumlah elemen
    cin >> n;//input disimpan di variabel n

    cout << "Masukkan " << n << " elemen :" << "\n";//perintah untuk memasukkan nilai sebanyak n elemen
    for (int i = 0; i < n; ++i) {//looping untuk menyimpan input ke variabel data 
        int data;
        cin >> data;//input disimpan ke dalam variabel data 

        // Membuat node baru untuk elemen yang diinput
        Node* newNode = new Node();//membuat node baru
        newNode->data = data;//mengisi data ke node baru
        newNode->next = NULL;//mengatur pointer node baru menjadi NULL

        if (head == NULL) {//jika linked list masih kosong
            head = newNode;//head akan diisi dengan newNode
        } else {//Jika linked list tidak kosong
            Node* temp = head;//membuat variabel temp yang bertipe data *Node 
                            //digunakan agar kita dapat bergerak melalui linked list, mulai dari head hingga last
                            //tanpa mengubah alamat head (transversal linked list)
            while (temp->next != NULL) {//perulangan untuk mencari node terakhir yang nilainya !=NULL
                temp = temp->next;//agar temp menunjuk ke node next
            }
            temp->next = newNode;//menambahkan newMode setelah node terakhir
        }
    }

    // Menampilkan linked list sebelum dibalik
    cout << "Linked list sebelum dibalik: ";
    Node* temp = head; // Mengatur variabel temp untuk traversal linked list diinisialisasi dengan head
    while (temp != NULL) { // Melakukan traversal dan menampilkan nilai data setiap node selama node temp tidak bernilai NULL
        cout << temp->data << " ";// Menampilkan setiap nilai data
        temp = temp->next;//memperbarui temp untuk menunjuk ke node berikutnya (mirip dengan iterasi)
    }
    cout << "\n";

    // Memutar linked list
    Node* prev = NULL;//deklarasi variabel pointer prev yang menyimpan alamat node sebelumnya, diinisialisasi dengan NULL
    Node* current = head;//deklarasi variabel pointer current yang menunjuk ke node saat ini yaitu head
    Node* next = NULL;//deklarasu variabel pointer next yang menyimpan alamat node berikutnya, diinisialisasi dengan NULL

    while (current != NULL) { // looping untuk membalikkan linked list
        next = current->next;//menyimpan alamat node berikutnya dalam variabel next
        current->next = prev;//mengubah pointer next node menjadi node sebelumnya
        prev = current;//memperbarui prev dengan current yang telah diperbarui isinya dengan node berikutnya
        current = next;//memperbarui variabel current untuk menunjuk ke next,yang menyimpan alamat node berikutnya sebelum pembalikan.
    }

    head = prev;// head menjadi node terakhir sebelum pembalikan

    // Menampilkan linked list setelah dibalik, caranya sama seperti saat menampilkan linked list yang belum dibalik
    cout << "Linked list setelah dibalik: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    line();
    identitas();// Memanggil fungsi identitas untuk menampilkan nama dan NPM
    line();
 
    return 0;
}
