#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class WindowSizeEvent : public Event
{
public:
    WindowSizeEvent(int width, int height)
        : m_width(width), m_height(height)
    {

    }
    ~WindowSizeEvent() = default;

    EventType Type() const override
    {
        return EventType::WindowSizeEvent;
    }

    int Width() const
    {
        return m_width;
    }

    int Height() const
    {
        return m_height;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[WindowSizeEvent]{";

        os << " width:" << m_width;
        os << " height:" << m_height;

        os << " }\n";
    }
private:
    int m_width{};
    int m_height{};
};

}