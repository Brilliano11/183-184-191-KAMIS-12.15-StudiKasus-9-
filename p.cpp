#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {

    string nim;
    float nilai[3];
    float rataRata;
    
    void hitungRataRata() {
        rataRata = (nilai[0] + nilai[1] + nilai[2]) / 3;
    }
};

void tampilkanMenu() {
    cout << "===== MENU =====\n";
    cout << "1. Input Nilai Siswa\n";
    cout << "2. Tampilkan Tabel Nilai dan Rata-rata\n";
    cout << "3. Sorting Rata-rata (Ascending)\n";
    cout << "4. Sorting Rata-rata (Descending)\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

void inputNilai(Mahasiswa mahasiswa[], int &jumlah) {
    cout << "Masukkan jumlah mahasiswa : ";
    cin >> jumlah;
    cout << "Masukkan nilai untuk " << jumlah << " siswa (3 mata pelajaran):\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Siswa " << (i + 1) << ":\n";
        cout << "Nim " << (i + 1) << " : ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai mapel 1: ";
        cin >> mahasiswa[i].nilai[0];
        cout << "Nilai mapel 2: ";
        cin >> mahasiswa[i].nilai[1];
        cout << "Nilai mapel 3: ";
        cin >> mahasiswa[i].nilai[2];
        mahasiswa[i].hitungRataRata();
    }
}

void tampilkanTabel(Mahasiswa mahasiswa[], int jumlah) {
    cout << "+-------------------------------------+\n";
    cout << "| Siswa | Nim | M1  | M2  | M3 | Rata |\n";
    cout << "+-------------------------------------+\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "| " << setw(5) << (i + 1) << " | " << setw(3) << mahasiswa[i].nim 
             << " | " << setw(3) << (int)mahasiswa[i].nilai[0] 
             << " | " << setw(3) << (int)mahasiswa[i].nilai[1] 
             << " | " << setw(2) << (int)mahasiswa[i].nilai[2] 
             << " | " << setw(4) << mahasiswa[i].rataRata << " |\n";
    }
    cout << "+-------------------------------------+\n";
}

void sortingAscending(Mahasiswa mahasiswa[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (mahasiswa[i].rataRata > mahasiswa[j].rataRata) {
                Mahasiswa temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }

    cout << "Rata-rata siswa (Ascending): ";
    for (int i = 0; i < jumlah; i++) {
        cout << mahasiswa[i].rataRata;
        if (i < jumlah - 1) cout << " | ";
    }
    cout << " |\n";
}

void sortingDescending(Mahasiswa mahasiswa[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (mahasiswa[i].rataRata < mahasiswa[j].rataRata) {
                Mahasiswa temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }

    cout << "Rata-rata siswa (Descending): ";
    for (int i = 0; i < jumlah; i++) {
        cout << mahasiswa[i].rataRata;
        if (i < jumlah - 1) cout << " | ";
    }
    cout << " |\n";
}

int main() {
    const int MAX_MAHASISWA = 100;
    Mahasiswa mahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa = 0;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputNilai(mahasiswa, jumlahMahasiswa);
                break;
            case 2:
                tampilkanTabel(mahasiswa, jumlahMahasiswa);
                break;
            case 3:
                sortingAscending(mahasiswa, jumlahMahasiswa);
                break;
            case 4:
                sortingDescending(mahasiswa, jumlahMahasiswa);
                break;
            case 5:
                cout << "Terima Kasih\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    
    return 0;
}
