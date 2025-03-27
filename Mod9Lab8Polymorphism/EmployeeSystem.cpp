/*
Author        : Lloyd Ivester
Class         : CSI - 240 : Advanced Programming
Assignment    : Module 9 Lab 78 Polymorphism
Date Assigned : 27/3/25
Due Date      : 3/4/25

Project Description :
A payroll system that models different types of employees.
Each employee type calculates salary differently, and polymorphism will be used to handle them in a unified way.

Certification of Authenticity :

I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/

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