
#pragma once

#include <Core/Event/Event.h>
#include <Core/Event/Modifier.h>

namespace Core::Event {
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

        Modifier Mods() const
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
        Modifier mods_;
    };
}