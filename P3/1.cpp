#include<iostream>
#include <conio.h> //library agar bisa menggunakan getch();
using namespace std;

struct mahasiswa {//Struck mahasiswa
    string nama;//berisi nama dengan tipe data string
    string npm;//NPM yang bertipe data string
    struct dataNilai {//string di dalam string untuk menyimpan data nilai
        int absen;//terdiri dari var absen yang bertipe data int
        int tugas;//var tugas yang bertipe data int
        int uts;//var uts yang bertipe data int
        int uas;//var uas yang bertipe data int
    } nilai;//diberi kata kata kunci nilai
    double nilaiAkhir;//var nilaiAkhir untuk menyimpan nilai akhir
    char hurufMutu;//var char untuk menyimpan huruf mutu
};

const int maxMahasiswa = 20;//jumlah maksimal mahasiswa yang bisa diinput dan bersifat const atau nilai nya tidak akan berubah
int jumlahMahasiswa = 0;//Jumlah mahasiswa saat ini
mahasiswa mhs[maxMahasiswa];////array untuk menyimpan data mahasiswa dengan tipe data mahasiswa,dimana mahasiswa ini merupakan struct

void line() {//fungsi untuk mencetak garis horizontal
    for (int i = 0; i < 73; i++) {
        cout << "=";
    }
    cout << "\n";
}

void identitas() {//fungsi untuk mencetak nama dan npm
    cout << "Program dibuat oleh :\n";
    cout << "Nama : Delia Nur Ilmi Salam\n";
    cout << "NPM  : 2310631170069\n";
}

void menu() {//fungsi untuk menampilkan menu apa saja yang ada
    line();
    cout << "|\t\t\tSistem Manajemen Data Mahasiswa\t\t\t|\n";
    line();
    cout << "| 1. Tambah Mahasiswa\t\t\t\t\t\t\t|\n"; 
    cout << "| 2. Tampilkan Mahasiswa\t\t\t\t\t\t|\n";
    cout << "| 3. Edit Data Mahasiswa\t\t\t\t\t\t|\n"; 
    cout << "| 4. Hapus Data Mahasiswa\t\t\t\t\t\t|\n"; 
    cout << "| 5. Keluar\t\t\t\t\t\t\t\t|\n"; 
    line();
}

void tambahData() {//fungsi untuk menambah data 
    char pil;//deklarasi var pil yang bertipe data char
    do {//menggunakan perulangan do while agar kode dijalankan sekali lalu akan dijalankan ketika kondisi di while terpenuhi
        if (jumlahMahasiswa < maxMahasiswa) {//pengkondisian dimana jika jumlah mahasiswa lebih kecil dari max mahasiswa maka akan masuk ke statement berikutnya
            mahasiswa mahasiswaBaru;//variabel baru dengan tipe data Mahasiswa
            line();
            cout << "|\t\t Menu Tambah Data Mahasiswa \t\t\t\n";//menampilkan judul dari fungsi
            line();
            cout << "Masukkan nama mahasiswa ke-"<< jumlahMahasiswa+ 1 <<"\t\t: ";//pengguna akan diminta menginput nama mahasiswa
            cin.ignore();//digunakan untuk mengabaikan karakter tertentu dalam buffer input
            getline(cin, mahasiswaBaru.nama);//digunakan agar komputer bisa membaca satu garis penuh input termasuk spasi dan menyimpannya sebagai nama mahasiswa baru
            cout << "Masukkan NPM mahasiswa\t\t\t: ";//perintah untuk menginput npm mahasiswa
            cin >> mahasiswaBaru.npm;//input akan disimpan di mahasiswaBaru.npm
            cout << "Data Nilai :\n";
            cout << "Masukkan nilai absen \t\t\t: ";//perintah untuk menginput nilai absen mahasiswa 
            cin >> mahasiswaBaru.nilai.absen;//input akan disimpan di mahasiswaBaru.nilai.absen
            cout << "Masukkan nilai tugas \t\t\t: ";//perintah untuk menginput nilai tugas mahasiswa
            cin >> mahasiswaBaru.nilai.tugas;//input akan disimpan di mahasiswaBaru.nilai.uts
            cout << "Masukkan nilai uts   \t\t\t: ";//perintah untuk menginput nilai uts mahasiswa
            cin >> mahasiswaBaru.nilai.uts;//input akan disimpan di mahasiswaBaru.nilai.uts
            cout << "Masukkan nilai uas   \t\t\t: ";//perintah untuk menginput nilai uas mahasiswa
            cin >> mahasiswaBaru.nilai.uas;//input akan disimpan di mahasiswaBaru.nilai.uas

            // Hitung nilai akhir
            mahasiswaBaru.nilaiAkhir = (0.1 * mahasiswaBaru.nilai.absen) + (0.2 * mahasiswaBaru.nilai.tugas) + (0.3 * mahasiswaBaru.nilai.uts) + (0.4 * mahasiswaBaru.nilai.uas);
            
            // pengkondisian untuk menentukan nilai huruf
            if (mahasiswaBaru.nilaiAkhir > 80)//jika mahasiswaBaru.nilaiAkhir > 80
                mahasiswaBaru.hurufMutu = 'A';//maka mahasiswaBaru.hurufMutu = 'A'
            else if (mahasiswaBaru.nilaiAkhir > 70)//jika mahasiswaBaru.nilaiAkhir > 70
                mahasiswaBaru.hurufMutu = 'B';//maka mahasiswaBaru.hurufMutu = 'B'
            else if (mahasiswaBaru.nilaiAkhir > 60)//Jika mahasiswaBaru.nilaiAkhir > 60
                mahasiswaBaru.hurufMutu = 'C';//maka mahasiswaBaru.hurufMutu = 'C'
            else//pengkondisian jika nilaiAKhir < 60
                mahasiswaBaru.hurufMutu = 'D';//maka mahasiswaBaru.hurufMutu = 'D'

            mhs[jumlahMahasiswa] = mahasiswaBaru;//data mahasiswaBaru tersebut akan disimpan di dalam array mhs dimulai dari indeks ke-0
            jumlahMahasiswa++;//iterasi untuk meningkatkan nilai jumlahMahasiswa atau indeks dari array mhs

            cout << "Data Mahasiswa berhasil ditambahkan.\n";//pesan jika data berhasil disimpan
            line();
            cout << "Apakah anda ingin menambahkan data mahasiswa lagi?(Y/N):";//membuat pilihan untuk melanjutkan menu atau keluar dari menu
            cin >> pil;//input berupa var pil dengan tipe data char
            system("cls");
        } else {//jika jumlah maksimal mahasiswa telah tercapai
            cout << "Jumlah maksimum mahasiswa telah tercapai\n";
        }
    } while (pil=='Y' || pil=='y');//membuat perulangan dari pilihan y/n diatas
}

void tampilDataMahasiswa () {//fungsi untuk menampilkan data mahasiswa
    line();
    cout << "|\t\t\t Data Mahasiswa \t\t\t\t|\n";//judul dari menu
    line();
    if (jumlahMahasiswa == 0) {//jika belum ada data yang tersimpan di array
        cout << "Tidak ada mahasiswa dalam sistem.\n\n";
    } else {//jika ada data yang tersimpan di array 
        cout << "Daftar Mahasiswa :\n";//data akan ditampilkan
        for (int i = 0; i < jumlahMahasiswa; i++) {//dimulai dari data ke[0] sebanyak i < jumlahMahasiswa yang tersimpan
            line();
            cout << "Nama\t\t : " << mhs[i].nama << "\n";//Menampilkan nama
            cout << "NPM\t\t : " << mhs[i].npm << "\n";//Menampilkan Npm
            cout << "Nilai Akhir\t : " << mhs[i].nilaiAkhir << "\n";//Menampilkan nilai akhir
            cout << "Nilai Huruf\t : " << mhs[i].hurufMutu << "\n";//Menampilkan huruf mutu dari nilai akhir
        }
        line();
        cout << "Tekan enter untuk kembali ke menu.";
    }
}


void editDataMahasiswa(string editData) {//fungsi untuk mengedit data mahasiswa dengan parameter variabel editData bertipe data string
    bool ditemukan = false;//menggunakan operasi bool untuk mengedit data mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {/*perulangan untuk mencari data mahasiswa dengan npm yang diinputkan.
                                             perulangan dimulai dari i = 0 hingga i mencapai nilai <  jumlahMahasiswa*/
        if (mhs[i].npm == editData) {//Pengkondisian jika NPM mahasiswa pada indeks ke-i sama dengan NPM yang ingin diubah
            ditemukan = true;//nilai bool akan berubah menjadi true
            line();
            cout << "Mahasiswa ditemukan.\n";//pesan jika data yang ingin diubah ditemukan
            cout << "Nama\t\t : " << mhs[i].nama << "\n";//akan ditampilkan dulu data dari mahasiswa yang ingin diubah
            cout << "NPM\t\t : " << mhs[i].npm << "\n";
            cout << "Nilai Akhir\t : " << mhs[i].nilaiAkhir << "\n";
            cout << "Nilai Huruf\t : " << mhs[i].hurufMutu << "\n";
            line();
            char ubahData;//deklarasi varaibel ubahData yang akan diguankan untuk menampung pilihan 
            do {
                cout << "Data apa yang ingin anda ubah?\n";//menanyakan kepada user data apa yang ingin user ubah
                cout << "A. Nama\n";
                cout << "B. NPM\n";
                cout << "C. Nilai\n";
                cout << "D. Semua data\n";
                cout << "Masukkan Pilihan (A/B/C/D): ";//perintah untuk memasukkan pilihan
                cin >> ubahData;//input akan didimpan di variabel ubahData
                switch (ubahData) {// Switch statement untuk memilih tindakan berdasarkan input
                case 'A'://jika input 'A' atau 'a'
                case 'a':
                    cout << "Masukkan Nama Mahasiswa: ";//data yang akan diubah adalah data bagian nama 
                    cin.ignore();
                    getline(cin, mhs[i].nama);
                    cout << "Data Mahasiswa berhasil diubah.\n";//pesan jika data berhasil diubah
                    cout << "Tekan enter untuk kembali ke menu.";
                    break;// Keluar dari switch statement
                case 'B'://Jika input 'B atau 'b'
                case 'b':
                    cout << "Masukkan NPM Mahasiswa: ";//data yang akan diubah adalah data bagian npm
                    cin >> mhs[i].npm;
                    cout << "Data Mahasiswa berhasil diubah\n";
                    cout << "Tekan enter untuk kembali ke menu.";
                    break;
                case 'C'://Jika input 'C' atau 'c' 
                case 'c':
                    cout << "Masukkan nilai absen : ";//data yang akan diubah adalah data bagian nilai dimuali dari absen sampai nilai uas
                    cin >> mhs[i].nilai.absen;
                    cout << "Masukkan nilai tugas : ";
                    cin >> mhs[i].nilai.tugas;
                    cout << "Masukkan nilai uts : ";
                    cin >> mhs[i].nilai.uts;
                    cout << "Masukkan nilai uas : ";
                    cin >> mhs[i].nilai.uas;

                    // Menghitung ulang nilai akhir sesuai update data nilai terbaru yang barusan diinput
                    mhs[i].nilaiAkhir = (0.1 * mhs[i].nilai.absen) + (0.2 * mhs[i].nilai.tugas) 
                    + (0.3 * mhs[i].nilai.uts) + (0.4 * mhs[i].nilai.uas);

                    // menentukan huruf  mutu dari nilai akhir
                    if (mhs[i].nilaiAkhir > 80)
                        mhs[i].hurufMutu = 'A';
                    else if (mhs[i].nilaiAkhir > 70)
                        mhs[i].hurufMutu = 'B';
                    else if (mhs[i].nilaiAkhir > 60)
                        mhs[i].hurufMutu = 'C';
                    else
                        mhs[i].hurufMutu = 'D';

                    cout << "Data Mahasiswa berhasil diubah\n";
                    cout << "Tekan enter untuk kembali ke menu.";
                    break;
                case 'D'://Jika input 'D' atau 'd' 
                case 'd':
                    cout << "Masukkan Nama Mahasiswa : ";//data yang akan diubah adalah semua data dimulai dari nama sampai nilai
                    cin.ignore();
                    getline(cin, mhs[i].nama);
                    cout << "Masukkan NPM Mahasiswa : ";
                    cin >> mhs[i].npm;
                    cout << "Masukkan nilai absen : ";
                    cin >> mhs[i].nilai.absen;
                    cout << "Masukkan nilai tugas : ";
                    cin >> mhs[i].nilai.tugas;
                    cout << "Masukkan nilai uts : ";
                    cin >> mhs[i].nilai.uts;
                    cout << "Masukkan nilai uas : ";
                    cin >> mhs[i].nilai.uas;

                    // Menghitung ulang nilai akhir sesuai update data nilai terbaru yang barusan diinput
                    mhs[i].nilaiAkhir = (0.1 * mhs[i].nilai.absen) + (0.2 * mhs[i].nilai.tugas) 
                    + (0.3 * mhs[i].nilai.uts) + (0.4 * mhs[i].nilai.uas);

                    // menentukan huruf  mutu dari nilai akhir
                    if (mhs[i].nilaiAkhir > 80)
                        mhs[i].hurufMutu = 'A';
                    else if (mhs[i].nilaiAkhir > 70)
                        mhs[i].hurufMutu = 'B';
                    else if (mhs[i].nilaiAkhir > 60)
                        mhs[i].hurufMutu = 'C';
                    else
                        mhs[i].hurufMutu = 'D';
                    cout << "Data Mahasiswa berhasil diubah.\n";
                    cout << "Tekan enter untuk kembali ke menu.";
                    getch();
                    break;
                default://jika input selain dari di atas
                    cout << "Pilihan tidak valid.\n";
                    break;
                    }
                }//membuat kondisi while dimana program akan terus kembali ke bagian input data mana yang ingin diubah selama kondisi di while terpenuhi
                    while(ubahData != 'A' && ubahData != 'a' && ubahData != 'B' && ubahData != 'b' && ubahData != 'C' 
                    && ubahData != 'c' && ubahData != 'D' && ubahData != 'd');
        }
    }if (!ditemukan) {//kondisi jika data mahasiswa yang ingin diubah berdasarkan npm nya tidak ada
        cout << "Mahasiswa dengan NPM " << editData << " tidak ditemukan.\n";
        cout << "Tekan enter untuk kembali ke menu.";
    }
}
            
void hapusDataMahasiswa(string hapusNpm) {//fungsi untuk menghapus data dengan parameter var hapusNpm yang bertipe data string
    bool ditemukan = false;//menggunakan operasi bool untuk mengetahui data mahasiswa dengan npm yang ingin dihapus ada atau tidak
    for (int i = 0; i < jumlahMahasiswa; i++) {/*perulangan untuk mencari data mahasiswa dengan npm yang diinputkan.
                                             perulangan dimulai dari i = 0 hingga i mencapai nilai <  jumlahMahasiswa*/
        if (mhs[i].npm == hapusNpm) {//Pengkondisian jika NPM mahasiswa pada indeks ke-i sama dengan NPM dari mahasiswa yg ingin dihapus
            ditemukan = true;//nilai bool akan berubah menjadi true
            line();
            cout << "Mahasiswa ditemukan.\n";//data dari mahasiswa yang ingin dihapus akan ditampilkan dahulu
            cout << "Nama\t\t : " << mhs[i].nama << "\n";
            cout << "NPM\t\t : " << mhs[i].npm << "\n";
            cout << "Nilai Akhir\t : " << mhs[i].nilaiAkhir << "\n";
            cout << "Nilai Huruf\t : " << mhs[i].hurufMutu << "\n";
            line();
            // mengkonfirmasi penghapusan
            char konfirmasi;//deklarasi var konfirmasi yang bertipe data char
            cout << "Apakah Anda yakin ingin menghapus data mahasiswa ini? (Y/N): ";//pertanyaan untuk user apakah yakin ingin menghapus data atau tidak
            cin >> konfirmasi;//input akan disimpan di variabel konfirmasi
            if (konfirmasi == 'Y' || konfirmasi == 'y') {//Pengkondisian jika konfirmasi == 'Y' atau 'y'
                for (int j = i; j < jumlahMahasiswa - 1; j++) {/*perulangan untuk menggeser data sesudah data yang dihapus 
                                                                menjadi mengisi indeks data yang tadi dihapus*/
                    mhs[j] = mhs[j + 1];
                }
                jumlahMahasiswa--;//pengurangan jumlahMahasiswa
                cout << "Data Mahasiswa berhasil dihapus.\n";
                cout << "Tekan enter untuk kembali ke menu.";
            } else {//kondisi jika konfirmasi != 'Y' atau 'y'
                cout << "Penghapusan data dibatalkan.\n";
                cout << "Tekan enter untuk kembali ke menu.";
            }
            break;//keluar dari statement loop 
        }
    }
    if (!ditemukan) {//jika data mahasiswa dengan npm yang ingin dihapus tidak ditemukan
        cout << "Mahasiswa dengan NPM " << hapusNpm << " tidak ditemukan.\n";
        cout << "Tekan enter untuk kembali ke menu.";
    } 
}

int main() {//fungsi utama
    char pilihan;//deklarasi var pilihan dengan tipe data char
    do {//menggunakan perulangan do agar program dijalankan dulu sekali
        menu();//memanggil fungsi menu 
        cout << "Pilihan Anda: ";//pesan untuk menginput pilihan menu
        cin >> pilihan;//input akan disimpan di var pilihan
        system("cls");//membersihkan layar dari output sebelumnya 

        switch(pilihan) {// Switch statement untuk memilih tindakan berdasarkan input
            case '1'://jika input 1
                tambahData();//masuk ke menu tambahData
                system("cls");//clear screen, membersihkan layar setelah fungsi tambahData selesai diesksekusi
                break;
            case '2'://jika input 2
                tampilDataMahasiswa();//Memanggil fungsi tampilDataMahasiswa dan masuk ke menu tampil Data Mahasiswa
                getch();//agar ada jeda sebelum clear skin , jeda sampai user menekan tombol apapun
                system("cls");
                break;
            case '3': {//jika input 3
                string editData;//deklarasi variabel editData yang bertipe data string
                line();
                cout << "|\t\t\t Menu Edit Data Mahasiswa \t\t\t|\n";//judul menu ke-3
                line();
                cout << "Masukkan NPM mahasiswa yang ingin diubah: ";//perintah untuk menginput npm dari mahasiswa yang ingin diubah
                cin >> editData;//input disimpan di variabel editData
                editDataMahasiswa(editData);//memanggil fungsi editDataMahasiswa dan masuk ke menu edit data
                getch();
                system("cls");
                break;
            }
            case '4': {//jika input 4
                string hapusNpm;//deklarasi variabel hapusNpm yang bertipe data string
                line();
                cout << "|\t\t\t Menu Hapus Data Mahasiswa\t\t\t|\n";//judul menu ke-5
                line();
                cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";//perintah untuk menginputkan npm dari mahasiswa yang ingin diubah 
                cin >> hapusNpm;//input disimpan di variabel hapusNpm
                hapusDataMahasiswa(hapusNpm);//Memanggil fungsi hapusDataMahasiswa dan masuk ke menu hapus data
                getch();
                system("cls");
                break;
            }
            case '5': {//jika input 5
                cout << "Apakah anda yakin ingin keluar dari program?(Y/N):"; //konfirmasi ke user apakah benar ingin keluar atau tidak
                char exit;//deklarasi var exit yan bertipe data char
                cin >> exit;//input akan disimpan di variabel exit
                if (exit == 'N'||exit == 'n'){//pengkondisian jika pilihan user N atau n, maka akan kembali ke menu
                    cout <<"Anda memilih untuk tetap berada di program.\n";
                } else if (exit =='Y' || exit== 'y'){//pengkondisian jika pilihan user Y atau y, maka program akan berhenti
                    cout <<"Anda telah keluar dari program. Terimakasih!\n";
                    line();
                    identitas();//memanggil fungsi identitas
                    line();
                    return 0; //menunjukan program berhasil dieksekusi sampai akhir
                }
                break;
            }
            default://jika input selain 1-5
                cout << "Pilihan tidak valid. Silakan pilih kembali.\n";//pesan untuk memilih pilihan yang valid
                getch();
                system("cls");
        }
    } while (true);//perulangan akan terus dijalankan selama kondisi nya true
    return 0;
}