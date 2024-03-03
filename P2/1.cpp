#include <iostream>
#include<iomanip>
using namespace std;

const int MIN_TANGGAL = 5; // Minimal jumlah hari yang bisa diinput 
const int MAX_NAMA_BARANG = 50;// Minimal nama barang yang bisa diinput

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


struct DataBarang {//membuat struct untuk DataBarang yang terdiri dari nama,jumlah,tanggal dan kode
    string nama;
    int jumlah;
    int tanggal;
    int kode;
};


int main(){// fungsi utama
    line();// Memanggil fungsi garis
    cout << "\t\tProgram Cari Data Barang\n";// Judul program
    line();

    int jumlahData;//deklarasi variabel jumlahData untuk menampung banyaknya barang yang ingin diinput
    cout << "Masukkan jumlah data barang yang ingin diinputkan : "; //perintah untuk menginput banyak data barang yang ingin diinput
    cin >> jumlahData; //input berupa var jumlahData yang bertipe int

    int banyakTanggal;//deklarasi variabel banyakTanggal untuk menampung banyaknya hari 
     while(true) {//looping dimana statement akan terus berjalan selama kondisinya masih true
        cout << "Masukkan tanggal terakhir (min. 5 hari) : ";//perintah untuk menginput jumlah hari/tanggal
        cin >> banyakTanggal;//input berupa variabel banyakTanggal
        if (banyakTanggal < MIN_TANGGAL){
            cout << "tanggal hari harus minimal " << MIN_TANGGAL << "\n";//akan keluar pesan ini lalu kembali ke bagian input banyakTanggal
            }
            else{
                break;//jika tidak akan masuk statement break yang akan menghentikan looping dan lanjut mengeksekusi baris berikutnya
                }
                }

    DataBarang dataBarang[jumlahData][banyakTanggal];// pembuatan array 2D dengan panjang jumlahData dan banyakTanggal

    // Memasukkan data
    for (int i = 0; i < jumlahData; i++){//looping dimulai dari indeks 0 dan diiterasi sebanyak i < jumlahData 
        cout << "Masukkan nama barang ke-" << i+1 <<  " : ";//pesan untuk memasukkan nama barang 
        cin >> dataBarang[i][0].nama;//input akan disimpan di array dataBarang indeks [i][0].nama
    }
    cout << "\n";

    //looping untuk memasukkan jumlah dari barang per tanggalnya
    for(int i=0; i < banyakTanggal; i++){//loop untuk mengatur iterasi untuk setiap tanggal
        cout << "Tanggal ke-" << i+1 << "\n";
    for (int j = 0; j < jumlahData; j++){//looping untuk memasukan jumlah setiap barang setiap harinya 
        cout << "Masukkan jumlah " << dataBarang[j][0].nama << " tanggal " << i+1 << " : ";//perintah untuk memasukkan jumlah barang
        cin >> dataBarang[j][i].jumlah;//input akan disimpan di array jumlahBarang pada indeks [j][i].jumlah
        dataBarang[j][i].tanggal= i + 1;//agar tanggal dimulai dari 1
    }
    cout << "\n";
    }

    line();
    cout << "\t\t\tTabel data barang" << "\n";////menampilkan tabel data barang
    line();
    cout << setw(7) << "tanggal";//Menampilkan kata "tanggal" dengan lebar kolom sebanyak 7 karakter menggunakan fungsi setw.
    for (int i = 0; i < jumlahData; i++){//looping untuk menampilkan nama barang 
        cout << setw(15) << dataBarang[i][0].nama;
    }
    cout << '\n';
    line();
    for (int i = 0; i < banyakTanggal; i++){//looping untuk menampilkan tanggal
        cout << setw(6) << i+1;
        for(int j = 0; j < jumlahData; j++){//looping untuk menampilkan jumlah barang per tanggal dan jenis
            cout << setw(15) << dataBarang[j][i].jumlah;
        }
        cout << "\n";
    }
    line();
    
    while (true) {//looping dengan kondisi true
        int tanggalPencarian;//Deklarasi variabel tanggalPencarian
        int indeksBarang;//Deklarasi variabel indeksBarang
        cout << "\nMasukkan tanggal dan kode barang untuk mencari detail barang" << "\n";//pesan untuk input tanggal dan kode dari barang yang ingin dicari
        cout << "Masukkan tanggal pencarian\t\t\t: ";//perintah untuk memasukan tanggal
        cin >> tanggalPencarian;//input berupa var cariTanggalBarang
        cout << "Masukkan kode barang (kode berupa indeks barang) : ";//perintah untuk memasukkan kode dari barang yang ingin dicari (kode berupa indeks dari barang)
        cin >> indeksBarang;//input berupa var indeksBarang
        
        line();
        // Validasi indeks barang
        if (indeksBarang >= 0 && indeksBarang < jumlahData) {
            int indeksTanggal = tanggalPencarian - 1;//indeksTanggal merupakan nilai dari tanggalPencarian - 1
            if (indeksTanggal >= 0 && indeksTanggal < banyakTanggal) {//kondisi jika tanggal dan kode dari barang yang dicari ada
                cout << "Detail Barang";//akan menampilkan detail dari barang yang dicari
                cout << "\nData Tanggal  : " << tanggalPencarian;//dimulai dari tanggalPencarian
                cout << "\nNama Barang   : " << dataBarang[indeksBarang][0].nama;//nama barangnya 
                cout << "\nAlamat Barang : " << &dataBarang[indeksBarang][indeksTanggal].nama;//alamat dari barang 
                cout << "\n";
                line();
                }else{//jika barang yang dicari tidak ada 
                    cout << "Detail barang tidak ditemukan. Tanggal tidak valid." << "\n";
                    }
        }else{
            cout << "Detail barang tidak ditemukan. Kode barang tidak valid." << "\n";
            }
    char ulangi;
    cout << "Apakah Anda ingin mencari detail barang lagi? (y/n) : ";//pertanyaan kepada user apakah ingin mencari data barang lagi
    cin >> ulangi;//input berupa char 
    cout << "\n";
    if (ulangi == 'Y'||ulangi == 'y'){//pengkondisian jika pilihan user N atau n, maka akan kembali ke menu
    cout <<"memproses permintaan anda....\n";
    }else if (ulangi == 'n' || ulangi == 'N'){//kondisi jika jawaban user N atau n
    cout << "Terima kasih telah menggunakan program ini.See You!" << "\n";
    break; // Keluar dari loop jika jawaban bukan 'n' atau 'N'
    }
    }
    line();
    identitas();
    return 0;
    }
