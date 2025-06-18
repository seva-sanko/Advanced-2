#pragma once
#include <iostream>
using std::cout;
using std::endl;
//using std::vector;
using std::string;

class Shape {
private:
    static int Count;

public:
    static Shape* shapes[1000];
    static void PrintCount() {
        printf("Count = %d", Count);
    }
    static int GetCount() {
        return Count;
    }
    Shape();
    virtual void Move(double x, double y) = 0;
    virtual void Out() = 0;
    virtual double Area() = 0;
    ~Shape();
};

class Vector;



