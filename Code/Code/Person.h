#pragma once
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Person : public Object
{
protected:
	string Name;
	int Age;
	
public:

	Person(){}

	Person(string name, int age)
	{
		setName(name);
		setAge(age);
	}

	virtual ~Person() {}

	void Show(ostream& stream) override { stream << "Имя: " << Name << ", возраст: " << Age; }

	void Fill(istream& stream) override
	{
		cout << "Имя? "; getline(stream, Name);
		cout << "Возраст? "; stream >> Age;
	}

	void setName(string name) { Name = name; }

	void setAge(int age) { Age = age; }

	string getName() { return Name; }

	int getAge() { return Age; }
};

