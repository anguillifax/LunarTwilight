#include "KeyboardButton.h"

#include <SDL_keyboard.h>

#include <iostream>

namespace nova {

	KeyboardButton::KeyboardButton(const std::initializer_list<SDL_Scancode>& scancode_list)
		: scancodes(scancode_list)
	{
	}

	void KeyboardButton::add_button(SDL_Scancode code)
	{
		scancodes.emplace(code);
	}

	static const Uint8* KEYBOARD_STATE = nullptr;

	bool KeyboardButton::get_pressed() const
	{
		return pressed;
	}

	bool KeyboardButton::get_released() const
	{
		return !pressed;
	}

	void KeyboardButton::update()
	{
		if (KEYBOARD_STATE == nullptr) {
			KEYBOARD_STATE = SDL_GetKeyboardState(nullptr);
		}

		pressed = false;
		for (const SDL_Scancode& code : scancodes) {
			if (KEYBOARD_STATE[code] == SDL_TRUE) {
				pressed = true;
				break;
			}
		}
	}

} // namespace nova
