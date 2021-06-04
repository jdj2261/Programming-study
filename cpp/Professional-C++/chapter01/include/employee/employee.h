#pragma once
#include <string>
namespace Records
{
    // If it is a constant value, the variable name starts with k(Konstant)
    const int kDefaultStartingSalary = 3000;
    class Employee
    {
    public:
        Employee() = default;
        Employee(const std::string& firstName,
                 const std::string& lastName);

        void promote(int raiseAmount = 1000);
        void demote(int demeritAmount = 1000);
        void hire();
        void fire();
        void display() const;

        // getter, setter
        void setFirstName(const std::string& firstName);
        const std::string& getFirstName() const;

        void setLastName(const std::string& lastName);
        const std::string& getLastName() const;

        void setEmployeeNumber(int employeenumber);
        int getEmployeeNumber() const;

        void setSalary(int newSalary);
        int getSalary() const;

        bool isHired() const;

    private:
        std::string mFirstName;
        std::string mLastName;
        int mEmployeeNumber = -1;
        int mSalary = kDefaultStartingSalary;
        bool mHired = false;
    };
}


