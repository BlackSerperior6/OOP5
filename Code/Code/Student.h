#pragma once
#include "Person.h"

class Student : public Person
{
private:
	string SubjectName;
	int Mark;

public:

	Student() {}

	Student(string name, int age, string subjectName, int mark):Person(name, age)
	{
		setSubjectName(subjectName);
		setMark(mark);
	}

	virtual ~Student(){}

	void setSubjectName(string subjectName) { SubjectName = subjectName; }

	void setMark(int mark) { Mark = mark; }

	string getSubjectName() { return SubjectName; }

	int getMark() { return Mark; }

	void Show(ostream& stream) override { stream << "Èìÿ: " << Name << ", âîçðàñò: " << Age << ", ïðåäìåò: " << SubjectName << ", îöåíêà: " << Mark; }

	void Fill(istream& stream) override 
	{
		Person::Fill(stream);

		stream.ignore();

		cout << "Ïðåäìåò? "; getline(stream, SubjectName);
		cout << "Îöåíêà? "; stream >> Mark;
	}

	void PrintIfBadMark() 
	{
		if (Mark < 3)
			cout << "ÏËÎÕÀß ÎÖÅÍÊÀ ÍÀ ÏÅÐÅÇÄÀ×Ó!!!!" << endl;
	}
};

