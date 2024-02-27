#include<iostream>

using namespace std;

void line () {/*fungsi untuk mencetak garis horizontal*/
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

void kompresiChar () {/*fungsi untuk kompresi array char*/
    line();/*memanggil fungsi line*/
    cout << "Program Input Array berupa Char dan Kompresi Char yang sama\n";
    line();
    const int maxChar = 26;/*deklarasi dan inisialisasi variabel konstanta untuk menampung jumlah maksimal huruf alfabet*/
    char alfabet[maxChar] = {'\0'};/*membuat array karakter dengan ukuran maks 26 dan diinisalisasi dengan null character*/

    cout << "Masukkan char array awal :";/*perintah untuk menginputkan array char awal*/
    string masukan;/*membuat variabel masukan dengan tipe data string untuk menyimpan input pengguna*/
    getline(cin, masukan);/*menggunakan getline agar program bisa membaca satu baris penuh kode masukan */

    for (char c : masukan) {/*looping untuk menghitung jumlah kemunculan char dalam array awal*/
        if ('a' <= c && c <= 'z') {/*pengkondisian jika karakter dalam rentang huruf kecil(a-z)*/
            alfabet[c - 'a']++;/*menghitung jumlah kemunculan karakter*/
        }else if('A' <= c && c <= 'Z') {/*pengkondisian jika karakter dalam rentang huruf besar(A-Z)*/
            alfabet[c- 'A']++;/*menghitung jumlah kemunculan karakter*/
        }
    }
    cout << "Array setelah dikompresi:[";
    /*looping untuk menampilkan array kompresi dimana jika huruf lebih satu akan ditampilkan diikuti dengan jumlah kemunculannya*/
    for(int i = 0; i <maxChar ; i++) {
        if(alfabet[i] > 0) {/*pengkondisian jika jumlah kemunculan char lebih dari 0*/
            char karakter = 'a' + i;/*mengonversi indeks array ke char*/
            cout << "'" <<karakter << "'," << "'" << static_cast<int>(alfabet[i]) << "',";
            /*output berupa jumlah huruf sama yang dikonversi menjadi nilai int*/
        }
    }
    cout << "]";
    cout << "\n\n";
}

int main() {
    kompresiChar();/*memanggil fungsi kompresiChar*/
    Identitas();/*memanggil fungsi identitas*/
    return 0;
}
