#pragma once
#include "Note.h"
class GNote :
    public Note
{
    // ���� ������
private: // �������� �����
    Tags tags;

    // ������ ������
public: // �������� �����
    GNote(); // ����������� �� ��������� - ������� ������ ������
    ~GNote(); // ���������� - ������� ������

    // ������ ������ ������ 
    void SetData(Data nd);
    void SetTags(Tags nt);

    // ������ ������ ������
    Data GetData() { return data; }
    Tags GetTags() { return tags; }

    bool Search(string t); // ����� �� ������
    void Print(); // ������
};

