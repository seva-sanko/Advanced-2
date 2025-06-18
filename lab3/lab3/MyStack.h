#pragma once
#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;

class StackOverflow : public std::runtime_error {
public:
    StackOverflow() : std::runtime_error("Stack over flow") {}
};


class StackUnderflow : public std::runtime_error {
public:
    StackUnderflow() : std::runtime_error("Stack under flow") {}
};


class StackOutOfRange : public std::runtime_error {
public:
    StackOutOfRange(int n) : std::runtime_error("Stack out of range") {
        printf("Ошибка в индекск %d\n", n);
    }
};


template<typename T, int n>
class MyStack {
    vector<T> arr;
    int nz = n;
public:
    MyStack() {

    }

    void Push(T temp) {
        if (arr.size() == n) {
            throw StackOverflow();
        }
        arr.push_back(temp);
    }

    T Pop() {
        if (arr.size() == 0) {
            throw StackUnderflow();
        }
        T value = arr.back();
        arr.pop_back();
        return value;
    }

    int GetSize() {
        return arr.size();
    }

    int Capacity() {
        return n;
    }

    T& operator[](int index) {
        if (index < 0 || index >= n) {
            throw StackOutOfRange(index); ///index
        }
        return arr[index];
    }

};
