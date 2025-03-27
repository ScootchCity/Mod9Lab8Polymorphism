#include <string>
using namespace std;

class Employee {
public:
	Employee(int name, int ssn);
	virtual ~Employee();
	virtual double calculateSalary();
	virtual void displayInfo();
	static int getEmployeeCount();
private:
	string name, ssn;
	static int employeeCount;
};

class FullTimeEmployee : public Employee {
public:
	FullTimeEmployee();
	double calculateSalary();
	void displayInfo();
private:
	double monthlySalary;
};

class PartTimeEmployee : public Employee {
public:
	PartTimeEmployee();
	double calculateSalary();
	void displayInfo();
private:
	double hourlyRate;
	int hoursWorked;
};