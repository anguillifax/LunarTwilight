#include "InputSystem.h"

#include "../StringName.h"
#include "EventQueue.h"
#include "KeyboardButton.h"
#include "RawButton.h"
#include "VirtualButton.h"

#include <SDL.h>

#include <exception>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <unordered_set>

namespace nova {

	// Internal representation
	struct InputSystem::Data {
		
		// Has ownership of all raw buttons
		std::unordered_set<std::unique_ptr<RawButton>> raw_buttons;

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

	void InputSystem::bind(const StringName& name, RawButton* rb)
	{
		data->raw_buttons.emplace(rb);
		auto it = data->virtual_buttons.find(name);
		if (it == data->virtual_buttons.end()) {
			VirtualButton b;
			b.add_sub_button(rb);
			data->virtual_buttons.emplace(name, b);
		} else {
			it->second.add_sub_button(rb);
		}
	}

	void InputSystem::bind(const StringName& name, const std::initializer_list<RawButton*>& sub_button_list)
	{
		for (RawButton* btn : sub_button_list) {
			data->raw_buttons.emplace(btn);
		}

		auto it = data->virtual_buttons.find(name);
		if (it == data->virtual_buttons.end()) {
			VirtualButton b(sub_button_list);
			data->virtual_buttons.emplace(name, b);
		} else {
			for (RawButton* btn : sub_button_list) {
				it->second.add_sub_button(btn);
			}
		}
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

} // namespace nova
