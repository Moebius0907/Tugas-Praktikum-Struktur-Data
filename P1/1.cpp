#include<iostream>
using namespace std;

void line () { //fungsi untuk mencetak garis horizontal
    for (int i = 0 ; i < 70; i++) {
        cout << "=" ;
    }
    cout << "\n";
}

void Identitas () { //fungsi untuk mencetak nama dan npm
    cout << "Program dibuat oleh :\n";
    cout << "Nama : Delia Nur Ilmi Salam\n";
    cout << "NPM  : 2310631170069";
}

int main (){ //fungsi utama
    line(); //memanggil fungsi line
    cout << "Program Data Nama dan Alamat Mahasiswa 2C - Informatika Pada Komputer\n"; 
    line(); //memanggil fungsi line
    int jumlahData; //deklarasi variabel jumlahData yang bertipe data integer
    string dataMahasiswa[26]; /*membuat array untuk menampung data mahasiswa dengan panjang 26 dan bertipe data 
                                string panjangnya 26 karena menyesuaikan jumlah mahasiswa di kekas 2C*/
    string* alamatData; //membuat variabel pointer bernama alamatData dan bertipe data string juga
    alamatData = &dataMahasiswa[0]; /*Mengatur alamatData untuk menunjuk ke alamat memori dari elemen pertama 
                                      dalam array dataMahasiswa*/
    while (true) { //membuat perulangan dimana statement akan terus dijalankan selama kondisi nya masih true
        cout << "Jumlah mahasiswa : "; //perintah untuk menginputkan jumlah mahasiswa yang akan disimpan pada array
        cin >> jumlahData; //input berupa variabel jumlahData yang bertipe data int
        if (jumlahData > 26) { /*pengecekan kondisi, dimana jika jumlahData yang diinput > 26, 
                    akan keluar statement menampilkan tulisan di bawah lalu kembali ke bagian input jumlah Data*/
                cout << "Jumlah Data yang ingin diinputkan melebihi kapasitas array.Masukkan input jumlah yang valid !.\n";
        } else { //jika jumlahData tidak melebihi 26, looping while akan berhenti karena ada statement break
            break;}
            }

    for (int i = 0; i < jumlahData ; i++) { //perulangan untuk menginput data sebanyak jumlahData
            cout << "Nama Mahasiswa ke-" << i + 1 << " : ";
            cin.ignore(); //digunakan untuk mengabaikan karakter tertentu dalam buffer input
            getline (cin, dataMahasiswa[i]);//setiap data yang diinputkan akan disimpan ke dalam array dataMahasiswa 
            }
    line();
    cout << "Nama Mahasiswa\t\tAlamat pada komputer" << "\n"; 
    line();
    for (int i = 0; i < jumlahData; i++){ //looping untuk menampilkan nama dan alamat pada komputer
        cout << "" << *alamatData << "\t\t\t" << alamatData << "\n";/*mencetak nilai yang ditunjuk oleh pointer 
                                                   alamatData dan alamat data itu sendiri (alamat memori) */
        alamatData++; //digunakan untuk memajukan pointer alamatData ke elemen berikutnya.
    }
    line();
    cout << "\n";
    Identitas();//memanggil fungsi identitas 
return 0;
}
