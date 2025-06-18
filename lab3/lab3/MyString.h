#pragma once

class MyString
{
private:
    int size;
    char* m_pStr;        // Ёлемент данных класса (адрес строки)
public:
    MyString();
    MyString(const char* s);    // ќбъ€вление конструктора
    MyString(const MyString& other);
    ~MyString();        // ќбъ€вление деструктора

    MyString& operator= (const MyString& v);
    void Copy(char* s);
    const char* GetString();    // ќбъ€вление метода (accessor)
    int GetLength();    // ќбъ€вление метода (длина строки)
};
