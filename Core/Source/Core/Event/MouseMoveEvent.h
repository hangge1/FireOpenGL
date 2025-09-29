#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class MouseMoveEvent : public Event
{
public:
    MouseMoveEvent(double xpos, double ypos)
        : xpos_(xpos),
          ypos_(ypos)
    {

    }
    ~MouseMoveEvent() = default;

    EventType Type() const override
    {
        return EventType::MouseMoveEvent;
    }

    double XPos() const
    {
        return xpos_;
    }

    double YPos() const
    {
        return ypos_;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[MouseMoveEvent]{";

        os << " xpos:" << xpos_;
        os << " ypos:" << ypos_;

        os << " }\n";
    }
private:
    double xpos_{};
    double ypos_{};
};

}