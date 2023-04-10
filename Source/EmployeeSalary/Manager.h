#pragma once
#include"Employee.h"
#include"IConvert.h"
class Manager :public Employee {
private:
    int _FixedPayment;
    int _NumberOfWorkers;
    int _PaymentPerEmployee;
public:
    Manager();
    
    Manager(int FixedPayment, int NumberOfWorkers, int PaymentPerEmployee);

    void setFixedPayment(int FixedPayment);
    
    void setNumberOfWorkers(int NumberOfWorkers);
    
    void setPaymentPerEmployee(int PaymentPerEmployee);

    int getFixedPayment();
    
    int  getNumberOfWorkers();
    
    int getPaymentPerEmployee();
    
    shared_ptr<Employee>clone();
    
    string magicWord();
   
    int Payment();
    
    ~Manager();
};

class ManagerDataConveter :public IConvert {
public:
    bool isValidFormart(string value);
    
    string convert(shared_ptr<Employee> employee);
   
    shared_ptr<IConvert> clone();
    
    tuple<bool, shared_ptr<Employee>>convertBack(string str);
};