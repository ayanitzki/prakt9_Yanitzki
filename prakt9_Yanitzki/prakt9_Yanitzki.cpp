#include <string>
#include <iostream>
using namespace std;

const int n = 5;
void applyProcessing(double* data, int size, void (*processor)(double*, int)) 
{
    if (processor != nullptr) {
        processor(data, size);
    }
}
void copy(double arr[], const double source[])
{
    for (int i = 0; i < 5; i++)
    {
        arr[i] = source[i];
    }
}
void ShowArray(double arr[])
{
    cout << "Массив = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}
void prInc(double* data, int size)
{
    double value;
    cout << "На сколько увеличить?" << endl;
    cin >> value;
    for (int i = 0; i < n; i++)
    {
        data[i] += value;
    }
}
void prDec(double* data, int size)
{
    double value;
    cout << "На сколько уменьшить?" << endl;
    cin >> value;
    for (int i = 0; i < n; i++)
    {
        data[i] -= value;
    }
}
void prFull(double* data, int size)
{
    for (int i = 0; i < n; i++)
    {
        data[i] = 100.0;
    }
}
void prLim(double* data, int size)
{
    for (int i = 0; i < size; i++) 
    {
        if (data[i] < 0.0)
        {
            data[i] = 0.0;
        }
        if (data[i] > 100.0)
        {
            data[i] = 100.0;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));

    double source[n];
    for (int i = 0; i < n; i++)
    {
        source[i] = (rand() % 101) + (rand() % 10) / 10.0;
    }
    double arr[n];

    copy(arr, source);
    
    void (*processors[])(double*, int) = { prInc, prDec, prFull, prLim };

    int choice = 0;
    while (true)
    {
        cout << "1. Ввести данные" << endl;
        cout << "2. Показать данные" << endl;
        cout << "3. Выбрать и выполнить обработку" << endl;
        cout << "4. Восстановить исходные данные" << endl;
        cout << "5. Выход" << endl;

        cin >> choice;

        if (choice == 1)
        {
            cout << "Введите 5 чисел: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
        }
        else if (choice == 2)
        {
            ShowArray(arr);
        }
        else if (choice == 3)
        {
            cout << "1. Увеличить здоровье" << endl;
            cout << "2. Уменьшить здоровье" << endl;
            cout << "3. Восстановить здоровье до 100" << endl;
            cout << "4. Ограничить све значения диапазоном от 0 до 100" << endl;

            int pr = 0;
            cin >> pr;

            if (pr >= 1 && pr <= 4)
            {
                cout << "ДО: " << endl;
                ShowArray(arr);

                applyProcessing(arr, n, processors[pr - 1]);

                cout << "ПОСЛЕ: " << endl; 
                ShowArray(arr);
            }
            else
            {
                cout << "Неверный номер операции" << endl;
            }
        }
        else if (choice == 4)
        {
            copy(arr, source);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Неверный пункт меню" << endl;
        }
    }
}
