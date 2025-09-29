#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class TitleBarHitTestEvent : public Event
{
public:
    TitleBarHitTestEvent(int xpos, int ypos, int* hit)
        : xpos_(xpos),
          ypos_(ypos),
          hit_(hit)
    {

    }
    ~TitleBarHitTestEvent() = default;

    EventType Type() const override
    {
        return EventType::TitleBarHitTestEvent;
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

    int* Hit() const
    {
        return hit_;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[TitleBarHitTestEvent]{";

        os << " xpos:" << xpos_;
    }

private:
    int xpos_{};
    int ypos_{};
    int* hit_{};
};
}