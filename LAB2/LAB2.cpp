#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;
//Палитра цветов 
namespace Color {
    // ANSI escape codes для изменения цвета текста
    const string RESET = "\033[0m"; //сброс
    const string RED = "\033[1m\033[31m"; //красный 
    const string GREEN = "\033[1m\033[32m";//зеленый
    const string YELLOW = "\033[1m\033[33m"; //желтый
    const string BLUE = "\033[1m\033[34m";//синий
    const string MAGENTA = "\033[1m\033[35m";// пурпурный
    const string CYAN = "\033[1m\033[36m";// голубой
    const string BLACK = "\033[1m\033[30m";// черный
    const string WHITE = "\033[1m\033[37m"; // белый

    void Red(const string& text) {
        cout << RED << text << RESET << endl;
    }
    void Green(const string& text) {
        cout << GREEN << text << RESET << endl;
    }
    void Yellow(const string& text) {
        cout << YELLOW << text << RESET << endl;
    }
    void Blue(const string& text) {
        cout << BLUE << text << RESET << endl;
    }
    void Magenta(const string& text) {
        cout << MAGENTA << text << RESET << endl;
    }
    void Cian(const string& text) {
        cout << CYAN << text << RESET << endl;
    }
    void Black(const string& text) {
        cout << BLACK << text << RESET << endl;
    }
    void White(const string& text) {
        cout << WHITE << text << RESET << endl;
    }

}
using namespace Color;
//Сортировка пузырек
void bubble_sort(int res[100])
{
    bool swapped = false;
    for (int i = 0; i < 100; i++)
    {
        swapped = false;
        for (int j = 0; j < 100 - i - 1; j++)
        {
            if (res[j] > res[j + 1])
            {
                std::swap(res[j], res[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
//Сортировка шейкер
void shaker_sort(int res[100])
{
    bool swapped = true;
    while (swapped != false)
    {
        swapped = false;
        bool AorB = true;
        if (AorB)
        {
            for (int i = 0; i < 99; i++)
            {
                if (res[i] > res[i + 1])
                {
                    std::swap(res[i], res[i + 1]);
                    swapped = true;
                    AorB = false;
                }
            }
        }
        else
        {
            for (int j = 99; j > 0; j--)
            {
                if (res[j - 1] > res[j])
                {
                    std::swap(res[j], res[j - 1]);
                    swapped = true;
                    AorB = true;
                }
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
//Бинарный поиск
bool BinarySearch(int res[100], int num)
{
    int left = 0;
    int right = 100 - 1;
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (res[middle] == num)
        {
            return 1;
        }
        if (res[middle] < num)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return 0;
}
//Сортировка расческой
void CombSort(int res[100])
{
    int step = 100;
    bool isSwaps = true;
    while (step > 1 and isSwaps == true)
    {
        step = int(step / 1.247);
        isSwaps = false;
        for (int i = 0; i < 100 - step; i++)
        {
            if (res[i] > res[i + step])
            {
                swap(res[i], res[i + step]);
                isSwaps = true;
            }
        }
    }
}
//Сортировка вставками
void InsertSort(int res[100])
{
    for (int j = 1; j < 100; j++)
    {
        int bufer = res[j];
        int i = j - 1;
        while (i >= 0 && res[i] > bufer)
        {
            res[i + 1] = res[i];
            i--;
        }
        res[++i] = bufer;
    }
}
//Быстрая сортировка
void quickSort(vector<int>& res, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        int middle = res[(left + right) / 2];

        // Разделяем массив на две части
        while (left <= right) {
            // Ищем элементы, которые нужно поменять местами
            while (res[left] < middle) {
                left++;
            }
            while (res[right] > middle) {
                right--;
            }
            if (left <= right) {
                swap(res[left], res[right]);
                left++;
                right--;
            }
        }
        if (first < right) {
            quickSort(res, first, right);
        }
        if (left < last) {
            quickSort(res, left, last);
        }
    }
}

int BinarySearch1(int res[100], int num)
{
    int left = 0;
    int right = 100 - 1;
    int middle;
    int k = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (res[middle] == num)
        {
            return middle;
        }
        if (res[middle] < num)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return 0;
}

//Сортировка Шелла
void shellSort(int res[100]) {
    // Начинаем с большого интервала и уменьшаем его
    for (int gap = 100 / 2; gap > 0; gap /= 2) {
        // Выполняем сортировку вставками для текущего интервала
        for (int i = gap; i < 100; i++) {
            int temp = res[i];
            int j;
            for (j = i; j >= gap && res[j - gap] > temp; j -= gap) {
                res[j] = res[j - gap];
            }
            res[j] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end, start1, end1;
    nanoseconds result, result1;

    int yop;

    int key;

    int choice = 0;
    int res[100];

    int mini = 101;
    int maxi = -101;

    while (true) {
        //Меню
        cout << "\033[1m\033[31m";
        Red("Выберите пункт (1-8) или 0 для выхода\n");
        cout << "\033[0m";
        cout << "1. Пункт 1. Массив размерности N = 100\n";
        cout << "2. Пункт 2. Отсортировать\n";
        cout << "3. Пункт 3. Найти максимальный и минимальный элемент\n";
        cout << "4. Пункт 4. Выводит среднее значение\n";
        cout << "5. Пункт 5. Меньше числа a\n";
        cout << "6. Пункт 6. Больше числа b\n";
        cout << "7. Пункт 7. Есть ли введенное пользователем число\n";
        cout << "8. Пункт 8. Меняет местами элементы массива\n";
        cout << "9. Пункт 9. Сортировка шелла\n";
        cout << "0. Выход\n";

        cin >> choice;

        if (choice == 0) {
            std::cout << "\nПрограмма завершила свою работу" << std::endl;
            break;
        }
        switch (choice) {
        case 1:
            while (true)
            {
                cout << "\033[1m\033[31m";
                Green("Вы выбрали пункт 1");
                cout << "\033[0m";
                Cian("\nНесортированный список: ");
                start = steady_clock::now();
                for (int l = 0; l < 100; l++)
                {
                    int random1 = rand() % 200 - 100;
                    res[l] = random1;
                    if (random1 < mini)
                    {
                        mini = random1;
                    }
                    if (random1 > maxi)
                    {
                        maxi = random1;
                    }
                    cout << res[l] << " ";
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                key = result.count();
                cout << endl;
                char finish;
                cout << "Хотите выйти из 1 пункта?: y/n: ";
                cin >> finish;
                if (finish == 'y' || finish == 'Y' || finish == 'н')
                    break;
            }
        case 2:
            while (true)
            {
                Green("\nВы выбрали пункт 2");
                cout << "\nСейчас вы можете выбрать тип сортировки:\n";
                cout << "1: bubble_sort\n";
                cout << "2: shaker_sort\n";
                cout << "3: CombSort\n";
                cout << "4: InsertSort\n";
                cout << "5: quickSort\n";
                cout << "0: Выход из второго пункта\n";
                int sorty;
                cin >> sorty;
                if (sorty == 1) {
                    start = steady_clock::now();
                    bubble_sort(res);
                    Blue("Cортированный список: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "Время работы: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 2) {
                    start = steady_clock::now();
                    shaker_sort(res);
                    Blue("Cортированный список: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "Время работы: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 3) {
                    start = steady_clock::now();
                    CombSort(res);
                    Blue("Cортированный список: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "Время работы: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 4) {
                    start = steady_clock::now();
                    InsertSort(res);
                    Blue("Cортированный список: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "Время работы: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 5)
                {
                    vector<int> arr(100);
                    for (int l = 0; l < 100; l++)
                    {
                        int random1 = rand() % 200 - 100;
                        arr[l] = random1;
                    }
                    cout << endl;
                    start = steady_clock::now();
                    quickSort(arr, 0, 99);
                    Blue("Cортированный список: ");
                    for (int i = 0; i < 100; i++)
                        cout << arr[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "Время работы: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 0)
                    break;
            }

        case 3:
            while (true)
            {
                Green("Вы выбрали пункт 3\n");
                cout << "min элемент массива : " << mini << endl;
                cout << "max элемент массива : " << maxi << endl;
                Yellow("Время затраченное на поиск минимального и максимального элемента в НЕсортированном массиве: ");
                cout << key << endl;
                Yellow("Время затраченное на поиск минимального и максимального элемента в Сортированном массиве: ");
                start = steady_clock::now();
                int a = res[0], b = res[99];
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << result.count() << "\n";
                break;
            }
        case 4:
            while (true)
            {
                Green("Вы выбрали пункт 4\n");
                int srednee = int((mini + maxi) / 2);
                cout << "Среднее значение min и max: " << srednee << endl;
                int count = 0;
                int indexi[50];
                int o = 0;
                for (int l = 0; l < 100; l++)
                {
                    if (res[l] == srednee)
                    {
                        count += 1;
                    }
                }
                Cian("Количество элементов равных среднему значению: ");
                cout << count << endl;
                cout << "\033[1m\033[36m";
                cout << "Индексы данных элементов: ";
                cout << "\033[00m";
                bool found = false;
                start = steady_clock::now();
                for (int i = 0; i < 100; ++i)
                {
                    if (res[i] == srednee)
                    {
                        cout << i << " ";
                        found = true;
                    }
                }
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                if (!found) {
                    Red("Нет элементов, равных среднему значению.");
                }
                cout << endl;
                cout << "Время поиска: " << result.count() << "\n";
                break;
            }
        case 5:
            while (true)
            {
                shaker_sort(res);
                Green("Вы выбрали пункт 5\n");
                Blue("Введите число, чтобы найти количество элементов меньших a");
                int a;
                cout << "a = ";
                cin >> a;
                cout << "Количество элементов меньших a: ";
                int fin = BinarySearch1(res, a);
                if (fin != 0) {
                    cout << "Количество элементов меньших " << a << ": " << fin << endl;
                }
                else {
                    cout << "Число " << a << " нет в списке." << endl;
                }
                break;
            }
        case 6:
            while (true)
            {
                shaker_sort(res);
                Green("Вы выбрали пункт 6\n");
                Blue("Введите число, чтобы найти количество элементов больших a");
                int a;
                cout << "a = ";
                cin >> a;
                int fin = 100 - BinarySearch1(res, a);
                if (fin != 0) {
                    cout << "Количество элементов больших " << a << ": " << fin << endl;
                }
                else {
                    cout << "\033[1m\033[31m";
                    cout << "Число " << a << " нет в списке." << endl;
                    cout << "\033[00m";
                }
                break;
            }
        case 7:
            while (true)
            {
                Green("Вы выбрали пункт 7\n");
                Blue("Введите число, которое хотите найти в списке");
                int choice;
                cout << "choice = ";
                cin >> choice;
                start = steady_clock::now();
                int otvet = BinarySearch(res, choice);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                if (otvet != 0) {
                    cout << "Значение " << choice << " есть в массиве" << endl;
                }
                else {
                    cout << "\033[1m\033[31m";
                    cout << "Числа " << choice << " нет в списке." << endl;
                    cout << "\033[00m";
                }
                cout << "Время работы бинарного поиска: " << result.count() << endl;
                start1 = steady_clock::now();
                for (int i = 0; i < 100; i++)
                {
                    if (res[i] == choice)
                        return 1;
                    else
                        break;
                }
                end1 = steady_clock::now();
                result1 = duration_cast<nanoseconds>(end1 - start1);
                break;
            }
        case 8:
            Green("\nВы выбрали пункт 8\n");
            Cian("Сейчас необходимо поочередно ввести индексы элементов, нуждаяющихся в замене.");
            int a, b;
            cout << "Введите число A: ";
            cin >> a;
            cout << "Введите число B: ";
            cin >> b;
            int bufer;
            start = steady_clock::now();
            bufer = res[a];
            res[a] = res[b];
            res[b] = bufer;
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\nВот измененный массив: ";
            for (int i = 0; i < 100; i++)
                cout << res[i] << " ";
            Blue("\nВремя смены элементов с данными индексами: ");
            cout << result.count() << endl;
        case 9:
            while (true)
            {
                Green("Вы выбрали пункт 9. Сортировка Шелла\n");
                Blue("Cейчас мы наглядно увидим разницу между сортировкой Шелла и Bubble_Sort");
                Cian("Введите 1 - бабл, 2 - сортировка шелла или 0-выход");
                int sorty;
                cin >> sorty;
                if (sorty == 1) {
                    start = steady_clock::now();
                    bubble_sort(res);
                    Blue("Cортированный список: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "Время работы: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 2) {
                    start = steady_clock::now();
                    shellSort(res);
                    Blue("Cортированный список: ");
                    for (int i = 0; i < 100; i++)
                        cout << res[i] << " ";
                    end = steady_clock::now();
                    result = duration_cast<nanoseconds>(end - start);
                    cout << "\033[1m\033[33m";
                    cout << "\n" << "Время работы: " << result.count() << "\n";
                    cout << "\033[0m";
                }
                if (sorty == 0)
                    break;
            }
        default:
            cout << "Неверный выбор. Пожалуйста, выберите от 0 до 8\n";
        }
    }

    return 0;
}