#pragma once
#include "Note.h"
class VNote :
    public Note
{
    // ���� ������
private: // �������� �����
    Tags tags;

    // ������ ������
public: // �������� �����
    VNote(); // ����������� �� ��������� - ������� ������ ������
    ~VNote(); // ���������� - ������� ������

    // ������ ������ ������ 
    void SetData(Data nd);
    void SetTags(Tags nt);

    // ������ ������ ������
    Data GetData() { return data; }
    Tags GetTags() { return tags; }

    bool Search(string t); // ����� �� ������
    void Print(); // ������
};

