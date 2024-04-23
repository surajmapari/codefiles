#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <omp.h>

using namespace std;

template <typename T, typename Func>
T parallel_reduction(vector<T>& arr, Func operation) {
    T result = arr[0];
    #pragma omp parallel for reduction(operation: result)
    for (size_t i = 1; i < arr.size(); ++i) {
        result = operation(result, arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {3, 7, 2, 8, 1, 6, 4, 5};

    int min_value = parallel_reduction(arr, [](int a, int b) { return std::min(a, b); });
    int max_value = parallel_reduction(arr, [](int a, int b) { return std::max(a, b); });
    int sum_value = parallel_reduction(arr, [](int a, int b) { return a + b; });
    double average = static_cast<double>(parallel_reduction(arr, [](int a, int b) { return a + b; })) / arr.size();

    cout << "Min: " << min_value << endl;
    cout << "Max: " << max_value << endl;
    cout << "Sum: " << sum_value << endl;
    cout << "Average: " << average << endl;

    return 0;
}
