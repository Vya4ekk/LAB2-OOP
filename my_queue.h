#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

struct people
{
    int priority = 0;
    std::string name = "no_name";
};

class que
{
    people* arr;
    int capacity;
    int rear;
    int count;

    int left = -1;
    int right = -1;
public:
    que(int size = 200);
    que(const que& q);
    ~que();

    void pop();
    void push(people x);
    void incapacity(int newcapacity = 10);
    void show();
    void file(std::string filename);
    void setpriority();

    people peek();

    int size();

    bool isEmpty();
    bool isFull();

    que& getfromfile(std::string filename);
    que& operator+(const que& q);
    que& operator=(const people& p);
    que& operator = (const que& q);
    que& operator ()(int l, int r);

    friend ostream& operator <<(std::ostream& os, const que& q);
    friend istream& operator >>(std::istream& is, que& q);
};
