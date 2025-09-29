#pragma once

#include <Core/Event/Event.h>

namespace Core::Event {

class WindowSizeEvent : public Event
{
public:
    WindowSizeEvent(int width, int height)
        : width_(width), height_(height)
    {

    }
    ~WindowSizeEvent() = default;

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
    int width_{};
    int height_{};
};

}