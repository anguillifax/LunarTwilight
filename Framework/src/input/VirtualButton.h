#pragma once

#include "RawButton.h"

#include <initializer_list>
#include <unordered_set>

namespace nova {

	/**
	 * @brief Combines multiple raw buttons into a single button.
	 */
	class VirtualButton {

		std::unordered_set<RawButton*> buttons;
		bool pressed = false;
		bool just_pressed = false;
		bool just_released = false;

	public:

		VirtualButton() = default;
		VirtualButton(const std::initializer_list<RawButton*>& sub_button_list);

		/**
		 * @brief Add a new button to the VirtualButton.
		 *
		 * If the button is already a part of this virtual button,
		 * this function has no effect.
		 *
		 * @param button Button to add.
		 */
		void add_sub_button(RawButton* button);

		void update();

		[[nodiscard]]
		bool get_pressed() const
		{
			return pressed;
		}

		[[nodiscard]]
		bool get_just_pressed() const
		{
			return just_pressed;
		}

		[[nodiscard]]
		bool get_just_released() const
		{
			return just_released;
		}

	};

} // namespace nova

