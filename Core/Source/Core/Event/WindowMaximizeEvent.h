#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class WindowMaximizeEvent : public Event
{
public:
    WindowMaximizeEvent(int maximized)
        : maximized_(maximized)
    {

    }
    ~WindowMaximizeEvent() = default;

    EventType Type() const override
    {
        return EventType::WindowMaximizeEvent;
    }

    int Maximized() const
    {
        return maximized_;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[WindowMaximizeEvent]{";

        os << " maximized:" << maximized_;

        os << " }\n";
    }
private:
    int maximized_{};
};

}