#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> stringToVec(const string& s) {
    return vector<char>(s.begin(), s.end());
}

void cetakVektor(const string& label, const vector<char>& v) {
    cout << label << ": ";
    for (char c : v) cout << c;
    cout << endl;
}

void tampilkanHasil(const string& judulAlgo,
                    const vector<char>& sebelum,
                    const vector<char>& sesudah) {
    cout << "\n========================================" << endl;
    cout << "  " << judulAlgo << endl;
    cout << "========================================" << endl;
    cetakVektor("Sebelum Diurutkan", sebelum);
    cetakVektor("Setelah Diurutkan", sesudah);
    cout << "========================================\n" << endl;
}

void insertionSort(vector<char>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        char kunci = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;
    }
}

void merge(vector<char>& arr, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    vector<char> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++) R[j] = arr[tengah + 1 + j];
    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<char>& arr, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}

void shellSort(vector<char>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int partisi(vector<char>& arr, int rendah, int tinggi) {
    char pivot = arr[tinggi];
    int i = rendah - 1;
    for (int j = rendah; j < tinggi; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[tinggi]);
    return i + 1;
}

void quickSort(vector<char>& arr, int rendah, int tinggi) {
    if (rendah < tinggi) {
        int pi = partisi(arr, rendah, tinggi);
        quickSort(arr, rendah, pi - 1);
        quickSort(arr, pi + 1, tinggi);
    }
}

void bubbleSort(vector<char>& arr) {
    int n = arr.size();
    bool adaPertukaran;
    for (int i = 0; i < n - 1; i++) {
        adaPertukaran = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                adaPertukaran = true;
            }
        }
        if (!adaPertukaran) break;
    }
}

void selectionSort(vector<char>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int idxMin = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[idxMin]) idxMin = j;
        }
        if (idxMin != i) swap(arr[i], arr[idxMin]);
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n========================================" << endl;
        cout << "              S O R T I N G            " << endl;
        cout << "========================================" << endl;
        cout << " 1. Insertion Sort" << endl;
        cout << " 2. Merge Sort" << endl;
        cout << " 3. Shell Sort" << endl;
        cout << " 4. Quick Sort" << endl;
        cout << " 5. Bubble Sort" << endl;
        cout << " 6. Selection Sort" << endl;
        cout << " 7. Exit" << endl;
        cout << "========================================" << endl;
        cout << " Masukkan Pilihan : ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            string nama;
            cout << "\n Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);

            vector<char> dataNama    = stringToVec(nama);
            vector<char> sebelumNama = dataNama;

            switch (pilihan) {
                case 1:
                    insertionSort(dataNama);
                    tampilkanHasil("INSERTION SORT (Nama)", sebelumNama, dataNama);
                    break;
                case 2:
                    mergeSort(dataNama, 0, (int)dataNama.size() - 1);
                    tampilkanHasil("MERGE SORT (Nama)", sebelumNama, dataNama);
                    break;
                case 3:
                    shellSort(dataNama);
                    tampilkanHasil("SHELL SORT (Nama)", sebelumNama, dataNama);
                    break;
            }

        } else if (pilihan >= 4 && pilihan <= 6) {
            string nim;
            cout << "\n Masukkan NIM  : ";
            cin >> nim;

            vector<char> dataNIM    = stringToVec(nim);
            vector<char> sebelumNIM = dataNIM;

            switch (pilihan) {
                case 4:
                    quickSort(dataNIM, 0, (int)dataNIM.size() - 1);
                    tampilkanHasil("QUICK SORT (NIM)", sebelumNIM, dataNIM);
                    break;
                case 5:
                    bubbleSort(dataNIM);
                    tampilkanHasil("BUBBLE SORT (NIM)", sebelumNIM, dataNIM);
                    break;
                case 6:
                    selectionSort(dataNIM);
                    tampilkanHasil("SELECTION SORT (NIM)", sebelumNIM, dataNIM);
                    break;
            }

        } else if (pilihan == 7) {
            cout << "\n Terima kasih! Program selesai.\n" << endl;
        } else {
            cout << "\n [!] Pilihan tidak valid. Silakan masukkan angka 1-7.\n" << endl;
        }

    } while (pilihan != 7);

    return 0;
}