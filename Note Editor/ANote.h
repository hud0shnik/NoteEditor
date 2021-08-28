#pragma once
#include "Note.h"

class ANote :
    public Note
{
    // Поля класса
private: // закрытая часть
    Tags tags;

    // Методы класса
public: // открытая часть
    ANote(); // конструктор по умолчанию - создает пустой объект
    ~ANote(); // деструктор - удаляет объект

    // Методы задать данные 
    void SetData(Data nd);
    void SetTags(Tags nt);

    // Методы выдать данные
    Data GetData() { return data; }
    Tags GetTags() { return tags; }

    bool Search(string t); // поиск по меткам
    void Print(); // печать
};

