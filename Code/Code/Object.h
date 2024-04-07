#pragma once

#include <iostream>

using namespace std;
class Object
{
public:

	Object(){}

	~Object(){}

	virtual void Show(ostream& stream) = 0;

	virtual void Fill(istream& stream) = 0;
};

