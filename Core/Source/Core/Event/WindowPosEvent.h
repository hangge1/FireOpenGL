#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class WindowPosEvent : public Event
{
public:
    WindowPosEvent(int xpos, int ypos)
        : m_xpos(xpos), m_ypos(ypos)
    {

    }
    ~WindowPosEvent() = default;

    EventType Type() const override
    {
        return EventType::WindowPosEvent;
    }

    int XPos() const
    {
        return m_xpos;
    }

    int YPos() const
    {
        return m_ypos;
    }

    void Pos(int* xpos, int* ypos)
    {
        *xpos = m_xpos;
        *ypos = m_ypos;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[WindowPosEvent]{";

        os << " xpos:" << m_xpos;
        os << " ypos:" << m_ypos;

        os << " }\n";
    }
private:
    int m_xpos{};
    int m_ypos{};
};

}