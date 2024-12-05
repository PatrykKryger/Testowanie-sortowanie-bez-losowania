#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>

// Template for sorting using pointers
template <typename T>
void sortWithPointers(T* arr, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Template for sorting using std::swap
template <typename T>
void sortWithSwap(T* arr, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Template for sorting using std::vector and std::sort
template <typename T>
void sortWithVector(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());
}

// Utility function to initialize arrays in descending order
template <typename T>
void initializeDescending(T* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        arr[i] = static_cast<T>(size - i);
    }
}

// Utility function to initialize vectors in descending order
template <typename T>
void initializeDescending(std::vector<T>& vec, size_t size) {
    vec.resize(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = static_cast<T>(size - i);
    }
}

int main() {
    const size_t size = 10000;

    // Arrays for int and float
    int intArr[size];
    float floatArr[size];

    // Vectors for int and float
    std::vector<int> intVec;
    std::vector<float> floatVec;

    // Table for results
    std::cout << std::left << std::setw(15) << "Type"
        << std::setw(20) << "Sort Method"
        << std::setw(15) << "Time (ms)" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    // Test sorting for int array with pointers
    initializeDescending(intArr, size);
    auto start = std::chrono::high_resolution_clock::now();
    sortWithPointers(intArr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::setw(15) << "int"
        << std::setw(20) << "Pointers"
        << std::setw(15) << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    // Test sorting for int array with swap
    initializeDescending(intArr, size);
    start = std::chrono::high_resolution_clock::now();
    sortWithSwap(intArr, size);
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::setw(15) << "int"
        << std::setw(20) << "Swap"
        << std::setw(15) << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    // Test sorting for int vector
    initializeDescending(intVec, size);
    start = std::chrono::high_resolution_clock::now();
    sortWithVector(intVec);
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::setw(15) << "int"
        << std::setw(20) << "Vector"
        << std::setw(15) << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    // Test sorting for float array with pointers
    initializeDescending(floatArr, size);
    start = std::chrono::high_resolution_clock::now();
    sortWithPointers(floatArr, size);
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::setw(15) << "float"
        << std::setw(20) << "Pointers"
        << std::setw(15) << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    // Test sorting for float array with swap
    initializeDescending(floatArr, size);
    start = std::chrono::high_resolution_clock::now();
    sortWithSwap(floatArr, size);
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::setw(15) << "float"
        << std::setw(20) << "Swap"
        << std::setw(15) << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    // Test sorting for float vector
    initializeDescending(floatVec, size);
    start = std::chrono::high_resolution_clock::now();
    sortWithVector(floatVec);
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::setw(15) << "float"
        << std::setw(20) << "Vector"
        << std::setw(15) << std::chrono::duration<double, std::milli>(end - start).count() << std::endl;

    return 0;
}
