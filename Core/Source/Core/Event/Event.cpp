#include <Core/Event/Event.h>

using namespace Core::Event;

std::string Event::ToString()
{
    std::stringstream ss;
    Serialize(ss);
    return ss.str();
}

