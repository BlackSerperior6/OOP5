#include "Vector.h"

int main()
{
	system("chcp 1251");

	int Lenght;

	//Вводим длинну вектора
	do
	{
		cout << "Введите размер вектора" << endl;
		cin >> Lenght;
	} 
	while (Lenght <= 0);

	Vector vector(Lenght); //Создаем вектор

	cin >> vector; //Вводим данные

	cout << vector << endl; //Выводим
}
