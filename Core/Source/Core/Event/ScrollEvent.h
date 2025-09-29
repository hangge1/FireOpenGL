#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class ScrollEvent : public Event
{
public:
    ScrollEvent(double xoffset, double yoffset)
        : xoffset_(xoffset),
          yoffset_(yoffset)
    {

    }
    ~ScrollEvent() = default;

    EventType Type() const override
    {
        return EventType::ScrollEvent;
    }

    double XOffset() const
    {
        return xoffset_;
    }

    double YOffset() const
    {
        return yoffset_;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[ScrollEvent]{";

        os << " xoffset:" << xoffset_;
        os << " yoffset:" << yoffset_;

        os << " }\n";
    }
private:
    double xoffset_{};
    double yoffset_{};
};

}