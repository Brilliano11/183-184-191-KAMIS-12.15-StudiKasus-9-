#include <iostream>
#include <iomanip>
using namespace std;

class Siswa {
public:
    char nim[20];
    float nilai1;
    float nilai2; 
    float nilai3;
    float rataRata;
    
    void hitungRataRata() {
        rataRata = (nilai1 + nilai2 + nilai3) / 3;
    }
};

void tampilkanMenu() {
    cout << "=========MENU======" << endl;
    cout << "1. Input Nilai Siswa           " << endl;
    cout << "2. Tampilkan Tabel Nilai       " << endl;
    cout << "3. Sorting Rata-rata Ascending " << endl;
    cout << "4. Sorting Rata-rata Descending" << endl;
    cout << "5. Keluar                      " << endl;
    cout << "Masukkan Pilihan : ";
}

void inputNilai(Siswa siswa[], int &jumlah) {
    
    for (int i = 0; i < jumlah; i++) {
    	cout << "siswa"<<i+1 <<":"<<endl;
        cout << "Masukkan NIM " <<  " : ";
        cin >> siswa[i].nim;
        cout << "Input Nilai mapel 1 : ";
        cin >> siswa[i].nilai1;
        cout << "Input Nilai mapel 2 : ";
        cin >> siswa[i].nilai2;
        cout << "Input Nilai mapel 3 : ";
        cin >> siswa[i].nilai3;
       
        
        siswa[i].hitungRataRata();
    }
    
    cout << "  NILAI SISWA BERHASIL DIINPUT      " << endl;

}

void tampilkanTabel(Siswa siswa[], int jumlah) {

    cout << "\n+==============================================================+" << endl;
    cout << "| No |    NIM     |   M1   |   M2   |   M3   |   Rata-rata   |" << endl;
    cout << "+----+------------+--------+--------+--------+---------------+" << endl;
    
    for (int i = 0; i < jumlah; i++) {
        cout << "| " << setw(2) << (i+1) << " | " 
             << setw(10) << siswa[i].nim << " | "
             << setw(6) << fixed << setprecision(1) << siswa[i].nilai1 << " | "
             << setw(6) << fixed << setprecision(1) << siswa[i].nilai2 << " | "
             << setw(6) << fixed << setprecision(1) << siswa[i].nilai3 << " | "
             << setw(13) << fixed << setprecision(6) << siswa[i].rataRata << " |" << endl;
    }
    cout << "+----+------------+---------+--------+--------+--------------+" << endl;
    
    float totalRataRata = 0;
    for (int i = 0; i < jumlah; i++) {
        totalRataRata += siswa[i].rataRata;
    }
    
    
}

void bubbleSortAscending(Siswa siswa[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (siswa[j].rataRata > siswa[j + 1].rataRata) {
                Siswa temp = siswa[j];
                siswa[j] = siswa[j + 1];
                siswa[j + 1] = temp;
            }
        }
    }
    cout << "Data berhasil diurutkan secara Ascending (terendah ke tertinggi)! " << endl;
}

void bubbleSortDescending(Siswa siswa[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (siswa[j].rataRata < siswa[j + 1].rataRata) {
                Siswa temp = siswa[j];
                siswa[j] = siswa[j + 1];
                siswa[j + 1] = temp;
            }
        }
    }
    cout << "Data berhasil diurutkan secara Descending (tertinggi ke terendah)" << endl;
}

int main() {
    int jumlahSiswa;
    cout << "Masukkan jumlah Siswa : ";
    cin >> jumlahSiswa;
    
    Siswa siswa[jumlahSiswa];
    int pilihan;
    bool dataInputted = false;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                inputNilai(siswa, jumlahSiswa);
                dataInputted = true;
                break;
            case 2:
                if (dataInputted) {
                    tampilkanTabel(siswa, jumlahSiswa);
                } else {
                    cout << "Belum ada data! Silakan input nilai terlebih dahulu. " << endl;
                }
                break;
            case 3:
                if (dataInputted) {
                    bubbleSortAscending(siswa, jumlahSiswa);
                    tampilkanTabel(siswa, jumlahSiswa);
                } else {
                    cout << "Belum ada data! Silakan input nilai terlebih dahulu. " << endl;
                }
                break;
            case 4:
                if (dataInputted) {
                    bubbleSortDescending(siswa, jumlahSiswa);
                    tampilkanTabel(siswa, jumlahSiswa);
                } else {
                    cout << "Belum ada data! Silakan input nilai terlebih dahulu. " << endl;
                }
                break;
            case 5:
                cout << "Terima Kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    
    return 0;
}
