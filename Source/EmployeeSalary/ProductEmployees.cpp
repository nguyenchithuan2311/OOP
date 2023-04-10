#include"ProductEmployees.h"

    ProductEmployees::ProductEmployees() {};
    
    ProductEmployees::ProductEmployees(int PaymentProduct, int TotalProduct) {
        _PaymentProduct = PaymentProduct;
        _TotalProduct = TotalProduct;
    }

    void ProductEmployees::setPaymentProduct(int PaymentProduct) {
        _PaymentProduct = PaymentProduct;
    }

    void ProductEmployees::setTotalProduct(int TotalProduct) {
        _TotalProduct = TotalProduct;
    }

    int ProductEmployees::getPaymentProduct() {
        return _PaymentProduct;
    }

    int ProductEmployees::getTotalProduct() {
        return _TotalProduct;
    }

    shared_ptr<Employee>ProductEmployees::clone() {
        return make_shared<ProductEmployees>();
    }

    string ProductEmployees::magicWord() { return "ProductEmployee"; }
    
    int ProductEmployees::Payment() {
        return _PaymentProduct * _TotalProduct;
    }
    
    ProductEmployees::~ProductEmployees() {};

    
        bool ProductEmployeesDataConveter::isValidFormart(string value) {
            regex parttern("[A-Za-z]+: ([A-Za-z]+ ){1,3}  [A-Za-z]+=[0-9]+\\$; [A-za-z]+\\=\\d+");
            bool result = regex_match(value, parttern);
            return result;
        }
        string ProductEmployeesDataConveter::convert(shared_ptr<Employee> employee) {
            auto temp = static_pointer_cast<ProductEmployees>(employee);
            stringstream builder;
            builder << "Name Employee: " << temp->getName()
                << "\n      Type of Employee: " << temp->magicWord()
                << "\n      Payment Per Product= " << to_string(temp->getPaymentProduct()) << "$"
                << "\n      Total Products= " << to_string(temp->getTotalProduct())
                << "\n      Final Payment= " << to_string(temp->Payment()) << "$";
            string result = builder.str();
            return result;
        }
        shared_ptr<IConvert> ProductEmployeesDataConveter::clone() {
            return make_shared<ProductEmployeesDataConveter>();
        }
        tuple<bool, shared_ptr<Employee>>ProductEmployeesDataConveter::convertBack(string str) {
            shared_ptr<ProductEmployees> productEmployees = make_shared<ProductEmployees>();
            if (isValidFormart(str) == true) {
                stringstream ss(str);
                string buffer;
                getline(ss, buffer, ' ');
                getline(ss, buffer, ' ');
                string str = buffer + " ";
                getline(ss, buffer, ' ');
                buffer = str + buffer;
                productEmployees->setName(buffer);
                getline(ss, buffer, '=');
                getline(ss, buffer, '$');
                productEmployees->setPaymentProduct(stoi(buffer));
                getline(ss, buffer, '=');
                getline(ss, buffer, '\0');
                productEmployees->setTotalProduct(stoi(buffer));
            }
            else {
                return make_tuple(false, productEmployees);
            }
            return make_tuple(true, productEmployees);
        }
