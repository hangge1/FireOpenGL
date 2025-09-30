#pragma once

#include <string>
#include <iostream>

namespace Core::Event {
    
class MousePressType
{
public:
    MousePressType(int type): m_type(type) {}
    ~MousePressType() = default;

    int Type() const { return m_type; }

    static const MousePressType Release;
    static const MousePressType Press;

    bool operator==(const MousePressType& other) const
    {
        return m_type == other.m_type;
    }

    bool operator!=(const MousePressType& other) const
    {
        return !(*this == other);
    }

    std::string ToString() const
    {
        return m_sMousePressTypeNames[m_type];
    }

    friend std::ostream& operator<<(std::ostream& os, const MousePressType& mousePressType)
    {
        os << mousePressType.ToString();
        return os;
    }

private:
    int m_type;
    static const std::string m_sMousePressTypeNames[2];
};
}