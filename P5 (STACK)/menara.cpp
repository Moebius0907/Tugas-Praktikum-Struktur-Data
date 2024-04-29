#include<iostream>//library yang digunakan untuk mengakses perintah input dan output

using namespace std;

void line () {// Fungsi untuk mencetak garis horizontal sepanjang 70 
    for (int i = 0; i <= 70; i++){ // Melakukan loop dari 0 hingga 70 untuk mencetak karakter '='
        cout << "=";
    }
    cout << "\n";
}

void identitas () {// Fungsi untuk menampilkan identitas pembuat program
    cout << "Program dibuat oleh :\n";
    cout << "Nama : Delia Nur Ilmi Salam\n";
    cout << "NPM  : 2310631170069\n";
}

//ukuran maksimum dari Tower dalam menara
int maxSize = 3;

//Deklarasi dan inisialisasi array masing-masing tower
int towerA[3] = {60, 40, 20};
int towerB[3] , towerC[3];

// Fungsi untuk menghitung jumlah elemen di dalam sebuah tower
int countSize (int stack[]) {// Fungsi mempunyai parameter array stack 
    int size = 0;//Deklarasi dan inisialisasi variabel yang digunakan untuk menyimpan jumlah elemen dalam Tower
    //melakukan loop sampai akhir stack atau sampai menemukan ruang kosong
    while(stack[size] != 0 && size < maxSize) {
        size++; //Pada setiap iterasi dari loop, nilai size akan ditambahkan 1
    }
    return size;//Di akhir, fungsi Mengembalikan nilai size 
}

// Fungsi untuk menambahkan elemen ke sebuah Tower di Menara
void pushTo(int stack[], int number) { //Fungsi mempunyai 2 buah parameter yaitu stack dan 
//variabel number yang merupakan nilai elemen yang akan ditambahkan ke menara.
    int amount = countSize(stack); //deklarasi dan inisialisasi variabel amount yang digunakan untuk menyimpan jumlah elemen 
    //dalam menara sebelum penambahan mengecek apakah Tower sudah penuh
    if (amount >= maxSize) { // Pengkondisian jika stack tower sudah penuh
        cout << "Stack sudah penuh\n";
    } else { //Jika Tower masih kosong
        //Menambahkan nilai ke bagian atas Tower
        stack[amount] = number;//menyimpan number ke dalam stack pada indeks amount
    }
}

//Fungsi untuk menghapus satu nilai yang tersimpan di sebuah tower
void popElement (int stack []) {
    int amount = countSize(stack);
    //Mengecek apakah tower sudah kosong
    if (amount == 0) {
        cout << "Kosong\n";
    } else {
        //Menghapus nilai dari tower
        stack[amount-1] = 0;
    }
}

//Fungsi untuk menampilkan nilai nilai dalam sebuah tower 
void displayStack(int stack[]) {
    //looping untuk menampilkan menampilkan nilai yang tersimpan dalam stack sebuah tower
    for (int i = 0; i < maxSize; i++) {
        //pengkondisian jika stack tidak kosong
        if (stack[i] != 0) {
            cout << stack[i] << " -> ";
        }
    }
    cout << "\n";
}

//Fungsi untuk menampilkan semua tower dalam menara
void displayAll() {
    cout << "Tower A : ";
    displayStack(towerA);
    cout << "Tower B : ";
    displayStack(towerB);
    cout << "Tower C : ";
    displayStack(towerC);
    cout << "\n";
}

int main() {
    line();
    cout << " \t\t\t Menara Hanoi\n";
    line (); 

    //Menampilkan keadaan awal dari menara 
    cout << " Keadaan Awal \n";
    line();
    displayAll();//Memanggil fungsi displayAll untuk menampilkan semua stack

    //Memindahkan nilai teratas dari tower A ke menara awal tower B
    line();
    cout << " Step ke-1 : Memindahkan Nilai A ke B\n";
    line();
    cout << " \t\t\t Menara Hanoi\n";
    line (); 
    pushTo(towerB, towerA[countSize(towerA)-1]);//Memanggil fungsi pushTo yang akan memindahkan nilai, berisi argumen tower tujuan 
    //dan nilai teratas dari menara A yang akan dipindahkan. 
    popElement(towerA);//Memanggil fungsi popElement untuk menghapus nilai teratas dari tower A

    //Menampilkan keadaan menaara 
    displayAll();

    //Memindahkan nilai terbawah dari tower B ke bagian teratas tower A
    line();
    cout << " Step ke-2 : Memindahkan Nilai B ke A\n";
    line();
    cout << " \t\t\t Menara Hanoi\n";
    line (); 
    pushTo(towerA, towerB[countSize(towerB)-1]);//Memanggil fungsi pushTo yang akan memindahkan nilai, berisi argumen tower tujuan 
    //dan nilai terbawah dari menara B yang akan dipindahkan. 
    popElement(towerB);//Memanggil fungsi popElement untuk menghapus nilai yang tersimpan di tower B
    
    //Menampilkan keadaan menara 
    displayAll();


    //Memindahkan nilai teratas dari menara A ke menara C
    line();
    cout << " Step ke-3 : Memindahkan Nilai A ke C\n";
    line();
    cout << " \t\t\t Menara Hanoi\n";
    line (); 
    pushTo(towerC, towerA[countSize(towerA)-1]);//Memanggil fungsi pushTo yang akan memindahkan nilai, berisi argumen tower tujuan 
    //dan nilai teratas dari menara A yang akan dipindahkan. 
    popElement(towerA);//Memanggil fungsi popElement untuk menghapus nilai teratas dari tower A

    //Menampilkan keadaan akhir dari menara
    displayAll();

    line();
    identitas();//Memanggil fungsi identitas untuk menampilkan identitas pembuat
    line();
    return 0;
}