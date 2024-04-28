#pragma once
#include "Person.h"

class Student : public Person //������ ���������
{
private:

	//����
	string SubjectName;
	int Mark;

public:

	//�������������
	Student() {}
	Student(string name, int age, string subjectName, int mark):Person(name, age)
	{
		setSubjectName(subjectName);
		setMark(mark);
	}

	virtual ~Student(){} //����������

	//������� � �������
	void setSubjectName(string subjectName) { SubjectName = subjectName; }
	void setMark(int mark) { Mark = mark; }
	string getSubjectName() { return SubjectName; }
	int getMark() { return Mark; }

	//������������� ������ ����� � ������
	void Show(ostream& stream) override { stream << "���: " << Name << ", �������: " 
		<< Age << ", �������: " << SubjectName << ", ������: " << Mark; }
	void Fill(istream& stream) override 
	{
		Person::Fill(stream);

		stream.ignore();

		cout << "�������? "; getline(stream, SubjectName);
		cout << "������? "; stream >> Mark;
	}


	//����� ��� ������ ��������� � ������ ������
	void PrintIfBadMark() 
	{
		if (Mark < 3)
			cout << "������ ������, �� ���������!!!!" << endl;
	}
};

