#pragma once

#include <iostream>
#include <sstream>

namespace Core::Event {

    enum class EventType : unsigned int
    {
        WindowPosEvent,
        WindowSizeEvent,
        WindowRefreshEvent,
        WindowFocusEvent,
        WindowMaximizeEvent,
        TitleBarHitTestEvent,
        KeyEvent,
        MouseButtonEvent,
        ScrollEvent,
        MouseMoveEvent,

        UserEvent = 0x1000,
        MaxEvent = 0xFFFFFFFF
    };

	class Event
	{
    public:
        Event() = default;
        ~Event() = default;
        Event(const Event&) = delete;
        Event& operator=(const Event&) = delete;

        virtual EventType Type() const = 0;

        virtual std::string ToString();

        friend std::ostream& operator<<(std::ostream& os, Event& ev)
        {
            ev.Serialize(os);
            return os;
        }
    protected:
        virtual void Serialize(std::ostream& os) { }
	};
}