#pragma once
#include "Object.h"

class Person : public Object //Первый наследник
{
protected:
	//Поля
	string Name;
	int Age;
	
public:

	//Конструкторы
	Person(){}

	Person(string name, int age)
	{
		setName(name);
		setAge(age);
	}

	virtual ~Person() {} //Диструктор

	//Переопределение чисто вирутальных функций
	void Show(ostream& stream) override { stream << "Имя: " << Name << ", возраст: " << Age; }
	void Fill(istream& stream) override
	{
		cout << "Имя? "; getline(stream, Name);
		cout << "Возраст? "; stream >> Age;
	}

	//Сеттеры и геттеры
	void setName(string name) { Name = name; }
	void setAge(int age) { Age = age; }
	string getName() { return Name; }
	int getAge() { return Age; }
};