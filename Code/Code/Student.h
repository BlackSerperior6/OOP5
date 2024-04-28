#pragma once
#include "Person.h"

class Student : public Person //Второй наследник
{
private:

	//Поля
	string SubjectName;
	int Mark;

public:

	//Конструкторыы
	Student() {}
	Student(string name, int age, string subjectName, int mark):Person(name, age)
	{
		setSubjectName(subjectName);
		setMark(mark);
	}

	virtual ~Student(){} //Диструктор

	//Геттеры и сеттеры
	void setSubjectName(string subjectName) { SubjectName = subjectName; }
	void setMark(int mark) { Mark = mark; }
	string getSubjectName() { return SubjectName; }
	int getMark() { return Mark; }

	//Перегруженные методы ввода и вывода
	void Show(ostream& stream) override { stream << "Имя: " << Name << ", возраст: " 
		<< Age << ", предмет: " << SubjectName << ", оценка: " << Mark; }
	void Fill(istream& stream) override 
	{
		Person::Fill(stream);

		stream.ignore();

		cout << "Предмет? "; getline(stream, SubjectName);
		cout << "Оценка? "; stream >> Mark;
	}


	//Метод для вывода сообщение о плохой оценке
	void PrintIfBadMark() 
	{
		if (Mark < 3)
			cout << "ПЛОХАЯ ОЦЕНКА, НА ПЕРЕЗДАЧУ!!!!" << endl;
	}
};

