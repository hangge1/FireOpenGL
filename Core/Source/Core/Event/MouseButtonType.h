
#pragma once
#include <string>
#include <iostream>

namespace Core::Event {
    
class MouseButtonType
{
public:
    MouseButtonType(int type): m_type(type) {}
    ~MouseButtonType() = default;

    int Type() const { return m_type; }

    static const MouseButtonType LeftButton;
    static const MouseButtonType RightButton;
    static const MouseButtonType MiddleButton;

    bool operator==(const MouseButtonType& other) const
    {
        return m_type == other.m_type;
    }

    bool operator!=(const MouseButtonType& other) const
    {
        return !(*this == other);
    }

    std::string ToString() const
    {
        return m_sMouseButtonTypeNames[m_type];
    }

    friend std::ostream& operator<<(std::ostream& os, const MouseButtonType& mouseButtonType)
    {
        os << mouseButtonType.ToString();
        return os;
    }

private:
    int m_type;
    static const std::string m_sMouseButtonTypeNames[3];
};

}
