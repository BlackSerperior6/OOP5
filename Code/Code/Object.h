#pragma once

#include <iostream>
#include <string>

using namespace std;

class Object //абстрактный класс
{
public:
	Object(){}

	~Object(){}

	//„исто вирутальные методы
	virtual void Show(ostream& stream) = 0;
	virtual void Fill(istream& stream) = 0;
};