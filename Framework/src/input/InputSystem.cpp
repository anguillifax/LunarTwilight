#include "InputSystem.h"

#include <unordered_map>

namespace nova::input {

	struct InputSystem::Data {
	};

	InputSystem::InputSystem()
		: data(new Data)
	{
	}

	InputSystem::~InputSystem()
	{
		delete data;
	}

	void InputSystem::init()
	{}

} // namespace nova::input

