#include <iostream>
#include <string.h>
using namespace std;

void enkripsi()
{
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout << "ketikan pesan : ";
    cin.ignore();
    getline(cin, plainteks);

    cout << "masukkan jumlah pergeseran (0-25) :";
    cin >> k;

    cipherteks = ""; //inisialisasi cipheteks dengan string kosong

    for (i = 0; i < plainteks.length(); i++)
    {
        c = plainteks[i];
        if (isalpha(c))
        {                     //hanya memproses alphabet saja
            c = toupper(c);   // ubah menjadi huruf kapital
            c = c - 65;       //kodekan huruf ke angka 0 s/d 25
            c = (c + k) % 26; // enkripsi dan geser sejauh k ke kanan
            c = c + 65;       // kodekan kembali ke huruf semula
        }
        cipherteks = cipherteks + c; //sambungkan ke cipherteks
    }
    cout << "Cipherteks :" << cipherteks << endl; // cetak cipherteks
}

void deskripsi()
{
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout << "ketikan cipherteks :";
    cin.ignore();
    getline(cin, cipherteks);
    cout << "Masukkan jumlah pergeseran (0 - 25) :";
    cin >> k;
    plainteks = ""; // inisialisasi plainteks dengan null string

    for (i = 0; i < cipherteks.length(); i++)
    {
        c = cipherteks[i];
        if (isalpha(c)) // hanya memproses alphabet
        {
            c = toupper(c); //ubah karakter ke huruf besar
            c = c - 65;     //kodekan huruf ke angka 0 s/d 25
            if (c - k < 0)  // kasus pembagian bilangan negatif
                c = 26 + (c - k);

            else

                c = (c - k) % 26;

            c = c + 65;     //kodekan kembali ke huruf semula
            c = tolower(c); // plainteks dinyatakan sebagai huruf kecil
        }
        plainteks = plainteks + c; //sambungkan ke plainteks
    }
    cout << "Plainteks :" << plainteks << endl; // cetak plainteks
}

main()
{
    int pil;
    bool stop;
    stop = false;

    while (!stop)
    {
        cout << "Menu :" << endl;
        cout << "1. Enkripsi " << endl;
        cout << "2. Deskripsi " << endl;
        cout << "3. Exit " << endl;
        cout << "Pilih menu :";
        cin >> pil;
        switch (pil)
        {
        case 1:
            enkripsi();
            break;
        case 2:
            deskripsi();
            break;
        case 3:
            stop = true;
            break;
        default:
            cout << "menu tidak ada" << endl;
            break;
        }
    }
}