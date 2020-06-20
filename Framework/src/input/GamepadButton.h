#pragma once

#include "RawButton.h"

#include <SDL_gamecontroller.h>

#include <initializer_list>
#include <unordered_set>

namespace nova {

	class GamepadButton : public RawButton {

		std::unordered_set<SDL_GameControllerButton> buttons;
		bool pressed = false;

	public:

		GamepadButton() = default;
		GamepadButton(const std::initializer_list<SDL_GameControllerButton>& button_list);

		void add_button(SDL_GameControllerButton button);

		// Inherited via RawButton
		[[nodiscard]] bool get_pressed() const override;
		[[nodiscard]] bool get_released() const override;
		void update() override;

	};

} // namespace nova

