#pragma once
#include"Employee.h"
#include"IConvert.h"
class DailyEmployee :public Employee {
private:
    int _DailySalary;
    int _WorkingDays;
public:
    DailyEmployee();

    DailyEmployee(int DailySalary, int WorkingDays);

    void setDailySalary(int DailySalary);
    
    void setWorkingDays(int WorkingDays);

    int getDailySalary();
    
    int getWorkingDays();
    
    shared_ptr<Employee>clone();
    
    string magicWord();
    
    int Payment();
    
    ~DailyEmployee();
};

class DailyEmployeeDataConverter :public IConvert {
public:
    bool isValidFormart(string value);

    string convert(shared_ptr<Employee> employee);

    shared_ptr<IConvert> clone();

    tuple<bool, shared_ptr<Employee>>convertBack(string str);
};

