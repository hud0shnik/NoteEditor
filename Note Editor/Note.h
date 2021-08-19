#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;

// Структура меток
struct Tags {
	string* items;
	int count;
};

// Структура даты
struct Date {
	int day,
		month,
		year;
};

// Структура данных
struct Data {
	string title;	
	Date createDate;
	Date editDate;
	string note;
};

class Note
{
	// Поля класса
protected: // защищенная часть
	Data data;

	// Методы класса
public: // открытая часть
	Note(); // конструктор по умолчанию - создает пустой объект 
	~Note(); // деструктор - удаляет объект 
};

