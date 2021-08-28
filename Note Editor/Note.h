#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;

// ��������� �����
struct Tags {
	string* items;
	int count;
};

// ��������� ����
struct Date {
	int day,
		month,
		year;
};

// ��������� ������
struct Data {
	string title;	
	Date createDate;
	Date editDate;
	string note;
};

class Note
{
	// ���� ������
protected: // ���������� �����
	Data data;

	// ������ ������
public: // �������� �����
	Note(); // ����������� �� ��������� - ������� ������ ������ 
	~Note(); // ���������� - ������� ������ 
};

