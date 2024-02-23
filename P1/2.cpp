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

int fungsiKompres(char karakter[], int panjang) {/*fungsi untuk melakukan kompresi mempunyai parameter 
                                        berupa array karakter dan panjang serta mengembalikan tipe data int*/
    int i = 0;/*Inisialisasi variabel i sebagai indeks untuk iterasi melalui array karakter*/
    int j = 0;/*Inisialisasi variabel j sebagai indeks untuk menyimpan hasil dari kompres*/
    while( i < panjang) { /*looping jika nilai var i < panjang array awal*/
        karakter[j++] = karakter[i];/*Menyalin karakter pertama dari setiap kelompok karakter yang sama ke dalam 
                                    array karakter hasil kompresi,dan meningkatkan nilai j*/
        int jumlahChar = 1; /*var untuk menampung jumlah karakter yang sama*/
        while (i < panjang-1 && karakter[i] == karakter[i+1]) {
            /*Perulangan dengan kondisi i < panjang array awal - 1 dan array [i] == array [i+1]*/
            jumlahChar++;/*increment jumlahChar jika kondisi di while terpenuhi atau jumlah char yang sama bertambah 1*/
            i++;
        }
        if (jumlahChar > 1) {
            string jumlahCharString = to_string(jumlahChar);//mengubah var jumlahChar menjadi string
            for (int k = 0; k < jumlahCharString.length(); k++) {
                karakter[j++] = jumlahCharString[k];/*string hasil kompresi masuk ke dalam array chars hasil kompresi*/
            }
        }
        i++;
    }
    return j;/*mengembalikan nilai j yang merupakan panjang dari array karakter hasil kompresi.*/
}

int main() {
    line();/*memanggil fungsi line*/
    cout << "Program Input Array berupa Char dan Kompresi Char yang sama\n";
    line();
    cout << "Masukkan jumlah char:";/*perintah untuk memasukkan jumlah char*/
    int panjangArray;/*deklarasi var panjangArray yang bertipe data int*/
    cin >> panjangArray;/*input berupa panjangArray*/

    char chars[panjangArray];/*deklarasi array chars yang bertipe data char dengfan panjang panjangArray*/
    cout << "\nInput array awal : ";/*perintah untuk menginput elemen-elemen array*/
    for (int j = 0; j < panjangArray ;j++){/*looping untuk menyimpan input elemen-elemen array*/
        cin>> chars[j];/*input akan disimpan di array chars dimulai dari indeks 0*/
    }

    int panjang = panjangArray;/*deklarasi dan inisialisasi var panjang denfan nilai berupa panjangArray*/
    /*Memanggil fungsi fungsiKompres untuk melakukan kompresi terhadap array chars*/
    int panjangSetelahDikompresi = fungsiKompres(chars, panjang);
    cout <<  "Array setelah dikompresi : [";/*menampilkan array hasil kompresi*/
    for (int i = 0; i <panjangSetelahDikompresi; i++) {/*looping untuk menampilkan array hasil kompressi*/
        cout << "'" << chars[i] << "'";
        if (i < panjangSetelahDikompresi-1) {
            /*jika i kurang dari panjang array - 1, menambahkan koma dan spasi setelah karakter*/
            cout << ", ";
        }
    }
    cout << "]" << "\n\n";

    Identitas();/*memanggil fungsi identitas*/
    return 0;
}
