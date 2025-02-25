#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de ejecucion (Insertion Sort): " << duration.count() << " microsegundos" << endl;

    delete[] arr; 
    return 0;
}
