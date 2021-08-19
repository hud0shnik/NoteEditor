#pragma once
#include "ANote.h"
#include "VNote.h"
#include "GNote.h"
#include "TNote.h"

// Структуры для хранения данных объектов
struct VectorANote {
	ANote* items;
	int count;
};

struct VectorVNote {
	VNote* items;
	int count;
};

struct VectorGNote {
	GNote* items;
	int count;
};

struct VectorTNote {
	TNote* items;
	int count;
};

// Общие прототипы функций
void Menu(int& act);
void Print(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t);
void Add(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t);
void Edit(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t);
void Del(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t);
void Search(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t);
void Filtration(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t);
void Save(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t);
void Load(VectorANote& a, VectorVNote& v, VectorGNote& g, VectorTNote& t);

// Прототипы функция для ANote
void Copy(int n, ANote* org, ANote* (&res), int excl);
void Add(VectorANote(&origin), ANote a);
void Print(VectorANote n);
void Edit(int i, VectorANote& n, ANote a);
void Del(int index, VectorANote(&origin));
void Search(string t, VectorANote n);
void Filtration(string t, VectorANote n);
void Clear(VectorANote& n);
void Init(VectorANote& n);

// Прототипы функция для VNote
void Copy(int n, VNote* org, VNote* (&res), int excl);
void Add(VectorVNote(&origin), VNote a);
void Print(VectorVNote n);
void Edit(int i, VectorVNote& n, VNote a);
void Del(int index, VectorVNote(&origin));
void Search(string t, VectorVNote n);
void Filtration(string t, VectorVNote n);
void Clear(VectorVNote& n);
void Init(VectorVNote& n);

// Прототипы функция для GNote
void Copy(int n, GNote* org, GNote* (&res), int excl);
void Add(VectorGNote(&origin), GNote a);
void Print(VectorGNote n);
void Edit(int i, VectorGNote& n, GNote a);
void Del(int index, VectorGNote(&origin));
void Search(string t, VectorGNote n);
void Filtration(string t, VectorGNote n);
void Clear(VectorGNote& n);
void Init(VectorGNote& n);

// Прототипы функция для TNote
void Copy(int n, TNote* org, TNote* (&res), int excl);
void Add(VectorTNote(&origin), TNote a);
void Print(VectorTNote n);
void Edit(int i, VectorTNote& n, TNote a);
void Del(int index, VectorTNote(&origin));
void Search(string t, VectorTNote n);
void Filtration(string t, VectorTNote n);
void Clear(VectorTNote& n);
void Init(VectorTNote& n);