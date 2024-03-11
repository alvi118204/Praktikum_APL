# include <iostream>
using namespace std;


void fungsi_sirkuit()
{
    string daftar_sirkuit[10];
    string sirkuit;
    int pilihan, banyak_sirkuit = 0, index;

    while (true)
    {
        cout << "+-----------------------------------------+" << endl;
        cout << "|        DAFTAR SIRKUIT FORMULA 1         |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "|1| TAMPILKAN SIRKUIT                     |" << endl;
        cout << "|2| TAMBAHKAN SIRKUIT                     |" << endl;
        cout << "|3| UBAH SIRKUIT                          |" << endl;
        cout << "|4| HAPUS SIRKUIT                         |" << endl;
        cout << "|5| EXIT                                  |" << endl;
        cout << "+-----------------------------------------+" << endl;
        
        cout << "Pilihan: "; cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
            case 1 :
                if (banyak_sirkuit == 0)
                {
                    cout << "Daftar kosong" << endl;
                } 
                else 
                {
                    for (int i = 0; i < banyak_sirkuit; i++)
                    {
                        cout << i + 1 << ". " << daftar_sirkuit[i] << endl;
                    }
                }
                cout << endl;
                break;

            case 2 :
                if (banyak_sirkuit >= 10)
                {
                    cout << "Sirkuit sudah penuh" << endl;
                    cout << endl;
                }
                else
                {
                    cout << "Masukkan nama sirkuit : "; cin >> daftar_sirkuit[banyak_sirkuit];
                    cout << endl;
                    banyak_sirkuit++;
                }
                break;

            case 3 :
                for (int i = 0; i < banyak_sirkuit; i++)
                {
                    cout << i+1 << ". " << daftar_sirkuit[i] << endl;
                }
                cout << endl;
                cout << "Pilih sirkuit yang ingin diubah: "; cin >> index;
                cout << "Masukkan nama sirkuit baru: "; cin >> sirkuit;
                daftar_sirkuit[index-1] = sirkuit;
                cout << endl;
                break;

            case 4:
                for (int i = 0; i < banyak_sirkuit; i++)
                {
                    cout << i+1 << ". " << daftar_sirkuit[i] << endl;
                }
                cout << endl;
                cout << "Pilih sirkuit yang ingin dihapus: "; cin >> index;
                cout << endl;
                if (index >= 1 && index <= banyak_sirkuit)
                {
                    for (int i = index-1; i < banyak_sirkuit - 1; i++)
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
                break;

            case 5 :
                cout << "----------------" << endl;
                cout << "Program berhenti" << endl;
                return;

            default :
                break;

        }

    }
    




}

void fungsi_login(unsigned long int nim, string nama)
{
    int ulang = 0;
    unsigned long int nim_login;
    string nama_login;
    

    while (ulang < 3)
    {
        cout << "+-----------------------------------------+" << endl;
        cout << "|        DAFTAR SIRKUIT FORMULA 1         |" << endl;
        cout << "|-----------------------------------------|" << endl;
        cout << "|  SILAHKAN LOGIN MENGGUNAKAN NAMA & NIM  |" << endl;
        cout << "+-----------------------------------------+" << endl;

        cout << "Masukkan Nama: "; cin >> nama_login;
        cout << "Masukkan NIM: "; cin >> nim_login;

        if (nama_login == nama && nim_login == nim)
        {
            cout << "---------------" << endl;
            cout << "Login Berhasil" << endl;
            cout << endl;
            fungsi_sirkuit();
            ulang = 4;

        }
        else
        {
            cout << "--------------------------------" << endl;
            cout << "Nama & Nim yang dimasukkan salah" << endl;
            ulang += 1;
        }
        if (ulang == 3)
        {
            cout << "Anda Telah Salah Memasukkan NAMA atau NIM Sebanyak 3X" << endl;
            cout << "Program Berhenti" << endl;
            cout << "-----------------------------------------------------" << endl; 
        }

    }
}


int main ()
{
    unsigned long int nim =2309106132;
    string nama ="Alvito";
    fungsi_login(nim,nama);

    return 0;
}
