#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Ingresa el tamanio del arreglo: ";
    cin >> n;

    int* arr = new int[n]; 

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de ejecucion (Merge Sort): " << duration.count() << " microsegundos" << endl;

    delete[] arr;
    return 0;
}
