#pragma once
#include "Student.h"

class Vector //Класс вектора
{
public:

	Vector(int lenght) //Конструктор с параметрами
	{
		elements = new Object* [lenght];

		Lenght = lenght;
		cur_Lenght = 0;
	}

	~Vector() //Диструктор
	{
		if (elements == 0)
			return;

		for (int i = 0; i < cur_Lenght; i++)
			delete elements[i];

		delete[] elements;

		Lenght = 0;
		cur_Lenght = 0;
	}

	bool TryAdd(Object* element)  //Метод для добавки элемента в вектор
	{
		if (cur_Lenght >= Lenght)
			return false;

		elements[cur_Lenght] = element;
		cur_Lenght++;
		return true;
	}

	//Дружественные функции ввода и вывода
	friend ostream& operator<<(ostream& stream, Vector& vector);
	friend istream& operator>>(istream& stream, Vector& vector);

private:
	Object** elements; //Сам массив элементов
	int Lenght; //Максимальная длина вектора
	int cur_Lenght; //Текущая длина вектора
};

//Перегрузка оператора ввода через потоки
ostream& operator<<(ostream& stream, Vector& vector)
{
	stream << "Содержимое вектора:" << endl;

	if (vector.cur_Lenght > 0)
	{
		vector.elements[0]->Show(stream);

		for (int i = 1; i < vector.cur_Lenght; i++)
		{
			cout << endl;
			vector.elements[i]->Show(stream);
		}
	}

	return stream;	
}

//Перегрузка оператора вывода через потоки
istream& operator>>(istream& stream, Vector& vector)
{
	cout << "Вводите содержимое вектора по элементно" << endl;

	for (int i = 0; i < vector.Lenght; i++)
	{
		stream.ignore();

		if (i % 2 == 0) //По очередно вводится либо человек, либо студент
		{
			Person* person = new Person;
			person->Fill(stream);
			vector.TryAdd(person);
		}
		else
		{
			Student* student = new Student;
			student->Fill(stream);
			vector.TryAdd(student);
		}
		
		cout << "-------------" << endl;
	}

	return stream;
}