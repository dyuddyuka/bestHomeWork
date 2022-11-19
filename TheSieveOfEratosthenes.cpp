#include <iostream>

void Eratosthenes()
{
	int N;
	std::cout << "������� ����������� �������" << std::endl;
	std::cin >> N;
	bool* massiv = new bool[N];

	int i, j;
	for (j = 2; j <= N; j++) massiv[j] = true;
	j = 2;
	while (j * j <= N)
	{
		i = j * j;
		if (massiv[j])
			while (i <= N)
			{
				massiv[i] = false;
				i = i + j;
			}
		j = j + 1;
	}
	std::cout << "������ ������� �����: ";
	for (j = 2; j <= N; j++)
	{
		if (massiv[j] == true) std::cout << " " << j;
	}
}
