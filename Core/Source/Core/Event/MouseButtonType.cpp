
#include <Core/Event/MouseButtonType.h>

using namespace Core::Event;

const MouseButtonType MouseButtonType::LeftButton = MouseButtonType(0);
const MouseButtonType MouseButtonType::RightButton = MouseButtonType(1);
const MouseButtonType MouseButtonType::MiddleButton = MouseButtonType(2);

const std::string MouseButtonType::MouseButtonTypeNames[3] 
    = {"LeftButton", "RightButton", "MiddleButton"};