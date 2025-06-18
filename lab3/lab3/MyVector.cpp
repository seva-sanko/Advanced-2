//#include "stdafx.h"
#include "MyVector.h"

Vector::Vector(double c1, double c2)
{
    //    Count++;
    x = c1;
    y = c2;
}

Vector::Vector()
{
    //    Count++;
    x = y = 0.;
}

void Vector::Out()
{
    cout << "\nVector:  x = " << x << ",  y = " << y << endl;
}

Vector::Vector(const Vector& other) {
    //    Count++;
    this->x = other.x;
    this->y = other.y;
}

//====== Переопределение операций =====//
Vector& Vector::operator= (const Vector& v)    // Присвоение
{
    if (this == &v)
        return *this;
    x = v.x;
    y = v.y;
    return *this;
}

Vector operator+ (const Vector& one, const Vector& two) {
    return Vector(one.x + two.x, one.y + two.y);
}

double Vector::operator!() {
    double modul = sqrt(x * x + y * y);
    return modul;
}

bool Vector::operator> (Vector& other) {
    if ((*this).operator!() > other.operator!()) {
        return true;
    }
    return false;
}
bool Vector::operator== (const Vector& other) const {
    if (this->x == other.x && this->y == other.y) {
        return true;
    }
    return (x * x + y * y) < (other.x * other.x + other.y * other.y);
};

Vector operator* (double num, const Vector& other) {
    return Vector(num * other.x, num * other.y);
}

Vector Vector::operator*(double num) {
    return Vector(x * num, y * num);
}

Vector Vector::operator*(const Vector& other) {
    return Vector(x * other.x, y * other.y);
}


Vector::~Vector() {
    //    Count--;
}


void Vector::Move(double o, double p) {
    this->x += o;
    this->y += p;
};

double Vector::Area() {
    return 0.0;
};


bool Vector::operator< (const Vector& other) const {
    return (x * x + y * y) < (other.x * other.x + other.y * other.y);
}
