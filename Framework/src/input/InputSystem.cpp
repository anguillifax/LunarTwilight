#include "InputSystem.h"

#include "../StringName.h"
#include "EventQueue.h"
#include "RawButton.h"
#include "VirtualButton.h"
#include "KeyboardButton.h"

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
		// TODO: Add something that needs this check or get rid of it
		//auto mask = SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER;
		//if (mask != SDL_WasInit(mask)) {
		//	throw std::exception("InputSystem::ctor() Failed to create InputSystem. SDL Events and GameController subsystems were not initialized");
		//}

		data = new Data;
	}

	InputSystem::~InputSystem()
	{
		delete data;
	}

	void InputSystem::update(const EventQueue& events)
	{
		for (const auto& rbutton : data->raw_buttons) {
			rbutton->update(events);
		}
		for (auto& item : data->virtual_buttons) {
			item.second.update();
		}
	}

	void InputSystem::debug_create_button(const StringName& name, RawButton* rb)
	{
		data->raw_buttons.emplace_back(rb);
		VirtualButton b;
		b.add(rb);
		data->virtual_buttons.emplace(name, b);
	}

	bool InputSystem::get_pressed(const StringName& button_name) const
	{
		auto it = data->virtual_buttons.find(button_name);
		if (it != data->virtual_buttons.end()) {
			return it->second.get_pressed();
		}
		return false;
	}

	bool InputSystem::get_just_pressed(const StringName& button_name) const
	{
		auto it = data->virtual_buttons.find(button_name);
		if (it != data->virtual_buttons.end()) {
			return it->second.get_just_pressed();
		}
		return false;
	}

	bool InputSystem::get_released(const StringName& button_name) const
	{
		return !get_pressed(button_name);
	}

	bool InputSystem::get_just_released(const StringName& button_name) const
	{
		auto it = data->virtual_buttons.find(button_name);
		if (it != data->virtual_buttons.end()) {
			return it->second.get_just_released();
		}
		return false;
	}

} // namespace nova::input

