#pragma once

class MyString
{
private:
    int size;
    char* m_pStr;        // ������� ������ ������ (����� ������)
public:
    MyString();
    MyString(const char* s);    // ���������� ������������
    MyString(const MyString& other);
    ~MyString();        // ���������� �����������

    MyString& operator= (const MyString& v);
    void Copy(char* s);
    const char* GetString();    // ���������� ������ (accessor)
    int GetLength();    // ���������� ������ (����� ������)
};
