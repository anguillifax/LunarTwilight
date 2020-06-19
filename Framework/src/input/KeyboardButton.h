#pragma once

#include "RawButton.h"

#include "SDL_scancode.h"

#include <unordered_set>

namespace nova::input {

	/**
	 * @brief A button backed by a keyboard input.
	 */
	class KeyboardButton : public RawButton {

		std::unordered_set<SDL_Scancode> scancodes;
		bool pressed = false;

	public:

		/**
		 * @brief Add another scancode to the tracking list.
		 * 
		 * If the given scancode is already being tracked, this function
		 * has no effect.
		 * 
		 * @param code Scancode to add.
		 */
		void add_button(SDL_Scancode code);

		// Inherited via RawButton
		[[nodiscard]] bool get_pressed() const override;
		[[nodiscard]] bool get_released() const override;
		void update(const EventQueue& events) override;

	};

} // namespace nova::input

