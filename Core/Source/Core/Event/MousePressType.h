#pragma once

#include <string>
#include <iostream>

namespace Core::Event {
    
class MousePressType
{
public:
    MousePressType(int type): type_(type) {}
    ~MousePressType() = default;

    int Type() const { return type_; }

    static const MousePressType Release;
    static const MousePressType Press;

    bool operator==(const MousePressType& other) const
    {
        return type_ == other.type_;
    }

    bool operator!=(const MousePressType& other) const
    {
        return !(*this == other);
    }

    std::string ToString() const
    {
        return MousePressTypeNames[type_];
    }

    friend std::ostream& operator<<(std::ostream& os, const MousePressType& mousePressType)
    {
        os << mousePressType.ToString();
        return os;
    }

private:
    int type_;
    static const std::string MousePressTypeNames[2];
};
}