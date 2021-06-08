#pragma once

#include "Person.h"

class Student : public Person
{
private:
    int m_intel;

public:
    Student(const std::string &name_in = "No name", const int &intel_in = 0)
        : Person(name_in), m_intel(intel_in)
    {
    }

    void study()
    {
        std::cout << getName() << " " << std::endl;
    }

    void setIntel(const int &intel_in)
    {
        m_intel = intel_in;
    }

    int getIntel()
    {
        return m_intel;
    }

    friend std::ostream &operator<<(std::ostream &out, const Student &student)
    {
        out << student.getName() << " " << student.m_intel;
        return out;
    }
};