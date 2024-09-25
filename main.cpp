#include <iostream>
using namespace std;

/*int* allocateMemory(int size) {
    return new int[size];
}

void initializeArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void deleteArray(int* array) {
    delete[] array;
}

int* addElement(int* array, int& size, int element) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = element;
    size++;
    delete[] array;
    return newArray;
}

int* insertElement(int* array, int& size, int index, int element) {
    if (index < 0 || index > size) {
        cout << "Index out of bounds!" << endl;
        return array;
    }
    int* newArray = new int[size + 1];
    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i == index) {
            newArray[i] = element;
        }
        else {
            newArray[i] = array[j];
            j++;
        }
    }
    size++;
    delete[] array;
    return newArray;
}

int* deleteElement(int* array, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of bounds!" << endl;
        return array;
    }
    int* newArray = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newArray[j] = array[i];
            j++;
        }
    }
    size--;
    delete[] array;
    return newArray;
}

int main() {
    int size = 5;
    int* array = allocateMemory(size);

    initializeArray(array, size);
    cout << "Initialized array: ";
    printArray(array, size);

    array = addElement(array, size, 10);
    cout << "After adding element 10: ";
    printArray(array, size);

    array = insertElement(array, size, 2, 20);
    cout << "After inserting element 20 at index 2: ";
    printArray(array, size);

    array = deleteElement(array, size, 3);
    cout << "After deleting element at index 3: ";
    printArray(array, size);

    deleteArray(array);

    return 0;
}


 int isProste(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void removeProste(int*& array_, int& size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (!isProste(array_[i])) newSize++; // якщо не просте число - далі
    }

    int* newArray = new int[newSize];
    for (int i = 0, j = 0; i < size; i++) {
        if (!isProste(array_[i])) { // ++
            newArray[j++] = array_[i];
        }
    }

    size = newSize;
    delete[] array_;
    array_ = newArray;
}

int main() {
    int size = 20;
    int* array_ = new int[size] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    removeProste(array_, size);

    cout << "without prosti numbers: ";
    for (int i = 0; i < size; i++) {
        cout << array_[i] << " ";
    }
    cout << endl;

    delete[] array_;
    return 0;
 }*/



#include <iostream>
using namespace std;

void elements(int* arr, int size, int*& positives, int& posCount, int*& negatives, int& negCount, int*& zeros, int& zeroCount) {
    // підрахунок елементів
    posCount = negCount = zeroCount = 0; 
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) posCount++;
        else if (arr[i] < 0) negCount++;
        else zeroCount++;
    }

    positives = new int[posCount];
    negatives = new int[negCount];
    zeros = new int[zeroCount];
    // по різних масивах
    posCount = negCount = zeroCount = 0; 
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) positives[posCount++] = arr[i];
        else if (arr[i] < 0) negatives[negCount++] = arr[i];
        else zeros[zeroCount++] = arr[i];
    }
}

int main() {
    int arr[] = { 0, -1, 5, -3, 2, 0, -4, 7, 19, -5, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* positives, * negatives, * zeros;
    int posCount, negCount, zeroCount;

    elements(arr, size, positives, posCount, negatives, negCount, zeros, zeroCount);

    cout << "Positives: ";
    for (int i = 0; i < posCount; i++) cout << positives[i] << " ";
    cout << endl;

    cout << "Negatives: ";
    for (int i = 0; i < negCount; i++) cout << negatives[i] << " ";
    cout << endl;

    cout << "Zeros: ";
    for (int i = 0; i < zeroCount; i++) cout << zeros[i] << " ";
    cout << endl;

    delete[] positives;
    delete[] negatives;
    delete[] zeros;

    return 0;
}
