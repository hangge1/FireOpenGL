#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class WindowMaximizeEvent : public Event
{
public:
    WindowMaximizeEvent(int maximized)
        : m_maximized(maximized)
    {

    }
    ~WindowMaximizeEvent() = default;

    EventType Type() const override
    {
        return EventType::WindowMaximizeEvent;
    }

    int Maximized() const
    {
        return m_maximized;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[WindowMaximizeEvent]{";

        os << " maximized:" << m_maximized;

        os << " }\n";
    }
private:
    int m_maximized{};
};

}