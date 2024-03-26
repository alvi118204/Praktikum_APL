#include <iostream>
using namespace std;

struct login {
    unsigned long int nim = 2309106132;
    string nama = "Alvito";
};

struct sirkuit {
    string daftar_sirkuit[10];
    string sirkuit;
    int banyak_sirkuit = 0;
    int nomor;
    int status;
    login masuk;
};

int fungsi_login(unsigned long int nim, string nama, sirkuit &data);
void menu(sirkuit &data);
void tampilkan(sirkuit &data);
void tambah(sirkuit &data);
void ubah(sirkuit &data);
void hapus(sirkuit &data);

int main() {
    sirkuit data;
    int status_login = fungsi_login(data.masuk.nim, data.masuk.nama, data);

    if (status_login == 1) {
        menu(data);
    } else {
        cout << "Program Berhenti" << endl;
    }
    return 0;
}

int fungsi_login(unsigned long int nim, string nama, sirkuit &data) {
    unsigned long int nim_login;
    string nama_login;
    int ulang = 0;

    while (ulang < 3) {
        cout << "+-----------------------------------------+" << endl;
        cout << "|        DAFTAR SIRKUIT FORMULA 1         |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "|  SILAHKAN LOGIN MENGGUNAKAN NAMA & NIM  |" << endl;
        cout << "+-----------------------------------------+" << endl;

        cout << "Masukkan Nama: "; fflush (stdin);
        getline(cin, nama_login); fflush(stdin);
        cout << "Masukkan NIM: "; fflush(stdin);
        cin >> nim_login; fflush(stdin);
        cout << endl;

        if (nama == nama_login && nim == nim_login) {
            cout << "Login Berhasil" << endl;
            cout << endl;
            data.status = 1;
            ulang = 4;
        } else {
            cout << "Nama atau Nim salah silahkan coba lagi" << endl;
            cout << endl;
            ulang += 1;
        }
        if (ulang == 3) {
            cout << "Anda telah salah 3x" << endl;
            data.status = 2;
        }
    }

    return data.status;
}

void menu(sirkuit &data) {
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

    cout << "Pilihan: ";fflush(stdin);
    cin >> pilihan; fflush(stdin);
    cout << endl;

    switch (pilihan) {
    case 1:
        tampilkan(data);
        menu(data);
        break;
    case 2:
        tambah(data);
        menu(data);
        break;
    case 3:
        ubah(data);
        menu(data);
        break;
    case 4:
        hapus(data);
        menu(data);
        break;
    case 5:
        break;

    default:
        cout << "Pilihan tidak valid" << endl;
        menu(data);
    }
}

void tampilkan(sirkuit &data) {
    if (data.banyak_sirkuit == 0) {
        cout << "Daftar kosong" << endl;
    } else {
        for (int i = 0; i < data.banyak_sirkuit; i++)
            cout << i + 1 << ". " << data.daftar_sirkuit[i] << endl;
    }
    cout << endl;
}

void tambah(sirkuit &data) {
    if (data.banyak_sirkuit >= 10) {
        cout << "Sirkuit sudah penuh" << endl;
        cout << endl;
    } else {
        cout << "Masukkan nama sirkuit : "; fflush(stdin);
        getline(cin, data.daftar_sirkuit[data.banyak_sirkuit]);fflush(stdin);
        cout << endl;
        data.banyak_sirkuit++;
    }
}

void ubah(sirkuit &data) {
    tampilkan(data);
    cout << endl;
    cout << "Pilih sirkuit yang ingin diubah: ";fflush(stdin);
    cin >> data.nomor;fflush(stdin);
    cout << endl;
    if (data.nomor < 1 || data.nomor > data.banyak_sirkuit) {
        cout << "Pilihan tidak ada" << endl;
        menu(data);
    }
    cout << "Masukkan nama sirkuit baru: ";fflush(stdin);
    getline(cin, data.sirkuit);fflush(stdin);
    data.daftar_sirkuit[data.nomor - 1] = data.sirkuit;
    cout << endl;
}

void hapus(sirkuit &data) {
    tampilkan(data);
    cout << endl;
    cout << "Pilih sirkuit yang ingin dihapus: ";fflush(stdin);
    cin >> data.nomor;fflush(stdin);
    cout << endl;
    if (data.nomor < 1 || data.nomor > data.banyak_sirkuit) {
        cout << "Pilihan tidak ada" << endl;
        menu(data);
    }
    if (data.nomor >= 1 && data.nomor <= data.banyak_sirkuit) {
        for (int i = data.nomor - 1; i < data.banyak_sirkuit - 1; i++) {
            data.daftar_sirkuit[i] = data.daftar_sirkuit[i + 1];
        }
        data.banyak_sirkuit--;
        cout << "Sirkuit berhasil dihapus." << endl;
    } else {
        cout << "Input tidak valid. Pilih nomor sirkuit yang sesuai." << endl;
    }
    cout << endl;
}
