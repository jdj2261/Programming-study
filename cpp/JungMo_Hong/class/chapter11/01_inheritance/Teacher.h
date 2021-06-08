#pragma once

#include "Person.h"

class Teacher : public Person
{
private:
public:
    Teacher(const std::string &name_in = "No name")
        : Person(name_in)
    {
    }
    void teach()
    {
        std::cout << getName() << " " << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &out, const Teacher &teacher)
    {
        // out << teacher.m_name;
        out << teacher.getName();
        return out;
    }
};