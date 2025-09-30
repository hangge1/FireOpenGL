
#pragma once

#include <Core/Event/Event.h>
#include <Core/Event/Modifier.h>

namespace Core::Event {
    class KeyEvent : public Event
    {
    public:
        KeyEvent(int key, int scancode, int action, int mods)
            : m_key(key), m_scancode(scancode), m_action(action), m_mods(mods)
        {

        }

        EventType Type() const override
        {
            return EventType::KeyEvent;
        }

        int Key() const
        {
            return m_key;
        }

        int ScanCode() const
        {
            return m_scancode;
        }

        int Action() const
        {
            return m_action;
        }

        Modifier Mods() const
        {
            return m_mods;
        }

        void Serialize(std::ostream& os) override
        {
            os << "[KeyEvent]{";

            os << " key:" << m_key;
            os << " scancode:" << m_scancode;
            os << " action:" << m_action;
            os << " mods:" << m_mods;

            os << " }\n";
        }
    private:
        int m_key;
        int m_scancode;
        int m_action;
        Modifier m_mods;
    };
}