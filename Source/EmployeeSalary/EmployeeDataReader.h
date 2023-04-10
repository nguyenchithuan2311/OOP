#pragma once
#include"Factory.h"
#include<fstream>
class EmployeeDataReader {
private:
    string _connectString;
public:
    EmployeeDataReader(string);
    tuple<bool, vector<shared_ptr<Employee>>> GetAll();
};