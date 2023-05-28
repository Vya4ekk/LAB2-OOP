#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <iterator>
#include <sstream>

struct people
{
    int priority = 0;
    std::string name = "no_name";   
};

class que
{
    people *arr;
    int capacity;
    int rear;
    int count;

public:
    que(int size = 200);
    que(const que& q);
    ~que();

    void dequeue();
    void enqueue(people x);
    void incapacity(int newcapacity = 10);
    void show();
    void file(std::string filename);
    void getfromfile(std::string filename);
    void setpriority();

    people peek();

    int size();

    bool isEmpty();
    bool isFull();
    
    people& operator = (const people & p);
    que& operator = (const que& q);
    que& operator ()(int l, int r, const people& p);
};

