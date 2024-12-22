#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Задание 1: Сумма, среднее, минимум и максимум
void task1(int arr[][3], int rows, int cols) {
    int sum = 0, min = arr[0][0], max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
            if (arr[i][j] < min) min = arr[i][j];
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    double avg = (double)sum / (rows * cols);
    cout << "Сумма: " << sum << ", Среднее: " << avg << ", Минимум: " << min << ", Максимум: " << max << endl;
}

// Задание 2: Суммы по строкам и столбцам
void task2(int arr[][4], int rows, int cols) {
    int totalSum = 0;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " \t";
            rowSum += arr[i][j];
        }
        totalSum += rowSum;
        cout << "| " << rowSum << endl;
    }
    cout << "------------------------\n";
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        cout << colSum << " \t";
    }
    cout << "| " << totalSum << endl;
}

// Задание 3: Заполнение массивов
void task3() {
    int arr1[5][10], arr2[5][5];
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            arr1[i][j] = rand() % 51;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr2[i][j] = arr1[i][j * 2] + arr1[i][j * 2 + 1];
        }
    }
    cout << "Массив 1:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nМассив 2:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}

// Задание 4: Сортировка вставками
void task4(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Задание 5: Успеваемость
void task5() {
    int marks[10];
    cout << "Введите 10 оценок: ";
    for (int i = 0; i < 10; i++) {
        cin >> marks[i];
    }
    while (true) {
        cout << "Меню: 1. Показать оценки 2. Пересдать экзамен 3. Проверить стипендию 4. Выйти\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            for (int i = 0; i < 10; i++) {
                cout << marks[i] << " ";
            }
            cout << endl;
        } else if (choice == 2) {
            int index, newMark;
            cout << "Введите номер оценки и новую оценку: ";
            cin >> index >> newMark;
            marks[index] = newMark;
        } else if (choice == 3) {
            double avg = 0;
            for (int i = 0; i < 10; i++) {
                avg += marks[i];
            }
            avg /= 10;
            if (avg >= 4.5) {
                cout << "Стипендия назначена!\n";
            } else {
                cout << "Стипендии нет.\n";
            }
        } else if (choice == 4) {
            break;
        }
    }
}

// Задание 6: Быстрая сортировка
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void task6(int arr[], int size) {
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Задание 7: Сложная сортировка
void task7(int arr[], int size) {
    double avg = 0;
    for (int i = 0; i < size; i++) {
        avg += arr[i];
    }
    avg /= size;
    int sortEnd = (avg > 0) ? (size * 2 / 3) : (size / 3);
    for (int i = 0; i < sortEnd - 1; i++) {
        for (int j = i + 1; j < sortEnd; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = sortEnd; i < size; i++) {
        cout << arr[size - (i - sortEnd) - 1] << " ";
    }
    cout << endl;
}

int main() {
    while (true) {
        cout << "Выберите задание (1-7) или 0 для выхода: ";
        int choice;
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) {
            int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
            task1(arr, 2, 3);
        } else if (choice == 2) {
            int arr[3][4] = {{3, 5, 6, 7}, {12, 1, 1, 1}, {0, 7, 12, 1}};
            task2(arr, 3, 4);
        } else if (choice == 3) {
            task3();
        } else if (choice == 4) {
            int arr[] = {5, 2, 9, 1, 5, 6};
            task4(arr, 6);
        } else if (choice == 5) {
            task5();
        } else if (choice == 6) {
            int arr[] = {10, 7, 8, 9, 1, 5};
            task6(arr, 6);
        } else if (choice == 7) {
            int arr[] = {10, -7, 8, -9, 1, 5, 3};
            task7(arr, 7);
        }
    }
    return 0;
}
