#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

using namespace std;

//g++ prac2.cpp -o prac2 -fopenmp

class ParallelSorting {
public:
    static void parallelBubbleSort(vector<int>& arr) {
        int n = arr.size();
        bool swapped;
        do {
            swapped = false;
            #pragma omp parallel for shared(arr, swapped)
            for (int i = 1; i < n; i++) {
                if (arr[i - 1] > arr[i]) {
                    swap(arr[i - 1], arr[i]);
                    swapped = true;
                }
            }
        } while (swapped);
    }

    static void parallelMergeSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            #pragma omp parallel sections
            {
                #pragma omp section
                parallelMergeSort(arr, low, mid);
                #pragma omp section
                parallelMergeSort(arr, mid + 1, high);
            }
            merge(arr, low, mid, high);
        }
    }

    static void merge(vector<int>& arr, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> left(n1), right(n2);

        for (int i = 0; i < n1; i++) {
            left[i] = arr[low + i];
        }
        for (int j = 0; j < n2; j++) {
            right[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < n1) {
            arr[k++] = left[i++];
        }

        while (j < n2) {
            arr[k++] = right[j++];
        }
    }
};

int main() {
    const int size = 10000; // Change array size as needed
    vector<int> arr(size);
    generate(arr.begin(), arr.end(), []() { return rand(); });

    // Sequential Bubble Sort
    vector<int> arr1 = arr;
    double start = omp_get_wtime();
    sort(arr1.begin(), arr1.end());
    double end = omp_get_wtime();
    cout << "Sequential Bubble Sort: " << (end - start) * 1000 << " ms" << endl;

    // Parallel Bubble Sort
    vector<int> arr2 = arr;
    start = omp_get_wtime();
    ParallelSorting::parallelBubbleSort(arr2);
    end = omp_get_wtime();
    cout << "Parallel Bubble Sort: " << (end - start) * 1000 << " ms" << endl;

    // Sequential Merge Sort
    vector<int> arr3 = arr;
    start = omp_get_wtime();
    sort(arr3.begin(), arr3.end());
    end = omp_get_wtime();
    cout << "Sequential Merge Sort: " << (end - start) * 1000 << " ms" << endl;

    // Parallel Merge Sort
    vector<int> arr4 = arr;
    start = omp_get_wtime();
    ParallelSorting::parallelMergeSort(arr4, 0, arr4.size() - 1);
    end = omp_get_wtime();
    cout << "Parallel Merge Sort: " << (end - start) * 1000 << " ms" << endl;

    return 0;
}
