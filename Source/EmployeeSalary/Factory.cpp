#include"Factory.h"

    EmployeesFactory::EmployeesFactory() {
        auto Employee1 = make_shared<DailyEmployee>();
        auto Employee2 = make_shared<HourlyEmployees>();
        auto Employee3 = make_shared<ProductEmployees>();
        auto Employee4 = make_shared<Manager>();

        _prototypes.insert({ "DailyEmployee", Employee1 });
        _prototypes.insert({ "HourlyEmployee", Employee2 });
        _prototypes.insert({ "ProductEmployee", Employee3 });
        _prototypes.insert({ "Manager", Employee4 });
    }

    shared_ptr<EmployeesFactory> EmployeesFactory::instance() {
        if (_instance == NULL) {
            auto temp = new EmployeesFactory();
            _instance = make_shared<EmployeesFactory>(*temp);
        }
        return _instance;
    }

    shared_ptr<Employee> EmployeesFactory::create(string choice) {
        auto prototype = _prototypes[choice];
        auto result = prototype->clone();
        return result;
    }

    
    ConvertFactory::ConvertFactory() {
            auto e1 = make_shared<DailyEmployeeDataConverter>();
            auto e2 = make_shared<HourlyEmployeesDataConverter>();
            auto e3 = make_shared<ProductEmployeesDataConveter>();
            auto e4 = make_shared<ManagerDataConveter>();

            _prototypes.insert({ "DailyEmployee", e1 });
            _prototypes.insert({ "HourlyEmployee", e2 });
            _prototypes.insert({ "ProductEmployee", e3 });
            _prototypes.insert({ "Manager", e4 });
        }
       shared_ptr<ConvertFactory> ConvertFactory::instance() {
            if (_instance == NULL) {
                auto temp = new ConvertFactory();
                _instance = make_shared<ConvertFactory>(*temp);
            }
            return _instance;
        }

        shared_ptr<IConvert>ConvertFactory::create(string choice) {
            auto prototype = _prototypes[choice];
            auto result = prototype->clone();
            return result;
        }