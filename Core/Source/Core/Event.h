#pragma once

#include <iostream>
#include <sstream>

namespace Core {

    enum class EventType : unsigned int
    {
        KeyEvent,
        WindowPosEvent,
        WindowMaximizeEvent,
        TitleBarHitTestEvent,
        WindowSizeEvent,
        WindowRefreshEvent,
        WindowFocusEvent,

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

        virtual std::string ToString()
        {
            std::stringstream ss;
            Serialize(ss);
            return ss.str();
        }

        friend std::ostream& operator<<(std::ostream& os, Event& ev)
        {
            ev.Serialize(os);
            return os;
        }
    protected:
        virtual void Serialize(std::ostream& os) { }
	};

    class KeyEvent : public Event
    {
    public:
        KeyEvent(int key, int scancode, int action, int mods)
            : key_(key), scancode_(scancode), action_(action), mods_(mods)
        {

        }

        EventType Type() const override
        {
            return EventType::KeyEvent;
        }

        int Key() const
        {
            return key_;
        }

        int ScanCode() const
        {
            return scancode_;
        }

        int Action() const
        {
            return action_;
        }

        int Mods() const
        {
            return mods_;
        }

        void Serialize(std::ostream& os) override
        {
            os << "[KeyEvent]{";

            os << " key:" << key_;
            os << " scancode:" << scancode_;
            os << " action:" << action_;
            os << " mods:" << mods_;

            os << " }\n";
        }
    private:
        int key_;
        int scancode_;
        int action_;
        int mods_;
    };

    class WindowPosEvent : public Event
    {
    public:
        WindowPosEvent(int xpos, int ypos)
            : xpos_(xpos), ypos_(ypos)
        {

        }

        EventType Type() const override
        {
            return EventType::WindowPosEvent;
        }

        int XPos() const
        {
            return xpos_;
        }

        int YPos() const
        {
            return ypos_;
        }

        void Pos(int* xpos, int* ypos)
        {
            *xpos = xpos_;
            *ypos = ypos_;
        }

        void Serialize(std::ostream& os) override
        {
            os << "[WindowPosEvent]{";

            os << " xpos:" << xpos_;
            os << " ypos:" << ypos_;

            os << " }\n";
        }
    private:
        int xpos_;
        int ypos_;
    };

    class WindowMaximizeEvent : public Event
    {
    public:
        WindowMaximizeEvent(int maximized)
            : maximized_(maximized)
        {

        }

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
        int maximized_;
    };

    class TitleBarHitTestEvent : public Event
    {
    public:
        TitleBarHitTestEvent(int xpos, int ypos, int* hit)
            : xpos_(xpos),
              ypos_(ypos),
              hit_(hit)
        {

        }

        EventType Type() const override
        {
            return EventType::TitleBarHitTestEvent;
        }

        int XPos() const
        {
            return xpos_;
        }

        int YPos() const
        {
            return ypos_;
        }

        void Pos(int* xpos, int* ypos)
        {
            *xpos = xpos_;
            *ypos = ypos_;
        }

        int* Hit() const
        {
            return hit_;
        }

        void Serialize(std::ostream& os) override
        {
            os << "[TitleBarHitTestEvent]{";

            os << " xpos:" << xpos_;
            os << " ypos:" << ypos_;

            os << " }\n";
        }
    private:
        int xpos_;
        int ypos_;
        int* hit_;
    };

    class WindowSizeEvent : public Event
    {
    public:
        WindowSizeEvent(int width, int height)
            : width_(width), height_(height)
        {

        }

        EventType Type() const override
        {
            return EventType::WindowSizeEvent;
        }

        int Width() const
        {
            return width_;
        }

        int Height() const
        {
            return height_;
        }

        void Serialize(std::ostream& os) override
        {
            os << "[WindowSizeEvent]{";

            os << " width:" << width_;
            os << " height:" << height_;

            os << " }\n";
        }
    private:
        int width_;
        int height_;
    };

    class WindowRefreshEvent : public Event
    {
    public:
        WindowRefreshEvent() = default;

        EventType Type() const override
        {
            return EventType::WindowRefreshEvent;
        }

        void Serialize(std::ostream& os) override
        {
            os << "[WindowRefreshEvent]\n";
        }
    };

    class WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent(int focused)
            : focused_(focused)
        {

        }

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
        int focused_;
    };
}