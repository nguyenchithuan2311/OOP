#pragma once
#include"HourlyEmployees.h"
#include"DailyEmployee.h"
#include"Manager.h"
#include"ProductEmployees.h"
using namespace std;
class EmployeesFactory {
public:
    map<string, shared_ptr<Employee>> _prototypes;
private:
    inline static shared_ptr<EmployeesFactory>_instance = NULL;
private:
    EmployeesFactory();
public:
    static shared_ptr<EmployeesFactory> instance();
public:
    shared_ptr<Employee> create(string choice);
};

class ConvertFactory {
public:
	map<string, shared_ptr<IConvert>> _prototypes;
private:
	inline static shared_ptr<ConvertFactory> _instance = NULL;
private:
	ConvertFactory();
public:
	static shared_ptr<ConvertFactory> instance();
public:
	shared_ptr<IConvert>create(string choice);
};