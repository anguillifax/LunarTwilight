#include "KeyboardButton.h"

#include <SDL_keyboard.h>

#include <iostream>

namespace nova::input {

	void KeyboardButton::add_button(SDL_Scancode code)
	{
		scancodes.emplace(code);
	}

	bool KeyboardButton::get_pressed() const
	{
		return pressed;
	}

	bool KeyboardButton::get_just_pressed() const
	{
		return just_pressed;
	}

	bool KeyboardButton::get_released() const
	{
		return !pressed;
	}

	bool KeyboardButton::get_just_released() const
	{
		return just_released;
	}

	static const Uint8* KEYBOARD_STATE = nullptr;

	void KeyboardButton::update(const EventQueue&)
	{
		if (KEYBOARD_STATE == nullptr) {
			KEYBOARD_STATE = SDL_GetKeyboardState(nullptr);
		}

		bool last_pressed = pressed;

		pressed = false;
		for (const SDL_Scancode& code : scancodes) {
			if (KEYBOARD_STATE[code]) {
				pressed = true;
				break;
			}
		}

		just_pressed = !last_pressed && pressed;
		just_released = last_pressed && !pressed;
	}

} // namespace nova::input
