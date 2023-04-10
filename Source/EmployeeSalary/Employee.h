#pragma once
#include<iostream>
#include<map>
#include<regex>
#include<tuple>
#include<sstream>
using namespace std;
class Employee {
protected:
    string _name;
public:
    Employee();
    string getName();
    void setName(string name);
    virtual shared_ptr<Employee>clone() = 0;
    virtual string magicWord() = 0;
    virtual int Payment() = 0;
    ~Employee();
};
