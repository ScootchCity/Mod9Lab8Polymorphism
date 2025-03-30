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
#include "EmployeeSystem.h"
using namespace std;

//EMPLOYEE
Employee::Employee() {
	name = "NONE";
	ssn = "NONE";
	employeeCount++;
	//cout << "EMPLOYEE BASE\n";
}
Employee::Employee(string name, string ssn) {
	this->name = name;
	this->ssn = ssn;
	employeeCount++;
	//cout << "EMPLOYEE PERAM\n";
}
Employee::~Employee() {};
//double Employee::calculateSalary() {};
void Employee::displayInfo() {
	cout << "Name: " << name << endl;
	cout << "SSN: " << ssn << endl;
}
int Employee::getEmployeeCount() {
	return employeeCount;
}
int Employee::employeeCount = 0;

//FULL TIME
FullTimeEmployee::FullTimeEmployee() {
	monthlySalary = 0;
	//cout << "FULL-TIME BASE\n";
}
FullTimeEmployee::FullTimeEmployee(string name, string ssn, double monthlySalary) : Employee(name, ssn) {
	this->monthlySalary = monthlySalary;
	//cout << "FULL-TIME PERAM\n";
}
double FullTimeEmployee::calculateSalary() const { return monthlySalary; }
void FullTimeEmployee::displayInfo() {
	Employee::displayInfo();
	cout << "Type: Full-Time\n";
	cout << "Monthly Salary: $" << monthlySalary << endl;
	cout << "Calculated Salary: $" << calculateSalary() << endl;
}

//PART TIME
PartTimeEmployee::PartTimeEmployee() {
	hourlyRate = 0;
	hoursWorked = 0;
	//cout << "PART-TIME BASE\n";
}
PartTimeEmployee::PartTimeEmployee(string name, string ssn, double hourlyRate, int hoursWorked) : Employee(name, ssn) {
	this->hourlyRate = hourlyRate;
	this->hoursWorked = hoursWorked;
	//cout << "PART-TIME PERAM\n";
}
double PartTimeEmployee::calculateSalary() const { return hourlyRate * hoursWorked; }
void PartTimeEmployee::displayInfo() {
	Employee::displayInfo();
	cout << "Type: Part-Time\n";
	cout << "Hourly Rate: $" << hourlyRate << endl;
	cout << "Hours Worked: " << hoursWorked << endl;
	cout << "Calculated Salary: $" << calculateSalary() << endl;
}

//CONTRACT
ContractEmployee::ContractEmployee() {
	contractAmount = 0;
	contractDurationMonths = 0;
	//cout << "CONTRACT BASE\n";
}
ContractEmployee::ContractEmployee(string name, string ssn, double contractAmount, int contractDurationMonths) : Employee(name, ssn) {
	this->contractAmount = contractAmount;
	this->contractDurationMonths = contractDurationMonths;
	//cout << "CONTRACT PERAM\n";
}
double ContractEmployee::calculateSalary() const { return contractAmount / contractDurationMonths; }
void ContractEmployee::displayInfo() {
	Employee::displayInfo();
	cout << "Type: Contract\n";
	cout << "Contract Amount: $" << contractAmount << endl;
	cout << "Contract Duration: " << contractDurationMonths << endl;
	cout << "Calculated Salary: $" << calculateSalary() << endl;
}