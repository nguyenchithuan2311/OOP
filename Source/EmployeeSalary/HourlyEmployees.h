#pragma once
#include"Employee.h"
#include"IConvert.h"
class HourlyEmployees :public Employee {
private:
    int _HourlySalary;
    int _WorkingHours;
public:
    HourlyEmployees();
    
    HourlyEmployees(int HourlySalary, int WorkingHours);

    void setHourlySalary(int HourlySalary);
    
    void setWorkingHours(int WorkingHours);

    int getHourlySalary();

    int getWorkingHours();

    shared_ptr<Employee>clone();

    string magicWord();
    
    int Payment();
    
    ~HourlyEmployees();
};

class HourlyEmployeesDataConverter :public IConvert {
public:
    bool isValidFormart(string value);

    string convert(shared_ptr<Employee> employee);
    
    shared_ptr<IConvert> clone();

    tuple<bool, shared_ptr<Employee>>convertBack(string str);
};