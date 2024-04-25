import numpy as np
import multiprocessing


def parallel_reduction(arr, operation):
    with multiprocessing.Pool() as pool:
        return operation(pool.map(operation, arr))


if __name__ == "__main__":
    arr = [3, 7, 2, 8, 1, 6, 4, 5]

    min_value = min(arr)
    max_value = max(arr)
    sum_value = sum(arr)
    average = sum(arr) / len(arr)

    print("Min:", min_value)
    print("Max:", max_value)
    print("Sum:", sum_value)
    print("Average:", average)
