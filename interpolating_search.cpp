#include <iostream>
#include <iomanip>
//прототипы функций
int interpolatingSearch (int[], int, int);
void printArray (int[], int);
using namespace std;
int main()
{
    //резервируем память для переменных
    const int size = 18;
    int array[size] = {2,5,8,12,23,35,36,41,52,54,55,57,63,67,81,83,87,91};
    int key, result;
    //запрашиваем и сохраняем ключ поиска
    cout << "Enter a key of search: ";
    cin >> key;
    //печатаем массив
    printArray (array, size);
    //вызываем функцию интерполирующего поиска
    //сохраняем, возвращенное ею значение, в переменную result
    result = interpolatingSearch (array, size, key);
    if (result != -1)
    //значение найдено - выводим его индекс
    cout << "Value is found in an element with an index " << result << endl;
    else
    //значение не найдено
    cout << "Value is not found" << endl;
    return 0;
}
//функция, выполняющая интерполирующий поиск
//в качесте аргументов принимает массив, размер массива и ключ поиска
int interpolatingSearch (int a[], int arraySize, int keyOfSearch)
{
    //объявляем необходимые локальные переменные
    //изначально устанавливаем нижний индекс на начало массива,
    //а верний на конец массива
    int low = 0;
    int high = arraySize - 1;
    int mid;
    //цикл интерполирующего поиска
    while (a[low] < keyOfSearch && a[high] >= keyOfSearch)
    {
        //интерполирующий поиск производит оценку новой области поиска
        //по расстоянию между ключом поиска и текущим значение элемента
        mid = low + ((keyOfSearch - a[low]) * (high - low)) / (a[high] - a[low]);
        //если значение в ячейке с индексом mid меньше, то смещаем нижнюю границу
        if (a[mid] < keyOfSearch)
        low = mid + 1;
        //в случае, если значение больше, то смещаем верхнюю границу
        else if (a[mid] > keyOfSearch)
        high = mid - 1;
        //если равны, то возвращаем индекс
        else
        return mid;
    }
    //если цикл while не вернул индекс искомого значения,
    //то проверяем не находится ли оно в ячейке массива с индексом low,
    //иначе возвращаем -1 (значение не найдено)
    if (a[low] == keyOfSearch)
        return low;
    else
        return -1;
    }
    //функция, печатающая массив
    void printArray (int b[], int sizeOfArray)
    {
    cout << "Indexes: " << endl;
    for (int i = 0; i < sizeOfArray; i++)
    cout << setw(4) << i;
    cout << endl;
    for (int i = 0; i < sizeOfArray; i++)
    cout << "----";
    cout << endl;
    for (int i = 0; i < sizeOfArray; i++)
    cout << setw(4) << b[i];
    cout << endl << endl;
}
