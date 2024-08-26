import time
import pandas as pd
import matplotlib.pyplot as plt

def linear_search(arr, value):
    for i, element in enumerate(arr):
        if element == value:
            return i
    return -1

def main():
    num_experiments = int(input("Enter the number of experiments: "))
    storage = []
    storage2 = []

    for _ in range(num_experiments):
        array_size = int(input("Enter the array size: "))
        arr = [int(input(f"Enter element {i+1}: ")) for i in range(array_size)]
        value = int(input("Enter the value to search: "))

        start_time = time.perf_counter()
        index = linear_search(arr, value)
        end_time = time.perf_counter()

        elapsed_time = end_time - start_time

        if index != -1:
            print(f"Value found at index {index}")
        else:
            print("Value not found in the array")

        # Print elapsed time for each experiment within the loop
        print(f"Elapsed time: {elapsed_time} nano-seconds")

        storage.append(elapsed_time)
        storage2.append(array_size)

    print("\nArray sizes:")
    for array_size in storage2:
        print(array_size)

    # Plotting code
    plt.plot(storage2, storage, marker='o')
    plt.xlabel("Array Size")
    plt.ylabel("Elapsed Time (seconds)")
    plt.title("Linear Search Time vs. Array Size")
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()