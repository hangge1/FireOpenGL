#pragma once

#include <Core/Event/Event.h>

namespace Core::Event{

class MouseButtonEvent : public Event
{
public:
    MouseButtonEvent(int button, int action, int mods) : m_Button(button), m_Action(action), m_Mods(mods) {}
    ~MouseButtonEvent() = default;

    EventType Type() const override { return EventType::MouseButtonEvent; }

    int Button() const { return m_Button; }
    int Action() const { return m_Action; }
    int Mods() const { return m_Mods; }

    void Serialize(std::ostream& os) override
    {
        os << "[MouseButtonEvent]{";

        os << " button:" << m_Button;
        os << " action:" << m_Action;
        os << " mods:" << m_Mods;

        os << " }\n";
    }
private:
    int m_Button;
    int m_Action;
    int m_Mods;
};

}