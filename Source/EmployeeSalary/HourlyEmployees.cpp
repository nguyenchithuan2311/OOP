#include"HourlyEmployees.h"

    HourlyEmployees::HourlyEmployees() {};
    
    HourlyEmployees::HourlyEmployees(int HourlySalary, int WorkingHours) {
        _HourlySalary = HourlySalary;
        _WorkingHours = WorkingHours;
    };

    void HourlyEmployees::setHourlySalary(int HourlySalary) {
        _HourlySalary = HourlySalary;
    }
    
    void HourlyEmployees::setWorkingHours(int WorkingHours) {
        _WorkingHours = WorkingHours;
    }

    int HourlyEmployees::getHourlySalary() {
        return _HourlySalary;
    }
    
    int HourlyEmployees::getWorkingHours() {
        return _WorkingHours;
    }
    
    shared_ptr<Employee>HourlyEmployees::clone() {
        return make_shared<HourlyEmployees>();
    }
    
    string HourlyEmployees::magicWord() { return "HourlyEmployee"; }
    
    int HourlyEmployees::Payment() {
        return _HourlySalary * _WorkingHours;
    }
    
    HourlyEmployees::~HourlyEmployees() {};
    
    bool HourlyEmployeesDataConverter::isValidFormart(string value) {
        regex parttern("[A-Za-z]+: ([A-Za-z]+ ){1,3}  [A-Za-z]+=[0-9]+\\$; [A-za-z]+\\=\\d+");
        bool result = regex_match(value, parttern);
        return result;
    }
    

    string HourlyEmployeesDataConverter::convert(shared_ptr<Employee> employee) {
        auto temp = static_pointer_cast<HourlyEmployees>(employee);
        stringstream builder;
        builder << "Name Employee: " << temp->getName()
            << "\n      Type of Employee: " << temp->magicWord()
            << "\n      Hourly Payment= " << to_string(temp->getHourlySalary()) << "$"
            << "\n      Total Hours= " << to_string(temp->getWorkingHours())
            << "\n      Final Payment= " << to_string(temp->Payment()) << "$";
        string result = builder.str();
        return result;
    }

    shared_ptr<IConvert> HourlyEmployeesDataConverter::clone() {
        return make_shared<HourlyEmployeesDataConverter>();
    }

    tuple<bool, shared_ptr<Employee>>HourlyEmployeesDataConverter::convertBack(string str) {
        shared_ptr<HourlyEmployees> hourlyEmployees = make_shared<HourlyEmployees>();
        if (isValidFormart(str) == true) {
            stringstream ss(str);
            string buffer;
            getline(ss, buffer, ' ');
            getline(ss, buffer, ' ');
            string str = buffer + " ";
            getline(ss, buffer, ' ');
            buffer = str + buffer;
            hourlyEmployees->setName(buffer);
            getline(ss, buffer, '=');
            getline(ss, buffer, '$');
            hourlyEmployees->setHourlySalary(stoi(buffer));
            getline(ss, buffer, '=');
            getline(ss, buffer, '\0');
            hourlyEmployees->setWorkingHours(stoi(buffer));
        }
        else {
            return make_tuple(false, hourlyEmployees);
        }
        return make_tuple(true, hourlyEmployees);
    }