#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de ejecucion (Quick Sort): " << duration.count() << " microsegundos" << endl;

    delete[] arr;
    return 0;
}
