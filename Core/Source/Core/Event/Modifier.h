
#pragma once

#include <iostream>

#define LEFT_SHIFT(V, S) (V << S)

namespace Core::Event
{

class Modifier
{
    enum Mods
    {
        ModShift = LEFT_SHIFT(0x1, 0),
        ModCtrl = LEFT_SHIFT(0x1, 1),
        ModAlt = LEFT_SHIFT(0x1, 2),
    };

public:
    Modifier(int mods) : mods_(mods) {}

    static const Modifier None() { return Modifier(0); }
    static const Modifier Shift() { return Modifier(ModShift); }
    static const Modifier Ctrl() { return Modifier(ModCtrl); }
    static const Modifier Alt() { return Modifier(ModAlt); }
    static const Modifier ShiftCtrl() { return Modifier(ModShift | ModCtrl); }
    static const Modifier ShiftAlt() { return Modifier(ModShift | ModAlt); }
    static const Modifier CtrlAlt() { return Modifier(ModCtrl | ModAlt); }
    static const Modifier ShiftCtrlAlt() { return Modifier(ModShift | ModCtrl | ModAlt); }

    bool IsAlt() const { return mods_ & static_cast<unsigned char>(ModAlt); }
    bool IsCtrl() const { return mods_ & static_cast<unsigned char>(ModCtrl); }
    bool IsShift() const { return mods_ & static_cast<unsigned char>(ModShift); }
    
    bool operator==(const Modifier& other) const
    {
        return mods_ == other.mods_;
    }

    bool operator!=(const Modifier& other) const
    {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Modifier& modifier)
    {
        os << "Modifier{";
        if (modifier.IsAlt()) os << "Alt ";
        if (modifier.IsCtrl()) os << "Ctrl ";
        if (modifier.IsShift()) os << "Shift";
        os << "}";
        return os;
    }
private:
    unsigned char mods_{};
};

}