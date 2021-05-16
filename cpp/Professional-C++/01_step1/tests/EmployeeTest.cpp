#include <iostream>
#include "employee/employee.h"

using namespace std;
using namespace Records;

int main()
{
    std::cout << "Testing the employee class." << std::endl;
    Employee emp;
    emp.setFirstName("Jin");
    emp.setLastName("Dae Jong");
    emp.setEmployeeNumber(71);
    emp.setSalary(50000);
    emp.promote();
    emp.promote(50);
    emp.hire();
    emp.display();

    return 0;
}
