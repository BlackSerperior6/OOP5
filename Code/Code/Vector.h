#pragma once
#include "Object.h"
#include "Student.h"

class Vector
{
public:

	Vector(int lenght)
	{
		elements = new Object* [lenght];

		Lenght = lenght;
		cur_Lenght = 0;
	}

	~Vector()
	{
		if (elements == 0)
			return;

		for (int i = 0; i < cur_Lenght; i++)
			delete elements[i];

		delete[] elements;

		Lenght = 0;
		cur_Lenght = 0;
	}

	bool TryAdd(Object* element) 
	{
		if (cur_Lenght >= Lenght)
			return false;

		elements[cur_Lenght] = element;
		cur_Lenght++;
		return true;
	}

	friend ostream& operator<<(ostream& stream, Vector& vector);

	friend istream& operator>>(istream& stream, Vector& vector);

private:

	Object** elements;
	int Lenght;
	int cur_Lenght;
};

ostream& operator<<(ostream& stream, Vector& vector)
{
	stream << "Содержимое вектора:" << endl;

	if (vector.cur_Lenght <= 0)
		return stream;
	
	vector.elements[0]->Show(stream);

	for (int i = 1; i < vector.cur_Lenght; i++)
	{
		cout << endl;
		vector.elements[i]->Show(stream);
	}

	return stream;	
}

istream& operator>>(istream& stream, Vector& vector)
{
	cout << "Вводите содержимое вектора по элементно" << endl;

	for (int i = 0; i < vector.Lenght; i++)
	{
		stream.ignore();

		if (i % 2 == 0)
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

