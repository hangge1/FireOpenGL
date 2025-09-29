
#pragma once
#include <string>
#include <iostream>

namespace Core::Event {
    
class MouseButtonType
{
public:
    MouseButtonType(int type): type_(type) {}
    ~MouseButtonType() = default;

    int Type() const { return type_; }

    static const MouseButtonType LeftButton;
    static const MouseButtonType RightButton;
    static const MouseButtonType MiddleButton;

    bool operator==(const MouseButtonType& other) const
    {
        return type_ == other.type_;
    }

    bool operator!=(const MouseButtonType& other) const
    {
        return !(*this == other);
    }

    std::string ToString() const
    {
        return MouseButtonTypeNames[type_];
    }

    friend std::ostream& operator<<(std::ostream& os, const MouseButtonType& mouseButtonType)
    {
        os << mouseButtonType.ToString();
        return os;
    }

private:
    int type_;
    static const std::string MouseButtonTypeNames[3];
};

}
