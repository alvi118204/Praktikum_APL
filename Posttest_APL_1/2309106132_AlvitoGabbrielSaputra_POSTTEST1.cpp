#include <iostream>
using namespace std;


void menu_konversi_suhu()
{
    int ulang = 0;
    int suhu_awal,suhu_akhir;
    float nilai_suhu_awal,hasil;
    string lanjut;

    while (ulang == 0)
    {
        cout << "+-----------------------+" << endl;
        cout << "|    PILIH SUHU AWAL    |" << endl;
        cout << "+-----------------------+" << endl;
        cout << "|1| Celcius             |" << endl;
        cout << "|2| Reamur              |" << endl;
        cout << "|3| Fahrenheit          |" << endl;
        cout << "|4| Kelvin              |" << endl;
        cout << "+-----------------------+" << endl;

        cout << "Suhu Awal : ";
        cin >> suhu_awal;
        cout << "Besar Suhu Awal : ";
        cin >> nilai_suhu_awal;
        cout << endl;

        cout << "+-----------------------+" << endl;
        cout << "|    PILIH SUHU AKHIR   |" << endl;
        cout << "+-----------------------+" << endl;
        cout << "|1| Celcius             |" << endl;
        cout << "|2| Reamur              |" << endl;
        cout << "|3| Fahrenheit          |" << endl;
        cout << "|4| Kelvin              |" << endl;
        cout << "+-----------------------+" << endl;

        cout << "Suhu Akhir : ";
        cin>> suhu_akhir;
        cout << endl;

        // PERHITUNGAN CELCIUS
        if (suhu_awal == 1 && suhu_akhir == 1)
        {
            hasil = nilai_suhu_awal;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Celcius ke Celcius = " << hasil << " Celcius" << endl;
            cout << endl;
        }
        else if (suhu_awal == 1 && suhu_akhir == 2)
        {
            hasil = (nilai_suhu_awal*4)/5;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Celcius ke Reamur = " << hasil << " Reamur" << endl;
            cout << endl;
        }
        else if (suhu_awal == 1 && suhu_akhir == 3)
        {
            hasil = nilai_suhu_awal*9/5+32;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Celcius ke Fahrenheit = " << hasil << " Fahrenheit" << endl;
            cout << endl;
        }
        else if (suhu_awal == 1 && suhu_akhir == 4)
        {
            hasil = nilai_suhu_awal + 273.15;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Celcius ke Kelvin = " << hasil << " Kelvin" << endl;
            cout << endl;
        }
        // PERHITUNGAN REAMUR
        else if (suhu_awal == 2 && suhu_akhir == 1)
        {
            hasil = (nilai_suhu_awal*5)/4;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Reamur ke Celcius = " << hasil << " Celcius" << endl;
            cout << endl;
        }
        else if (suhu_awal == 2 && suhu_akhir == 2)
        {
            hasil = nilai_suhu_awal;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Reamur ke Reamur = " << hasil << " Reamur" << endl;
            cout << endl;
        }
        else if (suhu_awal == 2 && suhu_akhir == 3)
        {
            hasil = nilai_suhu_awal*9/4+32;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Reamur ke Fahrenheit = " << hasil << " Fahrenheit" << endl;
            cout << endl;
        }
        else if (suhu_awal == 2 && suhu_akhir == 4)
        {
            hasil = nilai_suhu_awal*5/4+273.15;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Reamur ke Kelvin = " << hasil << " Kelvin" << endl;
            cout << endl;
        }
        // PERHITUNGAN FAHRENHEIT
        else if (suhu_awal == 3 && suhu_akhir == 1)
        {
            hasil = (nilai_suhu_awal-32)*5/9;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Fahrenheit ke Celcius = " << hasil << " Celcius" << endl;
            cout << endl;
        }
        else if (suhu_awal == 3 && suhu_akhir == 2)
        {
            hasil = (nilai_suhu_awal-32)*4/9;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Fahrenheit ke Reamur = " << hasil << " Reamur" << endl;
            cout << endl;
        }
        else if (suhu_awal == 3 && suhu_akhir == 3)
        {
            hasil = nilai_suhu_awal;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Fahrenheit ke Fahrenheit = " << hasil << " Fahrenheit" << endl;
            cout << endl;
        }
        else if (suhu_awal == 3 && suhu_akhir == 4)
        {
            hasil = (nilai_suhu_awal-32)*5/9+273.15;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Fahrenheit ke Kelvin = " << hasil << " Kelvin" << endl;
            cout << endl;
        }
        // PERHITUNGAN KELVIN
        else if (suhu_awal == 4 && suhu_akhir == 1)
        {
            hasil = nilai_suhu_awal-273.15;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Kelvin ke Celcius = " << hasil << " Celcius" << endl;
            cout << endl;
        }
        else if (suhu_awal == 4 && suhu_akhir == 2)
        {
            hasil = (nilai_suhu_awal-273.15)*4/5;
            cout << "Hasil Konversi " << nilai_suhu_awal << " Kelvin ke Reamur = " << hasil << " Reamur" << endl;
            cout << endl;
        }
        else if (suhu_awal == 4 && suhu_akhir == 3)
        {
            hasil = (nilai_suhu_awal-273.15)*9/5+32;
            cout << "Hasil Konversi" << nilai_suhu_awal << " Kelvin ke Fahrenheit = " << hasil << " Fahrenheit" << endl;
            cout << endl;
        }
        else if (suhu_awal == 4 && suhu_akhir == 4)
        {
            hasil = nilai_suhu_awal;
            cout << "Hasil Konversi " << " Kelvin ke Kelvin = " << hasil << " Kelvin" << endl;
            cout << endl;
        }
        else 
        {
            cout << "Pilihan Tidak valid" << endl;
        }

        cout << "Apakah ingin melanjutkan Konversi (Ya/Tidak): ";
        cin >> lanjut;
        cout << endl;

        if (lanjut == "Ya")
        {
            ulang = 0;
        }
        else if (lanjut == "Tidak")
        {
            ulang = 1;

        }
    }
}

void menu_login(unsigned long int nim, string nama)
{
    int ulang = 0;
    while (ulang < 3)
    {
        string nama_inputan;
        unsigned long int nim_inputan;

        cout << "+------------------------+" << endl;
        cout << "|MASUKKAN NAMA & NIM ANDA|" << endl;
        cout << "+------------------------+" << endl;
        cout << "NAMA : ";
        cin >> nama_inputan;
        cout << "NIM : ";
        cin >> nim_inputan;
        cout << endl;

        if (nama_inputan == nama && nim_inputan == nim)
        {
            cout << "Login Berhasil" << endl;
            menu_konversi_suhu();
            ulang = 4;
            cout << "Program Berhenti" << endl;
        }
        else
        {
            cout << "Login Gagal" << endl;
            cout << "NAMA atau NIM yang Anda Masukkan Salah" << endl;
            ulang += 1;
        }
        if (ulang == 3)
        {
            cout << "-----------------------------------------------------" << endl;
            cout << "Anda Telah Salah Memasukkan NAMA atau NIM Sebanyak 3X" << endl;
            cout << "Program Berhenti" << endl;
            cout << "-----------------------------------------------------" << endl;
        }
    }
}


void menu_awal(unsigned long int nim, string nama)
{
    int ulang = 0;
    while (ulang == 0)
    {
        cout << "+---------------------------------------+" << endl;
        cout << "|SELAMAT DATANG DI PROGRAM KONVERSI SUHU|" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << "|1| Login                               |" << endl;
        cout << "|2| Exit                                |" << endl;
        cout << "+---------------------------------------+" << endl;

        int pilihan;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1)
        {
            menu_login(nim,nama);
            ulang = 1;
        }
        else if (pilihan == 2)
        {
            cout << "Program Berhenti" << endl;
            ulang = 1;
        }
        else
        {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}

int main()
{
    unsigned long int nim =2309106132;
    string nama ="Alvito";
    menu_awal(nim,nama);
    return 0;
}