#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class WindowFocusEvent : public Event
{
public:
    WindowFocusEvent(int focused)
        : m_focused(focused)
    {

    }
    ~WindowFocusEvent() = default;

    EventType Type() const override
    {
        return EventType::WindowFocusEvent;
    }

    int Focused() const
    {
        return m_focused;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[WindowFocusEvent]{";

        os << " focus:" << m_focused;

        os << " }\n";
    }
private:
    int m_focused{};
};

}