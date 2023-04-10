#include"EmployeeDataReader.h"

int main()
{
    EmployeeDataReader edr("November2021.txt");
    vector<shared_ptr<Employee>> list;
    bool success;
    tie(success, list) = edr.GetAll();
    if (success == true) {
        for (int i = 0; i < list.size(); i = i + 1) {
            auto temp = ConvertFactory::instance();
            auto convert = temp->create(list[i]->magicWord());
            cout << i + 1 << "." << convert->convert(list[i]) << endl;
        }
    }
    else {
        cout << "Invalid formart";
    }
    cin.get();
}