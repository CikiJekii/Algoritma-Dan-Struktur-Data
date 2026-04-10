#include <iostream>

using namespace std;

struct plat {
    char nomor[10]  = "DA1234MK";
    char jenis[10]  = "RUSH";
    char nama[20]   = "Andika Hartanto";
    char alamat[30] = "Jl. Kayu Tangi 1";
    char kota[20]   = "Banjarmasin";
};

int main() {
    plat mobil;

    cout << "a. Plat Nomor Kendaraan : " << mobil.nomor << endl;
    cout << "b. Jenis Kendaraan      : " << mobil.jenis << endl;
    cout << "c. Nama Pemilik         : " << mobil.nama << endl;
    cout << "d. Alamat               : " << mobil.alamat << endl;
    cout << "e. Kota                 : " << mobil.kota << endl;

    return 0;
}