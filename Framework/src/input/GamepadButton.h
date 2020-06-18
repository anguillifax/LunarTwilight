#pragma once

#include "RawButton.h"

#include <SDL_gamecontroller.h>

#include <unordered_set>

namespace nova::input {

	class GamepadButton : public RawButton {

		std::unordered_set<SDL_GameControllerButton> buttons;
		bool pressed = false;
		bool just_pressed = false;
		bool just_released = false;

	public:

		void add_button(SDL_GameControllerButton button);

		// Inherited via RawButton
		bool get_pressed() const override;
		bool get_just_pressed() const override;
		bool get_released() const override;
		bool get_just_released() const override;
		void update(const std::vector<SDL_Event>& events) override;
	};

} // namespace nova::input

