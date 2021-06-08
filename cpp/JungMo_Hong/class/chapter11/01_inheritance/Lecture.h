#pragma once

#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <vector>

class Lecture
{
private:
    std::string m_name;

    // Teacher teacher;
    // std::vector<Student> students;
    Teacher *teacher;
    std::vector<Student *> students;

public:
    Lecture(const std::string &name_in)
        : m_name(name_in)
    {
    }

    ~Lecture()
    {
    }

    // void assignTeacher(const Teacher &teacher_input)
    // {
    //     teacher = teacher_input;
    // }

    void assignTeacher(Teacher *const teacher_input)
    {
        teacher = teacher_input;
    }

    // void registerStudent(const Student &student_input)
    // {
    //     students.emplace_back(student_input);
    // }

    void registerStudent(Student *const student_input)
    {
        students.emplace_back(student_input);
    }

    void study()
    {
        std::cout << m_name << " Study " << std::endl
                  << std::endl;
        // for (auto &element : students)
        //     element.setIntel(element.getIntel() + 1);
        for (auto &element : students)
            element->setIntel(element->getIntel() + 1);
    }

    friend std::ostream &operator<<(std::ostream &out, const Lecture &lecture)
    {
        out << "Lecture Name : " << lecture.m_name << std::endl;
        out << *lecture.teacher << std::endl;
        // for (auto element : lecture.students)
        // out << element << std::endl;
        for (auto element : lecture.students)
            out << *element << std::endl;

        return out;
    }
};