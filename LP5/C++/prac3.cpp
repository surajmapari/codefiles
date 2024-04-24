#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <omp.h>

using namespace std;

// Function to perform parallel reduction for finding minimum value
int parallel_min_reduction(vector<int>& arr) {
    int min_value = arr[0];
    #pragma omp parallel for reduction(min:min_value)
    for (int i = 1; i < arr.size(); ++i) {
        min_value = min(min_value, arr[i]);
    }
    return min_value;
}

// Function to perform parallel reduction for finding maximum value
int parallel_max_reduction(vector<int>& arr) {
    int max_value = arr[0];
    #pragma omp parallel for reduction(max:max_value)
    for (int i = 1; i < arr.size(); ++i) {
        max_value = max(max_value, arr[i]);
    }
    return max_value;
}

// Function to perform parallel reduction for finding sum
int parallel_sum_reduction(vector<int>& arr) {
    int sum_value = 0;
    #pragma omp parallel for reduction(+:sum_value)
    for (int i = 0; i < arr.size(); ++i) {
        sum_value += arr[i];
    }
    return sum_value;
}

// Function to perform parallel reduction for finding average
double parallel_average_reduction(vector<int>& arr) {
    int sum_value = parallel_sum_reduction(arr);
    return static_cast<double>(sum_value) / arr.size();
}

int main() {
    vector<int> arr = {3, 7, 2, 8, 1, 6, 4, 5};

    int min_value = parallel_min_reduction(arr);
    int max_value = parallel_max_reduction(arr);
    int sum_value = parallel_sum_reduction(arr);
    double average = parallel_average_reduction(arr);

    cout << "Min: " << min_value << endl;
    cout << "Max: " << max_value << endl;
    cout << "Sum: " << sum_value << endl;
    cout << "Average: " << average << endl;

    return 0;
}
