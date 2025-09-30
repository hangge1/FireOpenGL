    #pragma once

    #include <Core/Event/Event.h>

    namespace Core::Event {

    class TitleBarHitTestEvent : public Event
    {
    public:
        TitleBarHitTestEvent(int xpos, int ypos, int* hit)
            : m_xpos(xpos),
            m_ypos(ypos),
            m_hit(hit)
        {

        }
        ~TitleBarHitTestEvent() = default;

        EventType Type() const override
        {
            return EventType::TitleBarHitTestEvent;
        }

        int XPos() const
        {
            return m_xpos;
        }

        int YPos() const
        {
            return m_ypos;
        }

        void Pos(int* xpos, int* ypos)
        {
            *xpos = m_xpos;
            *ypos = m_ypos;
        }

        int* Hit() const
        {
            return m_hit;
        }

        void Serialize(std::ostream& os) override
        {
            os << "[TitleBarHitTestEvent]{";

            os << " xpos:" << m_xpos;
        }

    private:
        int m_xpos{};
        int m_ypos{};
        int* m_hit{};
    };
    }