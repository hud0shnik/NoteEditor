#pragma once
#include "Note.h"
class TNote :
    public Note
{
    // ���� ������
private: // �������� �����
    Tags tags;

    // ������ ������
public: // �������� �����
    TNote(); // ����������� �� ��������� - ������� ������ ������
    ~TNote(); // ���������� - ������� ������

    // ������ ������ ������ 
    void SetData(Data nd);
    void SetTags(Tags nt);

    // ������ ������ ������
    Data GetData() { return data; }
    Tags GetTags() { return tags; }

    bool Search(string t); // ����� �� ������
    void Print(); // ������
};

