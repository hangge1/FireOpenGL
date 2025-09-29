#pragma once

#include <Core/Event/Event.h>
#include <Core/Event/Modifier.h>
#include <Core/Event/MouseButtonType.h>
#include <Core/Event/MousePressType.h>

namespace Core::Event{


class MouseButtonEvent : public Event
{
public:
    MouseButtonEvent(int button, int action, int mods) 
        : m_Button((MouseButtonType)button), 
          m_Action((MousePressType)action), 
          m_Mods(mods) {}
    ~MouseButtonEvent() = default;

    EventType Type() const override { return EventType::MouseButtonEvent; }

    MouseButtonType Button() const { return m_Button; }
    MousePressType Action() const { return m_Action; }
    Modifier Mods() const { return m_Mods; }

    void Serialize(std::ostream& os) override
    {
        os << "[MouseButtonEvent]{";

        os << " button:" << m_Button;
        os << " action:" << m_Action;
        os << " mods:" << m_Mods;

        os << " }\n";
    }
private:
    MouseButtonType m_Button;
    MousePressType m_Action;
    Modifier m_Mods;
};

}