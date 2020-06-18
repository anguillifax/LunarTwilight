#include "InputSystem.h"

#include "../StringName.h"
#include "EventQueue.h"
#include "RawButton.h"
#include "VirtualButton.h"

#include <SDL.h>

#include <exception>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

namespace nova::input {

	// Internal representation
	struct InputSystem::Data {
		
		// Has ownership of all raw buttons
		std::vector<std::unique_ptr<RawButton>> raw_buttons;

		// Borrows ownership from raw_buttons
		std::unordered_map<StringName, VirtualButton> virtual_buttons;

	};

	InputSystem::InputSystem()
		: data(nullptr)
	{
		auto mask = SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER;
		if (mask != SDL_WasInit(mask)) {
			throw std::exception("InputSystem::ctor() Failed to create InputSystem. SDL Events and GameController subsystems were not initialized");
		}

		data = new Data;
	}

	InputSystem::~InputSystem()
	{
		delete data;
	}

	void InputSystem::update(const EventQueue& events)
	{
	}

} // namespace nova::input

