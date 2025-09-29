#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class WindowRefreshEvent : public Event
{
public:
    WindowRefreshEvent() = default;
    ~WindowRefreshEvent() = default;
    
    EventType Type() const override
    {
        return EventType::WindowRefreshEvent;
    }

    void Serialize(std::ostream& os) override
    {
        os << "[WindowRefreshEvent]\n";
    }
};

}