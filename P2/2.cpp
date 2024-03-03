#include <iostream>
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

void rotateMatrix(int matrix[3][3]) {//fungsi untuk merotasi matriks sebesar 90 derajat yang memiliki parameter matrix 2D
    int rotatedMatrix[3][3];//deklarasi matriks untuk menyimpan hasil rotasi

    for(int i = 0; i < 3; i++){//digunakan untuk mengiterasi setiap baris di matrix awal
        for(int j = 0; j < 3; j++){//digunakan untuk mengiterasi setiap kolom di matrix awal
            rotatedMatrix[j][2 - i] = matrix[i][j];/*pemutaran matrix dilakukan dengan merubah
            Indeks baris dari matriks yang diputar (rotatedMatrix) diatur berdasarkan indeks kolom matriks asli (matrix) (2 - i).
            Indeks kolom dari matriks yang diputar (rotatedMatrix) diatur berdasarkan indeks baris matriks asli (matrix) (j).*/
        }
    }

    //output matriks yang telah diputar
    cout << "Matriks setelah diputar:" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    line();//memqnggil fungsi line
    cout << "\tProgram Rotasi Matrix Array\n";//pesan judul program
    line();
    int matrix[3][3];//deklarasi array matrix 2D persegi dengan nilai panjang 3

    // looping untuk menginput nilai matrix
    for(int i = 0; i < 3; i++){//digunakan untuk mengiterasi setiap baris pada matrix
        for(int j = 0; j < 3; j++){//digunakan untuk mengiterasi setiap kolom pada matrix
            cout << "Masukan nilai dari matriks [" << i <<"] [ " << j << "] :";//perintah untuk menginputkan elemen matrix dimulai dari indeks [0][0]
            cin >> matrix[i][j];//input akan disimpan ke dalam array matrix
        }
        cout << "\n";
    }

    //menampilkan matriks yang diinput tadi sebelum diputar
    cout << "Matriks sebelum diputar:" << "\n";
    for(int i = 0; i < 3; i++){//digunakan untuk mengiterasi setiap baris pada matrix 
        for(int j = 0; j < 3; j++){//digunakan untuk mengiterasi setiap kolom pada matrix
            cout << matrix[i][j] << " ";//menampilkan matrix yang sudah diinput tadi dimulai dari indeks ke-[0[0]
        }
        cout << "\n";
    }

    rotateMatrix(matrix);//memanggil fungsi rotatedMatrix untuk merotasi matrix sebesar 90 derajat
    line();
    identitas();
    line();

    return 0;
}