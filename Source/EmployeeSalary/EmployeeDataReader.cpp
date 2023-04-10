#include"EmployeeDataReader.h"

    EmployeeDataReader::EmployeeDataReader(string connectString) {
        _connectString = connectString;
    }
    tuple<bool, vector<shared_ptr<Employee>>> EmployeeDataReader::GetAll() {
        ifstream fi;
        vector<shared_ptr<Employee>> list;
        fi.open(_connectString, ios::in);
        string buffer;
        shared_ptr<Employee> temp;
        bool success;
        while (getline(fi, buffer)) {
            string str = buffer;
            stringstream ss(buffer);
            getline(ss, buffer, ':');
            auto type = EmployeesFactory::instance()->create(buffer);
            auto x = ConvertFactory::instance();
            auto convert = x->create(type->magicWord());
            getline(fi, buffer);
            str = str + buffer;
            tie(success, temp) = convert->convertBack(str);
            if (success == false) {
                return make_tuple(false, list);
            }
            list.push_back(temp);
        }
        return make_tuple(true, list);
    }