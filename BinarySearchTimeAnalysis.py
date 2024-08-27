import time
import random
import pandas as pd
import matplotlib.pyplot as plt


def bubble_sort(arr):

    n = len(arr)
    for i in range(n):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def binary_search(array, value):

    low = 0
    high = len(array) - 1

    while low <= high:
        mid = (low + high) // 2
        if array[mid] == value:
            return mid
        elif value < array[mid]:
            high = mid - 1
        else:
            low = mid + 1

    return -1  # Value not found


def main():
    num_experiments = int(input("Enter the number of experiments: "))
    storage = []
    storage2 = []

    for _ in range(num_experiments):
        array_size = int(input("Enter the array size: "))

        # Create an empty list to store random values
        arr = []

        for _ in range(array_size):
            random_value = random.randint(1, 100)  # Adjust the range as needed
            arr.append(random_value)
        print("Array elements:", arr)
        value = int(input("Enter the value to search: "))
        start_time = time.perf_counter()


        index = binary_search(arr, value)

        end_time = time.perf_counter()
        elapsed_time = end_time - start_time




        print(f"Elapsed time: {elapsed_time} seconds")
        storage.append(elapsed_time)
        storage2.append(len(arr))
    print("\nArray sizes:")
    for array_size in storage2:
        print(array_size)

    # Plot the graph
    plt.plot(storage2, storage, marker='o')
    plt.xlabel("Number of Elements")
    plt.ylabel("Elapsed Time (seconds)")
    plt.title("Time Complexity of Binary Search with Bubble Sort")
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
    main()