#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
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
    selectionSort(arr, n);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de ejecucion (Selection Sort): " << duration.count() << " microsegundos" << endl;

    delete[] arr;
    return 0;
}
