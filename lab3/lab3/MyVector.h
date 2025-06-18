#pragma once
#include <iostream>
#include "Shape.h"

class Vector : public Shape {
private:
    double x, y;    // ���������� ������� �� ���������
    //    static int Count;
public:
    //    static void PrintCount(){
    //        printf("Count = %d\n", Count);
    //    };

        //========== ��� ������������
    Vector(double c1, double c2);
    Vector();// Default
    Vector(const Vector& other);
    //====== ��������������� �������� =====//
    Vector& operator= (const Vector& v);    // ����������
    double operator! ();
    bool operator> (Vector& other);
    bool operator< (const Vector& other) const;
    bool operator== (const Vector& other) const;
    //    Vector operator+ (const Vector& other);
    double GetX() { return x; }
    double GetY() { return y; }
    friend Vector operator+ (const Vector& one, const Vector& two);
    friend Vector operator* (double num, const Vector& other);
    Vector operator*(double num);
    Vector operator*(const Vector& other);

    friend class Rect;
    friend class Circle;
    ~Vector();
    void Out() override;
    void Move(double x, double y) override;
    double Area() override;
    friend bool isSumGreaterThanTwo(const Vector& v);
};

