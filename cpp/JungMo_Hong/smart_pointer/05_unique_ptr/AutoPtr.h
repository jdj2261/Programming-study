#pragma once

#include <iostream>

template <class T>
class AutoPtr
{
public:
    T *m_ptr;

public:
    AutoPtr(T *ptr = nullptr)
        : m_ptr(ptr)
    {
        std::cout << "AutoPtr default constructor " << std::endl;
    }

    ~AutoPtr()
    {
        std::cout << "AutoPtr destructor " << std::endl;
        if (m_ptr != nullptr)
            delete m_ptr;
    }

    AutoPtr(const AutoPtr &a)
    {
        std::cout << "AutoPtr copy constructor " << std::endl;

        // deep copy
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    AutoPtr &operator=(const AutoPtr &a)
    {
        std::cout << "AutoPtr copy assignment " << std::endl;

        if (&a == this)
            return *this;

        if (m_ptr != nullptr)
            delete m_ptr;

        // deep copy
        m_ptr = new T;
        *m_ptr = *a.m_ptr;

        return *this;
    }

    // AutoPtr(const AutoPtr& a) = delete;
    // AutoPtr& operator=(const AutoPtr& a) = delete;

    // Copy constructor가 아니다.
    AutoPtr(AutoPtr &&a)
        : m_ptr(a.m_ptr)
    {
        std::cout << "AutoPtr move constructor " << std::endl;
        a.m_ptr = nullptr;
    }

    AutoPtr &operator=(AutoPtr &&a)
    {
        std::cout << "AutoPtr move assignement " << std::endl;
        if (&a == this)
            return *this;

        if (!m_ptr)
            delete m_ptr;

        // shallow copy
        // 메모리의 첫 주소만 복사
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;

        return *this;
    }

    T &operator*() const { return *m_ptr; }
    T *operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};