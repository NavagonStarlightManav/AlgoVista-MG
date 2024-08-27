import time
import numpy as np
import matplotlib.pyplot as plt


def binary_search(array, value):
    low = 0
    high = len(array) - 1

    while low <= high:
        mid = (low + high) // 2
        if array[mid] == value:
            return mid
        elif array[mid] < value:
            low = mid + 1
        else:
            high = mid - 1
    return -1


def main():
    m2 = int(input("Please enter how many times you want to perform the experiment: "))

    storage2 = []
    storage = []

    for option in range(m2):
        m1 = int(input("Please enter the number of elements you want in the array: "))

        array1 = np.random.randint(0, 100000, size=m1)

        print(f"Array: {array1}")

        value = int(input("Please enter the value to be checked in the array: "))

        start_time = time.time()

        array1.sort()  # Using Python's built-in sort function

        index = binary_search(array1, value)

        end_time = time.time()

        elapsed = end_time - start_time
        print(f"Value is present at index {index}" if index != -1 else "Value is not present in the array")
        print(f"Elapsed time: {elapsed:.6f} seconds")

        storage.append(elapsed)
        storage2.append(m1)

    # Plotting the results
    plt.figure(figsize=(10, 6))
    plt.plot(storage2, storage, marker='o', linestyle='-', color='b')
    plt.xlabel('Number of Elements')
    plt.ylabel('Elapsed Time (seconds)')
    plt.title('Elapsed Time vs Number of Elements')
    plt.grid(True)
    plt.show()


if __name__ == "__main__":
    main()
