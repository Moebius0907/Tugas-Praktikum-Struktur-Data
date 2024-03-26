#include <iostream> // Library agar bisa mengakses perintah input dan output
#include <conio.h> // Library agar bisa mengakses perintah getch();
#include <iomanip> // library untuk memanipulasi ouput 
using namespace std;

const int jumlahKursi = 50; // deklarasi dan inisialisasi variabel jumlahKursi untuk menampung jumlah kursi yang bersifat konstan

struct film {//struct film yang terdiri dari variabel waktu,kode,judul, dan harga yang berguna untuk memyimpan informasi tentang film
    string waktu;//digunakan untuk menyimpan informasi mengenai waktu tayang dari film
    int kode;// digunakan untuk menyimpan informasi mengenai kode dari film
    string judul;// digunakan untuk menyimpan informasi mengenai judul dari film
    float harga;// digunakan unuk menyimpan informasi mengenai harga dari film
};

struct kursi {//struct kursi yang digunakan untuk menyimpan informasi mengenai kursi
    int nomor;// terdiri dari varibel nomor yang bertipe data int, digunakan untuk menyimpan nomor kursi
    bool booked;// variabel booked yang bertipe data bool, digunakan untuk menyimpan status apakah kursi masih kosong atau tidak
};

struct pesanan {//struct pesanan yang digunakan untuk menyimpan informasi tentang pesanan
    int nomorPesanan;// variabel nomorPesanan yang digunakan untuk menyimpan nomor dari pesanan, bertipe data int
    float totalPesanan;// variabel totalPesanan yang digunakan untuk menyimpan jumlah total pesanan, bertipe data float
    bool dibayar;// variabel dibayar yang digunakan untuk menyimpan status pesanan sudah dibayar atau belum 
};

void line() {//fungsi untuk mencetak garis horizontal
    for (int i = 0; i < 97; i++) {
        cout << "=";
    }
    cout << "\n";
}

void identitas() {//fungsi untuk mencetak nama dan npm
    cout << "Program dibuat oleh :\n";
    cout << "Nama : Delia Nur Ilmi Salam\n";
    cout << "NPM  : 2310631170069\n";
}


void daftarMenu () {//fungsi untuk menampilkan menu apa saja yang ada
    line();
        cout << "|" << setw(53) << "BIOSKOP LA LA LA" << setw(44) << "|\n";
        line();
        cout << "|1. Daftar Film" << setw(83) << "|\n";
        cout << "|2. Pesan Tiket Film" << setw(78) << "|\n";
        cout << "|3. Lihat dan Bayar Pesanan" << setw(71) << "|\n";
        cout << "|4. Daftar Kursi" << setw(82) << "|\n";
        cout << "|5. Exit" << setw(90) << "|\n";
        line();
}

void tampilFilmTayang(const film daftarFilm[], int jumlahFilm) {//fungsi untuk menampilkan film apa saja yang tersedia
//memiliki parameter const film daftarFilm[], int jumlahFilm
    line();
    cout << "|\tWaktu Tayang\t|\tKode Film\t| Nama Film\t\t|\tHarga Tiket\t|\n";
    line();
    for (int i = 0; i < jumlahFilm; ++i)// looping untuk menampilkan informasi daftar film dimulai dari film yang tersimpan di array daftarFilm indeks ke-0 sampai indeks < jumlahFilm (5)
    {
        cout << "|\t" << daftarFilm[i].waktu << "\t\t|\t   " << daftarFilm[i].kode << "\t\t| " << daftarFilm[i].judul << "\t\t|\tRp." << daftarFilm[i].harga << "\t|\n";
        //informasi berupa waktu tayang, kode film, judul film, dan harga dari tiket untuk film tersebut
    }
    line();
}

void listPesanan (const pesanan listPesanan[], int jumlahPesanan) {//fungsi untuk melihat list pesanan
    if (jumlahPesanan == 0) { //Pengkondisian jika jumlahPesanan == 0 atau belum ada pesanan yang tercatat di sistem
        cout << "Tidak ada pesanan yang tersedia saat ini.\n";//akan menampilkan pesan disamping
    } else {//Pengkondisian jika ada pesanan yang tersimpan di array listPesanan
        line();
        cout << "|\tNomor Pesanan\t|\tTotal Pembelian\t\t|\tStatus Pembayaran\t\t|\n";
        line();
        for (int i = 0 ; i < jumlahPesanan ; i++) {//looping untuk menampilkan informasi pesanan
            cout << "|\t     " << listPesanan[i].nomorPesanan << "\t\t|\t      Rp." << listPesanan[i].totalPesanan << "\t\t|\t   " << (listPesanan[i].dibayar ? "Sudah Dibayar" : "Belum Dibayar") << "\t\t|\n";
            }
        line();
    }
}

void bayarPesanan (pesanan daftarPesanan[], int& jumlahPesanan) {//fungsi untuk membayar pesanan berdasarkan nomor pesanan
    if (jumlahPesanan == 0) {//pengkondisian jika jumlahPesanan == 0 atau belum ada pesanan yang tercatat pada sistem
        cout << "Tidak ada pesanan yang tersedia untuk dibayar saat ini.\n";//pesan yang muncul jika jumlahPesanan == 0
        cout << "Tekan enter untuk kembali ke beranda!.";// Perintah untuk menekan enter untuk kembali ke beranda

        return;// Untuk mengakhiri eksekusi fungsi
    }

    int nomor;//Deklarasi variabel nomor untuk menyimpan input pengguna
    float uangPembayaran;//Deklarasi variabel uangPembayaran untuk menyimpan input uangPembayaran

    listPesanan(daftarPesanan, jumlahPesanan);//memanggil fungsi listPesanan
    cout << "Masukkan nomor pesanan yang ingin dibayar : ";//Perintah kepada user untuk menginput nomor pesanan yang ingin dibayar
    cin >> nomor;//input akan disimpan di variabel nomor

    for (int i = 0; i < jumlahPesanan ; i++) {//Looping untuk mencari daftar pesanan yang sesuai dengan input user
        if (daftarPesanan[i].nomorPesanan == nomor) {//pengkondisian jika daftarPesanan[i].nomorPesanan == nomor
            if (!daftarPesanan[i].dibayar) {//pengkondisian jika pesanan belum dibayar
                while (true) {//looping while selama kondisi true
                    cout << "Masukkan jumlah pembayaran : Rp.";//Perintah untuk menginput jumlah pembayaran 
                    cin >> uangPembayaran;//Input disimpan di variabel uangPembayaran
                    
                    if (uangPembayaran >= daftarPesanan[i].totalPesanan) {//Pengkondisian jika uangPembayaran >= daftarPesanan[i].totalPesanan
                    daftarPesanan[i].dibayar = true;//inisialisasi daftarPesanan[i].dibayar = true
                    float kembalian = uangPembayaran - daftarPesanan[i].totalPesanan;//Deklarasi dan Inisialisasi variabel kembalian
                    cout << "Kembalian : Rp." << kembalian << "\n";//Menampilkan kembalian
                    cout << "Pembayaran untuk pesanan nomor " << nomor << " berhasil dilakukan.\n";//Menampilkan pesan pembayaran untuk pesanan nomor yang diinput berhasil dilakukan
                    cout << "Selamat Menonton!.\n";
                    break;//Keluar dari looping
                } else {//Pengkondisian jika uangPembayaran <= daftarPesanan[i].totalPesanan
                    cout << "Maaf, Jumlah uang tidak mencukupi. Masukkan jumlah yang sesuai!\n";//Pesan untuk membayar sesuai nominal 
                        cout << "Apakah Anda ingin mencoba lagi? (Y/N): ";//Pertanyaan apakah user ingin coba membayar lagi atau tidak
                        char pilihan;//Deklarasi variabel pilihan
                        cin >> pilihan;//Input akan disimpan di variabel piliihan
                        if (pilihan != 'Y' && pilihan != 'y')//Pengkondisian jika user memilih tidak
                        {
                            break;}//keluar dari looping 
                            }
                        }
                        cout << "Tekan enter untuk kembali ke beranda!";
            }else {//pengkondisian jika daftarPesanan[i].dibayar = true
                cout << "Pesanan dengan nomor " << nomor << " sudah dibayar sebelumnya.\n";
            }
            return;//Mengakhiri eksekusi fungsi
        }
    }
    cout << "Nomor pesanan tidak ditemukan. Tekan enter untuk kembali!\n";//Pengkondisian jika daftarPesanan[i].nomorPesanan != nomor
} 

void pesanTiket(film daftarFilm[5], kursi daftarKursi[], int jumlahKursi, pesanan listPesanan[], int& jumlahPesanan) {//fungsi untuk memesan tiket dan memilih kursi
    int kodeFilm, n, nomorKursi;//Deklarasi variabel kodeFilm, n, dan nomorKursi yang bertipe data integer
    float hargaTiket;//Deklarasi variabel hargaTiket 
    char yn;//Deklarasi variabel yn

    do {//Menggunakan looping do-while agar program dijalankam dulu sekali lalu akan terus diulangi selama kondisi di while terpenuhi
        
        int kursiTersedia = 0;//Deklarasi dan inisialisasi kursiTersedia dengan 0
        for (int i = 0; i < jumlahKursi; i++) {//Looping untuk mengecek kursi yang tersedia
            if (!daftarKursi[i].booked)//Pengkondisian jika kursi pada array daftarKursi[i] masih available
                kursiTersedia++;//Variabel kursiTersedia akan diiterasi 
        }

        // Memanggil fungsi untuk menampilkan daftar film
        tampilFilmTayang(daftarFilm, 5);

        // Kode untuk memilih  dengan input kode dari filmnya
        do {//Looping do agar program dijalankan sekali
            cout << "Masukkan Kode Film\t\t: ";
            cin >> kodeFilm;//Input kode akan disimpan di varaibel kodeFilm 
            if (kodeFilm < 1 || kodeFilm > 5) {//Pengkondisian jika kodeFilm yang diinput < 1 atau > 5
            cout << "Kode film yang Anda pilih tidak valid.\n";
            } 
        } while (kodeFilm < 1 || kodeFilm > 5);//Looping akan terus dijalankan selama kodeFilm < 1 atau kodeFilm > 5

        // Menampilkan judul dari film yang dipesan
        cout << "Judul film yang dipesan\t\t: " << daftarFilm[kodeFilm - 1].judul << "\n";

        // Memasukkan jumlah pembelian tiket
        do {//Looping do agar program dijalankan sekali
            cout << "Masukkan jumlah pembelian tiket : ";//Perintah input jumlah pembelian tiket
            cin >> n;//Input disimpan di variabel n 
            if (n <= 0) {//Pengkondisian jika jumlah pembelian tiket kurang dari sama dengan 0
                cout << "Jumlah pembelian tidak valid.\n";
                }
            } while (n <= 0);//Looping akan terus berjalan selama kondisinya n <= 0

        // Menghitung harga Tiket
        hargaTiket = n * daftarFilm[kodeFilm - 1].harga;//operasi untuk menghitung harga tiket
        cout << "Harga Tiket\t\t\t: Rp." << hargaTiket << "\n";//harga tiket akan ditampilkan 

        // Pemberian diskon jika pembelian lebih dari 5 tiket
        if (n > 5) {
            hargaTiket = hargaTiket * 0.4;//operasi untuk menghitung harga tiket setelah didiskon
            cout << "Harga setelah diskon\t\t: Rp." << hargaTiket << "\n";
        }

        //Memesan kursi
        if (n <= kursiTersedia) {//Pengkondisian jika jumlah pembelian tiket <= kursiTersedia
            line();
            pesanan pesananTiket;//Deklarasi variabel pesananTiket yang bertipe data struct pesanan
            pesananTiket.nomorPesanan = jumlahPesanan + 1;//Inisialisasi nomorPesanan pada pesananTiket dengan jumlahPesanan + 1
            pesananTiket.dibayar = false;//inisialiasi dibayar pada pesananTiket dengan false
            for (int j = 0; j < n; j++) {//Looping untuk memilih kursi sebanyak n 
                do {//Looping untuk menginput nomor kursi yang belum dibooking
                    cout << "Pilih nomor kursi ke-" << j+1 << " (1-" << jumlahKursi << ") : ";//Perintah menginput nomor kursi yg diinginkan
                    cin >> nomorKursi;//Input akan disimpan di variabel nomorKursi

                    if (nomorKursi < 1 || nomorKursi > 50) {//Jika nomor yang diinput tidak valid
                        cout << "Nomor kursi tidak valid.\n";
                        continue;//menghentikan eksekusi dan lanjut ke iterasi selanjutnya 
                    }

                    if (daftarKursi[nomorKursi-1].booked) {//jika nomor kursi yang diinput sudah dibooking
                        cout << "Maaf, kursi tersebut sudah dipesan. Silahkan pilih kursi lain!\n";
                    } else {//jika belum dibooking
                        kursi &kursiPilihan = daftarKursi [nomorKursi-1];//Deklarasi variabel referensi &kursiPilihan kursiPilihan 
                        //yang merujuk pada kursi yang sesuai dengan nomor kursi yang diinputkan.
                        kursiPilihan.booked = true;//inisialisasi atribut booked pada kursiPilihan dengan true
                        cout << "Pemesanan tiket berhasil untuk kursi nomor " << nomorKursi << "\n";

                        break;
                    }
                } while (true);//Looping akan terus dijalankan selama kondisinya true
            }
            line();
            cout << "Apakah Anda Ingin Memesan Makanan? (Y/N): ";//pertanyaan untuk menginput pesan makanan atau tidak
            cin >> yn;//input disimpan pada variabel yn
            if (yn == 'Y' || yn == 'y')//Pengkondisian jika yn == 'y' atau 'Y'
            {
                cout << "Menu Makanan:\n";//Menampilkan menu makanan beserta harganya
                cout << "1. Popcorn - Rp. 15000 per bungkus\n";
                cout << "2. Cola-cola - Rp. 10000 per gelas\n";
                // Inisialisasi variabel untuk menyimpan jumlah makanan yang dipesan
                int jumlahPopcorn = 0;
                int jumlahMinuman = 0;
                
                char pilihMakanan;//Deklarasi variabel pilihMakanan yg bertipe data char 
                do {//Looping do untuk memilih makanan
                    int makanan;//Deklarasi variabel makanan yang digunakan untuk menyimpan input makanan yang dipilih
                    cout << "Pilih makanan (1 untuk Popcorn, 2 untuk Minuman) : ";
                    cin >> makanan;

                    switch (makanan)//switch dengan ekspresi makanan
                    {
                        case 1://statement yang akan dijalankan jika input makanan = 1
                        cout << "Masukkan jumlah Popcorn yang ingin dipesan\t : ";
                        cin >> jumlahPopcorn;
                        cout << "Anda memesan " << jumlahPopcorn << " bungkus Popcorn\n";
                        break;
                        
                        case 2://statement yang akan dijalankan jika input makanan = 2
                        cout << "Masukkan jumlah Coca-Cola yang ingin dipesan\t : ";
                        cin >> jumlahMinuman;
                        cout << "Anda memesan " << jumlahMinuman << " gelas Coca-Cola\n";
                        break;

                        default://jika selain 1 atau 2
                        cout << "Menu makanan yang anda pilih tidak valid.\n";
                        break;
                        
                        }
                        cout << "Apakah Anda ingin memesan makanan lagi? (Y/N): ";//Membuat pertanyaan apakah ingin memesan makanan lagi atau tidak
                        cin  >> pilihMakanan;//input disimpan pada variabel pilihMakanan
                        } while (pilihMakanan == 'Y' || pilihMakanan == 'y');//looping akan terus berjalan selama kondisinya pilihMakanan == 'Y' atau 'y'
                        
    // Menghitung total harga makanan
    float hargaPopcorn = jumlahPopcorn * 15000;
    float hargaMinuman = jumlahMinuman * 10000;
    float totalMakanan = hargaPopcorn + hargaMinuman;

    // Menambahkan harga makanan ke total pembelian tiket
    hargaTiket += totalMakanan;
    }

    pesananTiket.totalPesanan = hargaTiket;//Mengisi atribut totalPesanan pada variabel pesananTiket dengan hargaTiket
    listPesanan[jumlahPesanan++] = pesananTiket;//menambahkan pesananTiket ke array listPesanan, lalu jumlahPesanan diiterasi 
    cout << "Total Pesanan : Rp." << pesananTiket.totalPesanan << "\n";//Menampilkan total pesanan
    break;
        } else {
            cout << "Maaf, kursi tidak mencukupi untuk jumlah pembelian tersebut.\n";//pesan jika kursi tidak cukup atau jumlahPesanan > 50
        }
    }while (true);//Looping akan terus berjalan selama kondisinya true
    line();
    cout << "Tekan enter untuk kembali ke beranda dan pilih menu Lihat dan Bayar Pesanan untuk membayar!";
}

int main () {//fungsi utama
    film daftarFilm[5] = {//Inisialisasi array daftarFilm
        {"13:00", 1, "Exhuma", 45000},
        {"14.20", 2, "Moana 2", 35000},
        {"15.30", 3, "Barbie",35000},
        {"18:20", 4, "Frozen 3", 35000},
        {"17:00", 5, "Munkar", 45000}
    };
    kursi daftarKursi[jumlahKursi];//Deklarasi variabel Array daftarKursi dengan panjang sebanyak jumlahKursi yaitu 50 dan bertipe data kursi 
    int jumlahPesanan = 0;//Inisialisasi awal jumlahPesanan
    pesanan daftarPesanan[100];//Array untuk menyimpan daftar pesanan
    
    // Inisialisasi status pemesanan kursi
    for (int i = 0; i < jumlahKursi; ++i)
    {
        daftarKursi[i].nomor = i + 1;
        daftarKursi[i].booked = false;
    }

    int menu;//Deklarasi variabel menu yang digunakan untuk menyimpan input berupa pilihan menu dari user 
    do {//Menggunakan perulangan do-while agar program dijalankan dulu sekali
        daftarMenu();//Memanggil fungsi daftarMenu untuk menampilkan menu
        cout << "Pilihan Menu (1/2/3/4) : ";//Perintah untuk memilih menu
        cin >> menu;//input disimpan di variabel menu
        system("cls");//Membersihkan layar setelah menginput menu 
    

        switch(menu) {//switch dengan ekspresi menu
            case 1 ://Statement yang akan dijalankan jika user menginput 1
                tampilFilmTayang(daftarFilm,5);
                cout << "Tekan enter untuk kembali ke menu!";
                getch();
                system("cls");
                break;
            case 2 : //Statement yang akan dijanlankan jika user menginput 2
                line();
                cout << "|" << setw(50) << "Menu Pesan Tiket" << setw(47) << "|\n";
                pesanTiket(daftarFilm, daftarKursi, jumlahKursi, daftarPesanan, jumlahPesanan);
                getch();
                system("cls");
                break;
            case 3: //Statement yang akan dijalankan jika user menginput 3
                bayarPesanan(daftarPesanan, jumlahPesanan);
                getch();
                system("cls");
                break;
            case 4://Statement yang akan dijalankan jika user menginput 4
                line();
                cout << "|" << setw(50) << "Menu Daftar Kursi" << setw(47) << "|\n";
                line();
                cout << "| No  |" << setw(40) << "Status " << setw(50) <<   "|" << "\n";
                line();
                for (int i = 0; i < jumlahKursi; ++i) //Looping untuk menampilakn nomor dan status kursi mulai dari indeks ke-0 sampai indeks ke-49
                {
                    cout << "| " << setw(3) << daftarKursi[i].nomor << " | ";
                    if (daftarKursi[i].booked)
                    cout << "Booked" << setw(83) << "|" << "\n";
                    else
                    cout << "Available" << setw(80) << "|" << "\n";
                    }
                    line();
                    cout << "Tekan enter untuk kembali ke beranda!";
                    getch();
                    system("cls");
                    break;
            case 5 : //Statement yang akan dijalankan jika user menginput 5 
                cout << "Apakah anda yakin ingin keluar dari program?(Y/N):"; //konfirmasi ke user apakah benar ingin keluar atau tidak
                char exit;//deklarasi var exit yan bertipe data char
                cin >> exit;//input akan disimpan di variabel exit
                if (exit == 'N'||exit == 'n'){//pengkondisian jika pilihan user N atau n, maka akan kembali ke menu
                    cout <<"Anda memilih untuk tetap berada di program.\n";
                    cout << "Tekan enter untuk kembali ke beranda !\n";
                    getch();
                    system("cls");
                } else if (exit =='Y' || exit== 'y'){//pengkondisian jika pilihan user Y atau y, maka program akan berhenti
                    cout <<"Anda telah keluar dari program. Terimakasih telah menggunakan program ini!\n";
                    line();
                    identitas();//memanggil fungsi identitas
                    line();
                    return 0; //menunjukan program berhasil dieksekusi sampai akhir
                }
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu lain.\n";
        }
    } while(true ); // Loop hingga pengguna memilih untuk keluar

    return 0;
}
