#include <iostream>
#include <vector>
using namespace std;

string daftar_sirkuit[10];
string sirkuit;
int banyak_sirkuit = 0;
int nomor;
int status;

int fungsi_login(unsigned long int nim, string nama);
void menu();
void tampilkan();
void tambah();
int ubah();
int hapus();

int main() {
    unsigned long int nim = 2309106132;
    string nama = "Alvito";

    fungsi_login(nim, nama);

    if (status == 1) {
        menu();
    } else {
        cout << "Program Berhenti" << endl;
        cout << endl;
    }

    return 0;
}

int fungsi_login(unsigned long int nim, string nama) {
    unsigned long int nim_login;
    string nama_login;
    int ulang = 0;

    while (ulang < 3) {
        cout << "+-----------------------------------------+" << endl;
        cout << "|        DAFTAR SIRKUIT FORMULA 1         |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "|  SILAHKAN LOGIN MENGGUNAKAN NAMA & NIM  |" << endl;
        cout << "+-----------------------------------------+" << endl;

        cout << "Masukkan Nama: ";
        cin >> nama_login;
        cout << "Masukkan NIM: ";
        cin >> nim_login;
        cout << endl;

        if (nama == nama_login && nim == nim_login) {
            cout << "Login Berhasil" << endl;
            cout << endl;
            status = 1;
            ulang = 4;
        } else {
            cout << "Nama atau Nim salah silahkan coba lagi" << endl;
            cout << endl;
            ulang += 1;
        }
        if (ulang == 3) {
            cout << "Anda telah salah 3x" << endl;
            status = 2;
        }
    }
    return status;
}

void menu() {
    int pilihan;

    cout << "+-----------------------------------------+" << endl;
    cout << "|        DAFTAR SIRKUIT FORMULA 1         |" << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "|1| TAMPILKAN SIRKUIT                     |" << endl;
    cout << "|2| TAMBAHKAN SIRKUIT                     |" << endl;
    cout << "|3| UBAH SIRKUIT                          |" << endl;
    cout << "|4| HAPUS SIRKUIT                         |" << endl;
    cout << "|5| EXIT                                  |" << endl;
    cout << "+-----------------------------------------+" << endl;

    cout << "Pilihan: ";
    cin >> pilihan;
    cout << endl;

    switch (pilihan) {
        case 1:
            tampilkan();
            menu();
            break;
        case 2:
            tambah();
            menu();
            break;
        case 3:
            ubah();
            menu();
            break;
        case 4:
            hapus();
            menu();
            break;
        case 5:
            break;

        default:
            cout << "Pilihan tidak valid" << endl;
            menu();
    }
}

void tampilkan() {
    if (banyak_sirkuit == 0) {
        cout << "Daftar kosong" << endl;
    } else {
        for (int i = 0; i < banyak_sirkuit; i++)
            cout << i + 1 << ". " << daftar_sirkuit[i] << endl;
    }
    cout << endl;
}

void tambah() {
    if (banyak_sirkuit >= 10) {
        cout << "Sirkuit sudah penuh" << endl;
        cout << endl;
    } else {
        cout << "Masukkan nama sirkuit : ";
        cin >> daftar_sirkuit[banyak_sirkuit];
        cout << endl;
        banyak_sirkuit++;
    }
}

int ubah()
{
    tampilkan();
    cout << endl;
    cout << "Pilih sirkuit yang ingin diubah: ";
    cin >> nomor;
    cout << "Masukkan nama sirkuit baru: ";
    cin >> sirkuit;
    daftar_sirkuit[nomor - 1] = sirkuit;
    cout << endl;
    return 0;
}

int hapus()
{
    tampilkan();
    cout << endl;
    cout << "Pilih sirkuit yang ingin dihapus: "; cin >> nomor;
    cout << endl;
    if (nomor >= 1 && nomor <= banyak_sirkuit)
    {
        for (int i = nomor-1; i < banyak_sirkuit - 1; i++)
        {
            daftar_sirkuit[i] = daftar_sirkuit[i + 1];
        }
        banyak_sirkuit--;
        cout << "Sirkuit berhasil dihapus." << endl;
    }
    else
    {
        cout << "Input tidak valid. Pilih nomor sirkuit yang sesuai." << endl;
    }
    cout << endl;
    return 0;
}
