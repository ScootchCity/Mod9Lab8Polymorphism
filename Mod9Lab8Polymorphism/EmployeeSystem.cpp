#include <string>
#include <iostream>
using namespace std;

class Employee {
public:
	Employee() {
		name = "NONE";
		ssn = "NONE";
	}
	Employee(string name, string ssn);
	virtual ~Employee() {
		this->name = name;
		this->ssn = ssn;
		employeeCount++;
	}
	virtual double calculateSalary() const = 0;
	virtual void displayInfo() {
		cout << "Name: " << name << endl;
		cout << "SSN: " << ssn << endl;
	}
	static int getEmployeeCount() {
		return employeeCount;
	}
private:
	string name, ssn;
	static int employeeCount;
};

class FullTimeEmployee : public Employee {
public:
	FullTimeEmployee() {
		monthlySalary = 0;
	}
	FullTimeEmployee(string name, string ssn, double hourlyRate) : Employee(name, ssn) {
		this->monthlySalary = monthlySalary;
	}
	double calculateSalary() { return monthlySalary; }
	void displayInfo() {
		Employee::displayInfo();
		cout << "Type: Full-Time\n";
		cout << 
	}
private:
	double monthlySalary;
};

class PartTimeEmployee : public Employee {
public:
	PartTimeEmployee() {
		hourlyRate = 0;
		hoursWorked = 0;
	}
	PartTimeEmployee(string name, string ssn, double hourlyRate, int hoursWorked) : Employee(name, ssn) {
		this->hourlyRate = hourlyRate;
		this->hoursWorked = hoursWorked;
	}
	double calculateSalary() { return hourlyRate * hoursWorked; }
	void displayInfo() {
		Employee::displayInfo();
	}
private:
	double hourlyRate;
	int hoursWorked;
};

//ADD CONTRACT EMPLOYEE
//FINISH DISPLAYINFO FOR ALL DERIVED