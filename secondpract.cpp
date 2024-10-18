#include <iostream>
#include <chrono>
const int SIZE_OF_ARR = 100;
using namespace std;

void bubbleSort(int* arr)
{
    int temp;
    cout << "\nОтсортированный массив: \n";
    for (int i = 0; i < SIZE_OF_ARR; i++)
    {
        for (int j = 0; j < SIZE_OF_ARR-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < SIZE_OF_ARR; i++)
        cout << arr[i] << " ";
}
void shakerSort(int* arr)
{
    bool swapped = true;
    int start = 0, end = SIZE_OF_ARR - 1;
    cout << "\nОтсортированный массив: \n";
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
    for (int i = 0; i < SIZE_OF_ARR; i++)
        cout << arr[i] << " ";
}
void combSort(int* arr)
{
    float k = 1.247;
    int count = 0, swap, S = SIZE_OF_ARR - 1;
    cout << "\nОтсортированный массив: \n";
    while (S >= 1)
    {
        for (int i = 0; i + S < SIZE_OF_ARR; i++)
        {
            if (arr[i] > arr[int(i + S)])
            {
                swap = arr[int(i + S)];
                arr[int(i + S)] = arr[i];
                arr[i] = swap;
            }
        }
        S /= k;
    }

    while (true)
    {
        for (int i = 0; i < SIZE_OF_ARR - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = swap;
            }
            else count++;
        }
        if (count == SIZE_OF_ARR - 1)
            break;
        else
            count = 0;
    }
    for (int i = 0; i < SIZE_OF_ARR; i++)
        cout << arr[i] << " ";
}
void insertSort(int* arr)
{
    int key, j;
    cout << "\nОтсортированный массив: \n";
    for (int i = 1; i < SIZE_OF_ARR; i++) {
        key = arr[i];
        j = i - 1;

        // Сдвигаем элементы массива, которые больше key, на одну позицию вперед
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < SIZE_OF_ARR; i++)
        cout << arr[i] << " ";
}
void quickSort(int* arr, int stop, int start)
{
    int f = start;
    int l = stop;
    int middle = arr[(l + f) / 2];
    while (f < l)
    {
        while (arr[f] < middle) f++;
        while (arr[l] > middle) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (l > start)
        quickSort(arr, l, start);
    if (f < stop) 
        quickSort(arr, stop, f);
}
void maxMinElement(int* arr)
{
    int max = 0;
    int min = 99999999;
    for (int i = 0; i < SIZE_OF_ARR; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    cout << "\nMax: " << max << " Min: " << min;
}
void midElement(int* arr)
{
    float max = 0;
    float min = 99999999;
    float mid;
    int k = 0;
    for (int i = 0; i < SIZE_OF_ARR; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    mid = (max + min) / 2;
    for (int i = 0; i < SIZE_OF_ARR; i++)
        if (arr[i] == mid)
        {
            k++;
            cout << i << " ";
        }
    cout << "\nСреднее значение: " << mid << "Количество элементов равных числу: " << k;
}
int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }

    return -1;
}
void searchInArray(int arr[], int value)
{
    for (int i = 0; i < SIZE_OF_ARR; i++)
        if (arr[i] == value)
        {
            cout << "\nНайден\n";
            break;
        }
}
int main()
{
    bool isSort = false;
    int arr[SIZE_OF_ARR];
    int typeOfSort;
    setlocale(0, "");
    cout << "\nВыберите сортировку: 1. Пузырьковая, 2. Шейкер, 3. Расчёска, 4. Вставки, 5. Быстрая, 6. Максимум и минимум, 7. Среднее значениие, 8. Элементы больше/меньше a/b, 9. Бинарный поиск, 10. Обычный поиск, 11. Свап, 12. Бинарный поиск, 0. Завершить работу\n";
    cin >> typeOfSort;
    cout << "\nИзначальный массив: \n";
    for (int i = 0; i < SIZE_OF_ARR; i++)
        arr[i] = rand() % (99 - (-99) + 1) + (-99);
    for (int i = 0; i < SIZE_OF_ARR; i++)
        cout << arr[i] << " ";
    while (typeOfSort)
    {
        switch (typeOfSort)
        {
        case 1:
        {
            auto begin = chrono::steady_clock::now();
            bubbleSort(arr);
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя: " << elapsed_ns.count() << " нс\n";
            isSort = true;
            break;
        }
        case 2:
        {
            auto begin = chrono::steady_clock::now();
            shakerSort(arr);
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя: " << elapsed_ns.count() << " нс\n";
            isSort = true;
            break;
        }
        case 3:
        {
            auto begin = chrono::steady_clock::now();
            combSort(arr);
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя: " << elapsed_ns.count() << " нс\n";
            isSort = true;
            break;
        }
        case 4:
        {
            auto begin = chrono::steady_clock::now();
            insertSort(arr);
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя: " << elapsed_ns.count() << " нс\n";
            isSort = true;
            break;
        }
        case 5:
        {
            auto begin = chrono::steady_clock::now();
            quickSort(arr, SIZE_OF_ARR - 1, 0);
            cout << "\nОтсортированный массив: \n";
            for (int i = 0; i < SIZE_OF_ARR; i++)
                cout << arr[i] << " ";
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя: " << elapsed_ns.count() << " нс\n";
            isSort = true;
            break;
        }
        case 6:
        {
            auto begin = chrono::steady_clock::now();
            maxMinElement(arr);
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя поиска максимума и минимума: " << elapsed_ns.count() << " нс\n";
            break;
        }
        case 7:
        {
            auto begin = chrono::steady_clock::now();
            midElement(arr);
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя: " << elapsed_ns.count() << " нс\n";
            break;
        }
        case 8:
        {
            if (isSort)
            {
                int k = 0, a = 0, i = 0, b = 0;
                cout << "\nВведите число a\n";
                cin >> a;
                while (arr[i] < a)
                {
                    k++;
                    i++;
                }
                cout << "Количество элементов меньше a: " << k;
                i = SIZE_OF_ARR - 1;
                k = 0;
                cout << "\nВведите число b\n";
                cin >> b;
                while (arr[i] > b)
                {
                    k++;
                    i--;
                }
                cout << "Количество элементов больше b: " << k;
            }
            else
                cout << "\nОтсортируйте массив";
            break;
        }
        case 9:
        {
            int result, y;
            cout << "\nВведите число: ";
            cin >> y;
            auto begin = chrono::steady_clock::now();
            result = binarySearch(arr, y, 0, SIZE_OF_ARR - 1);
            if (result == -1) {
                cout << "\nЭлемент не найден" << endl;
            }
            else {
                cout << "\nЭлемент находится в позиции " << result << endl;
            }
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя бинарного поиска: " << elapsed_ns.count() << " нс\n";
            break;
        }
        case 10:
        {
            int o;
            cout << "\nВведите число: ";
            cin >> o;
            auto begin = chrono::steady_clock::now();
            searchInArray(arr, o);
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя обычного поиска: " << elapsed_ns.count() << " нс\n";
            break;
        }
        case 11:
        {
            int a, b;
            cout << "\nВведите индексы:\n";
            cin >> a >> b;
            auto begin = chrono::steady_clock::now();
            swap(arr[a], arr[b]);
            auto end = chrono::steady_clock::now();
            auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << "\nВремя свапа: " << elapsed_ns.count() << " нс\n";
            for (int i = 0; i < SIZE_OF_ARR; i++)
                cout << arr[i] << " ";
            break;
        }
        case 12:
        {
            if (isSort)
            {
                auto begin = chrono::steady_clock::now();
                midElement(arr);
                auto end = chrono::steady_clock::now();
                auto elapsed_ns = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                cout << "\nВремя: " << elapsed_ns.count() << " нс\n";
            }
            else
                cout << "\nОтсортируйте массив\n";
            break;
        }
        }
        cout << "\nВыберите сортировку: 1. Пузырьковая, 2. Шейкер, 3. Расчёска, 4. Вставки, 5. Быстрая, 6. Максимум и минимум, 7. Среднее значениие, 8. Элементы больше/меньше a/b, 9. Бинарный поиск, 10. Обычный поиск, 11. Свап, 12. Бинарный поиск, 0. Завершить работу\n";
        cin >> typeOfSort;
    }
}
