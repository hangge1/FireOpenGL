#include <Core/Event/MousePressType.h>

using namespace Core::Event;

const MousePressType MousePressType::Release = MousePressType(0);
const MousePressType MousePressType::Press = MousePressType(1);
const std::string  MousePressType::MousePressTypeNames[2] = {"Release", "Press"};