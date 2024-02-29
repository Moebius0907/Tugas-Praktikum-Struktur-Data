#include<iostream>
using namespace std;

void line () { //fungsi untuk mencetak garis horizontal
    for (int i = 0 ; i < 50; i++) {
        cout << "=" ;
    }
    cout << "\n";
}

void identitas() {//fungsi untuk mencetak nama dan npm
    cout << "Program dibuat oleh :\n";
    cout << "Nama : Delia Nur Ilmi Salam\n";
    cout << "NPM  : 2310631170069\n";
}

int main() {
    line();
    cout << "\tProgram Perkalian Matrix\n";
    line();
    //perkalian matrix 
    int matrixA[2][2];//deklarasi matrixA untuk menampung elemen-elemen matriks A
    int matrixB[2][2];//deklarasi matrixB untuk menampung elemen-elemen matriks B
    int matrixC[2][2];//deklarasi matrixC untuk menampung hasil perkalian matriks A dan B


    for(int i=0; i <2 ; i++){
        for (int j =0; j < 2; j++) {//looping untuk menginput setiap elemen ke dalam kolom matriks A dimulai dari indeks [0]
            cout << "Masukkan nilai dari matrix A [" << i << "][" << j << "] :";//perintah untuk memasukan nilai dari matrix A
            cin >> matrixA[i][j];//setiap elemen akan diinput kan ke dalam matrix A dimulai dari [0][0] sampai [1][1]
        }
    }

    cout << "Matrix A : \n";//pesan untuk menampilkan matrixA
    for(int i=0; i <2 ; i++){//looping untuk menampilkan baris matrixA dimulai dari indeks [0]
        for (int j =0; j < 2; j++) {//looping untuk menampilkan kolom matrixA dimulai dari indeks [0]
            cout << matrixA[i][j] << " ";
            
        }
        cout << "\n";
    }
    cout << "\n";

    for(int i=0; i <2 ; i++){//looping untuk menginput setiap elemen ke dalam baris matriks B dimulai dari indeks [0]
        for (int j =0; j < 2; j++) {//looping untuk menginput setiap elemen ke dalam kolom matriks B dimulai dari indeks [0]
            cout << "Masukkan nilai dari matrix B [" << i << "][" << j << "] :";
            cin >> matrixB[i][j];//setiap elemen akan diinput kan ke dalam matrix B dimulai dari [0][0] sampai [1][1]
        }
    }
    cout << "Matrix B : \n";//pesan untuk menampilkan matrixB
    for(int i=0; i <2 ; i++){//looping untuk menampilkan matrixB
        for (int j =0; j < 2; j++) {
            cout << matrixB[i][j] <<" "; 
        }
        cout << "\n";
    }
    cout << "\n";

    // Melakukan perkalian matriks A dan B
    for(int i = 0; i < 2; i++) {//looping yang digunakan untuk mengiterasi setiap baris matriks hasil
        for(int j = 0; j < 2; j++) {//looping yang digunakan untuk mengiterasi setiap kolom matriks hasil
            matrixC[i][j] = 0;//deklarasi dan inisialisasi elemen matriksC dengan nilai 0
            for(int k = 0; k < 2; k++) {//looping yang digunakan untuk mengalikan elemen matriXsA dan matriB lalu menjumlahkannya
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];//menyimpan hasil perkalian matriksA dengan matriksB ke dalam matrixC
            }
        }
    }

    // Menampilkan hasil perkalian matriks C
    cout << "Hasil perkalian matriks A dan B (matriks C):\n";
    for(int i = 0; i < 2; i++) {//Looping untuk mengiterasi baris matrixC dimulai dari indeks [0]
        for(int j = 0; j < 2; j++) {//Looping untuk mengiterasi kolom matrixC dimulai dari indeks [0]
            cout << matrixC[i][j] << " ";//pesan untuk menampilkan matrixC
        }
        cout << "\n";
    }
    cout << "\n";
    line();
    identitas();//memanggil fungsi identitas untuk menampilkan nama dan npm
    line();

    return 0;
}