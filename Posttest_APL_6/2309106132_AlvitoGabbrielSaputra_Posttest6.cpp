#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
using namespace std;

struct login {
    unsigned long int nim = 2309106132;
    string nama = "Alvito";
};

struct sirkuit {
    string daftar_sirkuit[10];
    string sirkuit;
    int daftar_NoP[10];
    int nomor_pembalap;
    int banyak_sirkuit = 0;
    int banyak_NomorP = 0;
    int nomor;
    int status;
    login masuk;
};

int fungsi_login(unsigned long int nim, string nama, sirkuit *data);
void menu(sirkuit *data);
void tampilSirkuit(sirkuit *data);
void tampilNoP(sirkuit *data);
void tambahSirkuit(sirkuit *data);
void tambahNomorP(sirkuit *data);
void ubahSirkuit(sirkuit *data, int *nomor);
void ubahNoP(sirkuit *data, int *nomor);
void hapusSirkuit(sirkuit *data, int *nomor);
void hapusNoP(sirkuit *data, int *nomor);
void sorting(sirkuit *data);
void bubbleSortNomorP(sirkuit *data);
void selectionSortDescending(sirkuit *data);
void insertionSortAscending(sirkuit *data);
void searching(sirkuit *data);
void binarySearchSirkuit(sirkuit *data);
void interpolationSearchNomorP(sirkuit *data);

int main() {
    sirkuit data;
    int status_login = fungsi_login(data.masuk.nim, data.masuk.nama, &data);

    if (status_login == 1) {
        menu(&data);
    } else {
        cout << "Program Berhenti" << endl;
    }
    return 0;
}

int fungsi_login(unsigned long int nim, string nama, sirkuit *data) {
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
        getline(cin, nama_login);
        cout << "Masukkan NIM: ";
        cin >> nim_login;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        if (nama == nama_login && nim == nim_login) {
            cout << "Login Berhasil" << endl << endl;
            data->status = 1;
            return data->status;
        } else {
            cout << "Nama atau Nim salah silahkan coba lagi" << endl << endl;
            ulang += 1;
        }
    }

    cout << "Anda telah salah 3x" << endl;
    data->status = 2;
    return data->status;
}

void menu(sirkuit *data) {
    int pilihan;

    while (true) {
        cout << "+-----------------------------------------+" << endl;
        cout << "|        DAFTAR SIRKUIT FORMULA 1         |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "|1| TAMBAHKAN SIRKUIT                     |" << endl;
        cout << "|2| TAMBAHKAN NOMOR PEMBALAP              |" << endl;
        cout << "|3| SEARCHING                             |" << endl;
        cout << "|4| SORTING                               |" << endl;
        cout << "|5| UBAH SIRKUIT                          |" << endl;
        cout << "|6| HAPUS SIRKUIT                         |" << endl;
        cout << "|7| UBAH NOMOR PEMBALAP                   |" << endl;
        cout << "|8| HAPUS NOMOR PEMBALAP                  |" << endl;
        cout << "|9| EXIT                                  |" << endl;
        cout << "+-----------------------------------------+" << endl;

        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (pilihan) {
        case 1:
            tambahSirkuit(data);
            break;
        case 2:
            tambahNomorP(data);
            break;
        case 3:
            searching(data);
            break;
        case 4:
            sorting(data);
            break;
        case 5:
            ubahSirkuit(data, &(data->nomor));
            break;
        case 6:
            hapusSirkuit(data, &(data->nomor));
            break;
        case 7:
            ubahNoP(data, &(data->nomor));
            break;
        case 8:
            hapusNoP(data, &(data->nomor));
            break;
        case 9:
            return;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    }
}

void tampilSirkuit(sirkuit *data) {
    if (data->banyak_sirkuit == 0) {
        cout << "Daftar kosong" << endl;
    } else {
        for (int i = 0; i < data->banyak_sirkuit; i++)
            cout << i + 1 << ". " << data->daftar_sirkuit[i] << endl;
    }
    cout << endl;
}

void tampilNoP(sirkuit *data){
    if (data->banyak_NomorP == 0){
        cout << "Daftar kosong" << endl;
    } else {
        for (int i = 0; i < data->banyak_NomorP; i++)
            cout << i + 1 << ". " << data->daftar_NoP[i] << endl;
    }
    cout << endl;
}

void tambahSirkuit(sirkuit *data) {
    if (data->banyak_sirkuit >= 10) {
        cout << "Sirkuit sudah penuh" << endl << endl;
    } else {
        cout << "Masukkan nama sirkuit : ";
        getline(cin, data->daftar_sirkuit[data->banyak_sirkuit]);
        cout << endl;
        data->banyak_sirkuit++;
    }
}

void tambahNomorP(sirkuit *data){
    if (data->banyak_NomorP >= 10){
        cout << "Nomor Pembalap sudah penuh" << endl << endl;
    } else {
        cout << "Masukkan Nomor Pembalap : ";
        cin >> data->daftar_NoP[data->banyak_NomorP];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        data->banyak_NomorP++;
    }
}

void ubahSirkuit(sirkuit *data, int *nomor) {
    tampilSirkuit(data);

    if (data->banyak_sirkuit == 0){
        cout << "Tidak ada sirkuit yang bisa diubah" << endl << endl;
    } else {
        cout << "Pilih sirkuit yang ingin diubah: ";
        cin >> *nomor;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        if (*nomor < 1 || *nomor > data->banyak_sirkuit) {
            cout << "Pilihan tidak ada" << endl << endl;
        } else {
            cout << "Masukkan nama sirkuit baru: ";
            getline(cin, data->sirkuit);
            data->daftar_sirkuit[*nomor - 1] = data->sirkuit;
            cout << endl;
        }
    }
}

void ubahNoP (sirkuit *data, int *nomor){
    tampilNoP(data);

    if (data->banyak_NomorP == 0){
        cout << "Tidak ada nomor pembalap yang bisa diubah" << endl << endl;
    } else {
        cout << "Pilih nomor pembalap yang ingin diubah: ";
        cin >> *nomor;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        if (*nomor < 1 || *nomor > data->banyak_NomorP){
            cout << "Pilihan tidak ada" << endl << endl;
        } else {
            cout << "Masukkan nomor pembalap baru: ";
            cin >> data->daftar_NoP[*nomor - 1];
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
        }
    }
}

void hapusSirkuit(sirkuit *data, int *nomor) {
    tampilSirkuit(data);

    if (data->banyak_sirkuit == 0){
        cout << "Tidak ada sirkuit yang bisa dihapus" << endl << endl;
    } else {
        cout << "Pilih sirkuit yang ingin dihapus: ";
        cin >> *nomor;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        if (*nomor < 1 || *nomor > data->banyak_sirkuit) {
            cout << "Pilihan tidak ada" << endl << endl;
        } else {
            for (int i = *nomor - 1; i < data->banyak_sirkuit; i++) {
                data->daftar_sirkuit[i] = data->daftar_sirkuit[i + 1];
            }
            data->banyak_sirkuit--;
            cout << "Sirkuit berhasil dihapus." << endl << endl;
        }
    }
}

void hapusNoP(sirkuit *data, int *nomor){
    tampilNoP(data);

    if (data->banyak_NomorP == 0){
        cout << "Tidak ada nomor pembalap yang bisa dihapus" << endl << endl;
    } else {
        cout << "Pilih nomor pembalap yang ingin dihapus: ";
        cin >> *nomor;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        if (*nomor < 1 || *nomor > data->banyak_NomorP){
            cout << "Pilihan tidak ada" << endl << endl;
        } else {
            for (int i = *nomor - 1; i < data->banyak_NomorP; i++) {
                data->daftar_NoP[i] = data->daftar_NoP[i + 1];
            }
            data->banyak_NomorP--;
            cout << "Nomor Pembalap  berhasil dihapus." << endl << endl;
        }
    }
}

void sorting(sirkuit *data){
    int pilihan;

    while (true) {
        cout << "+-------------------------+" << endl;
        cout << "|      MENU SORTING       |" << endl;
        cout << "+-------------------------+" << endl;
        cout << "|1| SIRKUIT (A-Z)         |" << endl;
        cout << "|2| SIRKUIT (Z-A)         |" << endl;
        cout << "|3| NOMOR PEMBALAP (1-10) |" << endl;
        cout << "|4| EXIT                  |" << endl;
        cout << "+-------------------------+" << endl;
        cout << endl;

        cout << "PILIHAN ANDA: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (pilihan){
        case 1:
            insertionSortAscending(data);
            break;
        case 2:
            selectionSortDescending(data);
            break;
        case 3:
            bubbleSortNomorP(data);
            break;
        case 4:
            return;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    }
}

void searching(sirkuit *data){
    int pilihan;

    while (true) {
        cout << "+--------------------------+" << endl;
        cout << "|      MENU SEARCHING      |" << endl;
        cout << "+-------------------------+" << endl;
        cout << "|1| SIRKUIT                |" << endl;
        cout << "|2| NOMOR PEMBALAP         |" << endl;
        cout << "|3| EXIT                   |" << endl;
        cout << "+--------------------------+" << endl;
        cout << endl;

        cout << "PILIHAN ANDA: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (pilihan){
        case 1:
            binarySearchSirkuit(data);
            break;
        case 2:
            interpolationSearchNomorP(data);
            break;
        case 3:
            return;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    }
}

void bubbleSortNomorP(sirkuit *data) {
    int n = data->banyak_NomorP;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data->daftar_NoP[j] > data->daftar_NoP[j + 1]) {
                int temp = data->daftar_NoP[j];
                data->daftar_NoP[j] = data->daftar_NoP[j + 1];
                data->daftar_NoP[j + 1] = temp;
            }
        }
    }

    cout << "Hasil sorting nomor pembalap: " << endl;
    for (int i = 0; i < data->banyak_NomorP; i++){
        cout << i + 1 << ". " << data->daftar_NoP[i] << endl;
    }
    cout << endl;
}

void selectionSortDescending(sirkuit *data) {
    int n = data->banyak_sirkuit;

    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (data->daftar_sirkuit[j] > data->daftar_sirkuit[max_idx]) {
                max_idx = j;
            }
        }
        swap(data->daftar_sirkuit[max_idx], data->daftar_sirkuit[i]);
    }

    cout << "Hasil sorting nama sirkuit secara descending: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << data->daftar_sirkuit[i] << endl;
    }
    cout << endl;
}

void insertionSortAscending(sirkuit *data) {
    int n = data->banyak_sirkuit;

    for (int i = 1; i < n; i++) {
        string key = data->daftar_sirkuit[i];
        int j = i - 1;

        while (j >= 0 && data->daftar_sirkuit[j] > key) {
            data->daftar_sirkuit[j + 1] = data->daftar_sirkuit[j];
            j = j - 1;
        }
        data->daftar_sirkuit[j + 1] = key;
    }

    cout << "Hasil sorting nama sirkuit secara ascending: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << data->daftar_sirkuit[i] << endl;
    }
    cout << endl;
}

void binarySearchSirkuit(sirkuit *data) {
    selectionSortDescending(data);

    string cari_sirkuit;
    cout << "Masukkan nama sirkuit yang ingin dicari: ";
    getline(cin, cari_sirkuit);

    int kiri = 0;
    int kanan = data->banyak_sirkuit - 1;
    int ditemukan = -1;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if (data->daftar_sirkuit[tengah] == cari_sirkuit) {
            ditemukan = tengah;
            break;
        }
        if (data->daftar_sirkuit[tengah] > cari_sirkuit)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    if (ditemukan == -1)
        cout << "Sirkuit tidak ditemukan." << endl;
    else
        cout << "Sirkuit ditemukan pada indeks: " << ditemukan + 1 << endl;
    cout << endl;
}

void interpolationSearchNomorP(sirkuit *data) {
    bubbleSortNomorP(data);

    int n = data->banyak_NomorP;

    int key;
    cout << "Masukkan nomor pembalap yang ingin dicari: ";
    cin >> key;

    int low = 0;
    int high = n - 1;

    while (low <= high && key >= data->daftar_NoP[low] && key <= data->daftar_NoP[high]) {
        if (low == high) {
            if (data->daftar_NoP[low] == key) {
                cout << "Nomor pembalap " << key << " ditemukan pada indeks: " << low + 1 << endl;
                return;
            } else {
                cout << "Nomor pembalap " << key << " tidak ditemukan." << endl;
                return;
            }
        }
        double pos = low + (double)(high - low) / (data->daftar_NoP[high] - data->daftar_NoP[low]) * (key - data->daftar_NoP[low]);

        if (data->daftar_NoP[(int)pos] == key) {
            cout << "Nomor pembalap " << key << " ditemukan pada indeks: " << (int)pos + 1 << endl;
            return;
        }
        if (data->daftar_NoP[(int)pos] < key) {
            low = (int)pos + 1;
        } else {
            high = (int)pos - 1;
        }
    }
    cout << "Nomor pembalap " << key << " tidak ditemukan." << endl;
    cout << endl;
}