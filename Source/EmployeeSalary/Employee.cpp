#include"Employee.h"
Employee::Employee() {};
    string Employee::getName() {
        return _name;
    }

    void Employee::setName(string name) {
        _name = name;
    }

    Employee::~Employee() {};