#include <iostream>
using namespace std;

void hapusAstronot(int arr[], int &jumlah_elemen, int indeks) {
    for (int i = indeks; i < jumlah_elemen - 1; i++) {
        arr[i] = arr[i + 1];
    }
    jumlah_elemen--; 
}

int main() {
    int N, K;
    cout << "Masukkan N (jumlah astronot): ";
    cin >> N;
    while (N < 1) {
        cout << "N harus lebih besar atau sama dengan 1. Silakan masukkan ulang N: ";
        cin >> N;
    }
    if (N == 1) {
        cout << "The Last Astronaut: 1" << endl;
        return 0;
    }

    cout << "Masukkan K (jarak hitungan awal): ";
    cin >> K;
    while (K < 1) {
        cout << "K harus lebih besar dari 0. Silakan masukkan ulang K: ";
        cin >> K;
    }

    int list_astronot[1000];
    for (int i = 0; i < N; i++) {
        list_astronot[i] = i + 1;
    }

    int jumlah_elemen = N;
    int posisi_saat_ini = 0;
    int nomor_tereliminasi;

    while (jumlah_elemen > 1) {
        posisi_saat_ini = (posisi_saat_ini + K - 1) % jumlah_elemen;
        nomor_tereliminasi = list_astronot[posisi_saat_ini];

        cout << "Astronot yang di-kick: " << nomor_tereliminasi << endl;

        hapusAstronot(list_astronot, jumlah_elemen, posisi_saat_ini);

        if (nomor_tereliminasi % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }

        if (K < 2) {
            K = 2;
        }
    }

    cout << "The Last Astronaut: " << list_astronot[0] << endl;

    return 0;
}