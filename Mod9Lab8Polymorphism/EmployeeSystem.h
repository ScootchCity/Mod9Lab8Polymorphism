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

#ifndef EMPLOYEE_SYSTEM_H_
#define EMPLOYEE_SYSTEM_H_

#include <string>
using namespace std;

class Employee {
public:
	Employee();
	Employee(string name, string ssn);
	virtual ~Employee();
	virtual double calculateSalary() const = 0;
	virtual void displayInfo();
	static int getEmployeeCount();
private:
	string name, ssn;
	static int employeeCount;
};

class FullTimeEmployee : public Employee {
public:
	FullTimeEmployee();
	FullTimeEmployee(string, string, double);
	double calculateSalary() const override;
	void displayInfo();
private:
	double monthlySalary;
};

class PartTimeEmployee : public Employee {
public:
	PartTimeEmployee();
	PartTimeEmployee(string, string, double, int);
	double calculateSalary() const override;
	void displayInfo();
private:
	double hourlyRate;
	int hoursWorked;
};

class ContractEmployee : public Employee {
public:
	ContractEmployee();
	ContractEmployee(string, string, double, int);
	double calculateSalary() const override;
	void displayInfo();
private:
	double contractAmount;
	int contractDurationMonths;
};

#endif // !EMPLOYEE_SYSTEM_H_