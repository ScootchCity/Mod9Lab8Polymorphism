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

#include <iostream>
#include <vector>
#include "EmployeeSystem.h"
using namespace std;

int main()
{
    vector<Employee*> employeeList;
    employeeList.push_back(new FullTimeEmployee("John Doe", "123-45-6789", 5000.00));
    employeeList.push_back(new PartTimeEmployee("Jane Smith", "234-56-7890", 20.00, 60));
    employeeList.push_back(new ContractEmployee("Alex Johnson", "345-67-8901", 18000.00, 6));


    cout << "--- Employee Information ---\n";
    for (int i = 0; i < employeeList.size(); i++) {
        
        /*
        Employee* currentEmployee = employeeList.at(i);
        currentEmployee->displayInfo();
        */

        //Jan method
        Employee& currentEmployee = *(employeeList.at(i));
        currentEmployee.displayInfo();
        
        cout << endl;
    }
    cout << "Total number of employees: " << Employee::getEmployeeCount() << endl;
}