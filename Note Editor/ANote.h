#pragma once
#include "Note.h"

class ANote :
    public Note
{
    // ���� ������
private: // �������� �����
    Tags tags;

    // ������ ������
public: // �������� �����
    ANote(); // ����������� �� ��������� - ������� ������ ������
    ~ANote(); // ���������� - ������� ������

    // ������ ������ ������ 
    void SetData(Data nd);
    void SetTags(Tags nt);

    // ������ ������ ������
    Data GetData() { return data; }
    Tags GetTags() { return tags; }

    bool Search(string t); // ����� �� ������
    void Print(); // ������
};

