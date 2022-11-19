#include <iostream>
#include <algorithm>
 template <typename T>
	 T GetCorrectNumber(T min, T max)
	 {
		 T x;
		 while ((std::cin >> x).fail() || x<min || x > max)
		 {
			 std::cin.clear();
			 std::cin.ignore(10000, '\n');
			 std::cout << "введено не корректное значение \n";
		 }
		 return x;
	 }
 void Binary_search()
{

	std::cout << "Введите размерность вашего массива" << std::endl; 
	int n = GetCorrectNumber(2, 20000); //создали переменную  в которой будет храниться размерность нашего массива, учитывая рамки
	 
	
	//std::cin >> n;
	


	std::cout << "Введите числа массива,учитывая его размерность (иначе вам предстанет сообщение об ошибке и программа завершится): " << std::endl;

	int *arr = new int[n]; // Выделение памяти для массива
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i]; // считываем элементы массива
	}
	std::sort (arr, arr + n); // в случае неупорядоченного массива сортируем его с помощью встроенной функции
	// sort(<имя массива>, <имя массива> + <размер массива>, компаратор);
	std::cout << "После сортировки: ";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}


	std::cout << std::endl << "Введите интересующее вас значение : ";
	int key; // создали переменную в которой будет находиться значение
	int index_key = -1; //данная запись означает что такого элемента нет
	std::cin >> key; // считываем наш ключ
	 
	  

	int left = 0, right = n - 1;
	int middle;
	
	
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (key == arr[middle])
		{
			std::cout << "Искомый вами элемент имеет индекс: "; 
			index_key = middle;
			break;
		}
		if (key < arr[middle]) right = middle - 1;
		else left = middle + 1;
	}
	if (index_key == -1) std::cout << "ERROR!!! not found" << std::endl;
	else std::cout << index_key << std::endl;


	delete[] arr; // очистка памяти
	return ;
	
}

 int main()
 {
	 setlocale(LC_ALL, "rus");
	 Binary_search();
	 system("pause");
 }