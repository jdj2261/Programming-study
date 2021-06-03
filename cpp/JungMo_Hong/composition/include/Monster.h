#pragma once

#include "Position2D.h"
#include <string>

class Monster
{
private:
    std::string m_name;
    Position2D m_location;
    // int m_x;
    // int m_y;

public:
    Monster(const std::string name_in, const Position2D &pos_in)
        : m_name(name_in), m_location(pos_in)
    {
    }

    void moveTo(const Position2D &pos_target)
    {
        m_location.set(pos_target);
    }

    friend std::ostream &operator<<(std::ostream &out, const Monster &monster)
    {
        out << monster.m_name << " " << monster.m_location;
        return out;
    }
};