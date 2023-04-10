Fullname:
Nguyen Chi Thuan

Student's ID:
20127346

Any notice on how to compile and run my project?
 - Text editor: Visual Studio Code
 - Use c++ version 17
I also compiled and run my project on Visual Studio Community 2019 version and work successfully so I demonstrated my project on Visual Studio Code for easy viewing.

All things I listed below are what I have done in this project:
 1. Read the file
         - To do this task, I created and used class EmployeeDataReader
	- With class EmployeeDataReader, I use one private member is the name of file to know what is the file I want to read them. 
	- GetAll() will find the name of file and start to read file, also save data they read into vector<shared_ptr<Employee>>>.
	- EmployeeDataReader uses 2 classes EmployeesFactory, ConvertFactory to create an object and polymorphism to create a Factory pattern that performs the above request.
 2. Print out all the employees' information and the final payment for each employee.
         - To do this task, I created and used class IConvert, DailyEmployeeDataConverter, HourlyEmployees, ProductEmployeesDataConveter, Manager
	- With the data I read earlier, adding polymorphism I wrote the function convert(shared_ptr<Employee> employee), int Payment() to do the above requirement
What I have not done:
None.

What should be taken into account for a bonus?
clear file division, detailed comment, detect when the file format is wrong

Expected grade:
10.0
Link Video Demo: https://youtu.be/LUPYTeCV91A