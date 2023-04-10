#pragma once
#include"Employee.h"
#include"IConvert.h"
class ProductEmployees :public Employee {
private:
    int _PaymentProduct;
    int _TotalProduct;
public:
    ProductEmployees();

    ProductEmployees(int PaymentProduct, int TotalProduct);

    void setPaymentProduct(int PaymentProduct);

    void setTotalProduct(int TotalProduct);

    int getPaymentProduct();

    int getTotalProduct();

    shared_ptr<Employee>clone();

    string magicWord();

    int Payment();

    ~ProductEmployees();
};

class ProductEmployeesDataConveter :public IConvert {
public:
    bool isValidFormart(string value);

    string convert(shared_ptr<Employee> employee);

    shared_ptr<IConvert> clone();

    tuple<bool, shared_ptr<Employee>>convertBack(string str);
};
