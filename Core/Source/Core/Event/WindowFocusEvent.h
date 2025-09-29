#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class WindowFocusEvent : public Event
{
public:
    WindowFocusEvent(int focused)
        : focused_(focused)
    {

    }
    ~WindowFocusEvent() = default;

    EventType Type() const override
    {
        return EventType::WindowFocusEvent;
    }

    int Focused() const
    {
        return focused_;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[WindowFocusEvent]{";

        os << " focus:" << focused_;

        os << " }\n";
    }
private:
    int focused_{};
};

}