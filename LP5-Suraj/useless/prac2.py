import random
import time
import threading


class ParallelSorting:
    
    @staticmethod
    def bubble_sort(arr):
        n = len(arr)
        for i in range(n):
            for j in range(0, n-i-1):
                if arr[j] > arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]
    
    @staticmethod
    def parallel_bubble_sort(arr):
        chunk_size = len(arr) // threading.active_count()
        chunks = [arr[i:i+chunk_size] for i in range(0, len(arr), chunk_size)]
        threads = []

        for chunk in chunks:
            thread = threading.Thread(target=ParallelSorting.bubble_sort, args=(chunk,))
            thread.start()
            threads.append(thread)

        for thread in threads:
            thread.join()

        # Merge sorted chunks
        sorted_arr = []
        for chunk in chunks:
            sorted_arr.extend(chunk)

        return sorted_arr

    @staticmethod
    def parallel_merge_sort(arr):
        if len(arr) > 1:
            mid = len(arr) // 2
            left = arr[:mid]
            right = arr[mid:]

            left_thread = threading.Thread(
                target=ParallelSorting.parallel_merge_sort, args=(left,))
            right_thread = threading.Thread(
                target=ParallelSorting.parallel_merge_sort, args=(right,))
            left_thread.start()
            right_thread.start()
            left_thread.join()
            right_thread.join()

            i = j = k = 0
            while i < len(left) and j < len(right):
                if left[i] < right[j]:
                    arr[k] = left[i]
                    i += 1
                else:
                    arr[k] = right[j]
                    j += 1
                k += 1

            while i < len(left):
                arr[k] = left[i]
                i += 1
                k += 1

            while j < len(right):
                arr[k] = right[j]
                j += 1
                k += 1


def main():
    size = 10000  # Change array size as needed
    arr = [random.randint(0, 1000) for _ in range(size)]

    # Sequential Bubble Sort
    arr1 = arr[:]
    start = time.time()
    arr1.sort()
    end = time.time()
    print("Sequential Bubble Sort:", (end - start) * 1000, "ms")

    # Parallel Bubble Sort
    arr2 = arr[:]
    start = time.time()
    ParallelSorting.parallel_bubble_sort(arr2)
    end = time.time()
    print("Parallel Bubble Sort:", (end - start) * 1000, "ms")

    # Sequential Merge Sort
    arr3 = arr[:]
    start = time.time()
    arr3.sort()
    end = time.time()
    print("Sequential Merge Sort:", (end - start) * 1000, "ms")

    # Parallel Merge Sort
    arr4 = arr[:]
    start = time.time()
    ParallelSorting.parallel_merge_sort(arr4)
    end = time.time()
    print("Parallel Merge Sort:", (end - start) * 1000, "ms")


if __name__ == "__main__":
    main()
