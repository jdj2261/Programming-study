#include <iostream>
#include "database/database.h"

using namespace Records;

int main()
{
    Database myDB;
    Employee& emp1 = myDB.addEmployee("Jin", "Dae Jong");
    emp1.fire();

    Employee& emp2 = myDB.addEmployee("Kim", "Ji Su");
    emp2.setSalary(100000);

    Employee& emp3 = myDB.addEmployee("Lee", "Min Ji");
    emp3.setSalary(10000);
    emp3.promote();

    std::cout << "all employees: " << std::endl << std::endl;
    myDB.displayAll();

    std::cout << std::endl <<"current employees: " << std::endl << std::endl;
    myDB.displayCurrent();

    std::cout << std::endl <<"former employees: " << std::endl << std::endl;
    myDB.displayFormer();
}
