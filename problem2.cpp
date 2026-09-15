#include <iostream>
using namespace std;

int hitungPanjang(const char str[]) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

int dapatkanNilaiAlfabet(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    return 0;
}

char geserHuruf(char c, int nilaiGeser) {
    if (c >= 'A' && c <= 'Z') {
        int posisiBaru = (c - 'A' + nilaiGeser) % 26;
        return 'A' + posisiBaru;
    } else if (c >= 'a' && c <= 'z') {
        int posisiBaru = (c - 'a' + nilaiGeser) % 26;
        return 'a' + posisiBaru;
    }
    return c;
}

int main() {
    char pesan[1000];
    char hasil[1000];

    cout << "Masukkan pesan: ";
    cin.getline(pesan, 1000);

    int panjang = hitungPanjang(pesan);

    if (panjang == 0) {
        return 0;
    }

    hasil[0] = pesan[0];

    for (int i = 1; i < panjang; i++) {
        int nilaiGeser = dapatkanNilaiAlfabet(pesan[i - 1]);
        hasil[i] = geserHuruf(pesan[i], nilaiGeser);
    }

    hasil[panjang] = '\0';

    cout << "Hasil Enkripsi Pesan: " << hasil << endl;

    return 0;
}
