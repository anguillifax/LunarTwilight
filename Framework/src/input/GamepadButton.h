#pragma once

#include "RawButton.h"

#include <SDL_gamecontroller.h>

#include <unordered_set>

namespace nova::input {

	class GamepadButton : public RawButton {

		std::unordered_set<SDL_GameControllerButton> buttons;
		bool pressed = false;

	public:

		void add_button(SDL_GameControllerButton button);

		// Inherited via RawButton
		[[nodiscard]] bool get_pressed() const override;
		[[nodiscard]] bool get_released() const override;
		void update(const EventQueue& events) override;

	};

} // namespace nova::input

