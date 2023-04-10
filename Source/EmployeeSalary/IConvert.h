#pragma once
class IConvert {
public:
	virtual bool isValidFormart(string value) = 0;
	virtual string convert(shared_ptr<Employee>) = 0;
	virtual shared_ptr<IConvert> clone() = 0;
	virtual tuple<bool, shared_ptr<Employee>>convertBack(string str) = 0;
};