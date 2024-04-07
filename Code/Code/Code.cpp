#include "Vector.h"
#include "Student.h"

int main()
{
	system("chcp 1251");

	int Lenght;

	do
	{
		cout << "Введите размер вектора" << endl;
		cin >> Lenght;
	} 
	while (Lenght <= 0);

	Vector vector(Lenght);

	cin >> vector;

	cout << vector << endl;
}
