#include "inputdevice.h"

using namespace kerosin;
using namespace zeitgeist;


InputDevice::InputDevice() :
Leaf(), mInputSystem(NULL)
{
}

InputDevice::~InputDevice()
{
}

bool InputDevice::Init(kerosin::InputSystem *inputSystem)
{
	mInputSystem = inputSystem;

	if (mInputSystem == NULL) return false;

	return true;
}