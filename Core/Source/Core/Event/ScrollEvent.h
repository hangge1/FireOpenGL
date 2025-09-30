#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class ScrollEvent : public Event
{
public:
    ScrollEvent(double xoffset, double yoffset)
        : m_xoffset(xoffset),
          m_yoffset(yoffset)
    {

    }
    ~ScrollEvent() = default;

    EventType Type() const override
    {
        return EventType::ScrollEvent;
    }

    double XOffset() const
    {
        return m_xoffset;
    }

    double YOffset() const
    {
        return m_yoffset;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[ScrollEvent]{";

        os << " xoffset:" << m_xoffset;
        os << " yoffset:" << m_yoffset;

        os << " }\n";
    }
private:
    double m_xoffset{};
    double m_yoffset{};
};

}