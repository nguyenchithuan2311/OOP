#include"Manager.h"

    Manager::Manager() {};
    
    Manager::Manager(int FixedPayment, int NumberOfWorkers, int PaymentPerEmployee) {
        _FixedPayment = FixedPayment;
        _NumberOfWorkers = NumberOfWorkers;
        _PaymentPerEmployee = PaymentPerEmployee;
    }

    void Manager::setFixedPayment(int FixedPayment) {
        _FixedPayment = FixedPayment;
    }
    
    void Manager::setNumberOfWorkers(int NumberOfWorkers) {
        _NumberOfWorkers = NumberOfWorkers;
    }
    
    void Manager::setPaymentPerEmployee(int PaymentPerEmployee) {
        _PaymentPerEmployee = PaymentPerEmployee;
    }

    int Manager::getFixedPayment() {
        return _FixedPayment;
    }
    
    int Manager::getNumberOfWorkers() {
        return _NumberOfWorkers;
    }
    
    int Manager::getPaymentPerEmployee() {
        return _PaymentPerEmployee;
    }
    
    shared_ptr<Employee>Manager::clone() {
        return make_shared<Manager>();
    }
    
    string Manager::magicWord() { return "Manager"; }
    
    int Manager::Payment() {
        return _NumberOfWorkers * _PaymentPerEmployee + _FixedPayment;
    
    }
    Manager::~Manager() {};

    
        bool ManagerDataConveter::isValidFormart(string value) {
            regex parttern("[A-Za-z]+: ([A-Za-z]+ ){1,2}  [A-Za-z]+=[0-9]+\\$; [A-Za-z]+\\=\\d+; [A-Za-z]+=\\d+\\$");
            bool result = regex_match(value, parttern);
            return result;
        }
        string ManagerDataConveter::convert(shared_ptr<Employee> employee) {
            auto temp = static_pointer_cast<Manager>(employee);
            stringstream builder;
            builder << "Name Employee: " << temp->getName()
                << "\n      Type of Employee: " << temp->magicWord()
                << "\n      FixedPayment= " << to_string(temp->getFixedPayment()) << "$"
                << "\n      Total Employees= " << to_string(temp->getNumberOfWorkers())
                << "\n      Payment Per Employee= " << to_string(temp->getPaymentPerEmployee()) << "$"
                << "\n      Final Payment= " << to_string(temp->Payment()) << "$";
            string result = builder.str();
            return result;
        }
        shared_ptr<IConvert> ManagerDataConveter::clone() {
            return make_shared<ManagerDataConveter>();
        }
        tuple<bool, shared_ptr<Employee>>ManagerDataConveter::convertBack(string str) {
            shared_ptr<Manager> manager = make_shared<Manager>();
            if (isValidFormart(str) == true) {
                stringstream ss(str);
                string buffer;
                getline(ss, buffer, ' ');
                getline(ss, buffer, ' ');
                string str = buffer + " ";
                getline(ss, buffer, ' ');
                buffer = str + buffer;
                manager->setName(buffer);
                getline(ss, buffer, '=');
                getline(ss, buffer, '$');
                manager->setFixedPayment(stoi(buffer));
                getline(ss, buffer, '=');
                getline(ss, buffer, ';');
                manager->setNumberOfWorkers(stoi(buffer));
                getline(ss, buffer, '=');
                getline(ss, buffer, '$');
                manager->setPaymentPerEmployee(stoi(buffer));
            }
            else {
                return make_tuple(false, manager);
            }
            return make_tuple(true, manager);
        }