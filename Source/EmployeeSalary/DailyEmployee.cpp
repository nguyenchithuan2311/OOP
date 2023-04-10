#include"DailyEmployee.h"
    
    DailyEmployee::DailyEmployee() {};
    
    DailyEmployee::DailyEmployee(int DailySalary, int WorkingDays) {
        _DailySalary = DailySalary;
        _WorkingDays = WorkingDays;
    };

    void DailyEmployee::setDailySalary(int DailySalary) {
        _DailySalary = DailySalary;
    }
    
    void DailyEmployee::setWorkingDays(int WorkingDays) {
        _WorkingDays = WorkingDays;
    }

    int DailyEmployee::getDailySalary() {
        return _DailySalary;
    }
    int DailyEmployee::getWorkingDays() {
        return _WorkingDays;
    }
    
    shared_ptr<Employee>DailyEmployee::clone() {
        return make_shared<DailyEmployee>();
    }
   
    string DailyEmployee::magicWord() { return "DailyEmployee"; }
    
    int DailyEmployee::Payment() {
        return _DailySalary * _WorkingDays;
    }
    
    DailyEmployee::~DailyEmployee() {};

    
     bool DailyEmployeeDataConverter::isValidFormart(string value) {
         regex parttern("[A-Za-z]+: ([A-Za-z]+ ){1,3}  [A-Za-z]+=[0-9]+\\$; [A-za-z]+\\=\\d+");
         bool result = regex_match(value, parttern);
         return result;
     }

     string DailyEmployeeDataConverter::convert(shared_ptr<Employee> employee) {
         auto temp = static_pointer_cast<DailyEmployee>(employee);
         stringstream builder;
         builder << "Name Employee: " << temp->getName()
             << "\n      Type of Employee: " << temp->magicWord()
             << "\n      Daily Payment= " << to_string(temp->getDailySalary()) << "$"
             << "\n      Total Days= " << to_string(temp->getWorkingDays())
             << "\n      Final Payment= " << to_string(temp->Payment()) << "$";
         string result = builder.str();
         return result;
     }

     shared_ptr<IConvert> DailyEmployeeDataConverter::clone() {
         return make_shared<DailyEmployeeDataConverter>();
     }

     tuple<bool, shared_ptr<Employee>>DailyEmployeeDataConverter::convertBack(string str) {
         shared_ptr<DailyEmployee> dailyEmployee = make_shared<DailyEmployee>();
         if (isValidFormart(str) == true) {
             stringstream ss(str);
             string buffer;
             getline(ss, buffer, ' ');
             getline(ss, buffer, ' ');
             string str = buffer + " ";
             getline(ss, buffer, ' ');
             buffer = str + buffer;
             dailyEmployee->setName(buffer);
             getline(ss, buffer, '=');
             getline(ss, buffer, '$');
             dailyEmployee->setDailySalary(stoi(buffer));
             getline(ss, buffer, '=');
             getline(ss, buffer, '\0');
             dailyEmployee->setWorkingDays(stoi(buffer));
         }
         else {
             return make_tuple(false, dailyEmployee);
         }
         return make_tuple(true, dailyEmployee);
     }