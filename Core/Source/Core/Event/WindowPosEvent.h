#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class WindowPosEvent : public Event
{
public:
    WindowPosEvent(int xpos, int ypos)
        : xpos_(xpos), ypos_(ypos)
    {

    }
    ~WindowPosEvent() = default;

    EventType Type() const override
    {
        return EventType::WindowPosEvent;
    }

    int XPos() const
    {
        return xpos_;
    }

    int YPos() const
    {
        return ypos_;
    }

    void Pos(int* xpos, int* ypos)
    {
        *xpos = xpos_;
        *ypos = ypos_;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[WindowPosEvent]{";

        os << " xpos:" << xpos_;
        os << " ypos:" << ypos_;

        os << " }\n";
    }
private:
    int xpos_{};
    int ypos_{};
};

}