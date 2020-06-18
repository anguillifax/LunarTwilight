#pragma once

#include "RawButton.h"

#include <unordered_set>

namespace nova::input {

	/**
	 * @brief Combines multiple raw buttons into a single button.
	 */
	class VirtualButton {

		std::unordered_set<RawButton*> buttons;

	public:

		/**
		 * @brief Add a new button to the VirtualButton, taking ownership.
		 * 
		 * If the button is already a part of this virtual button,
		 * this function has no effect.
		 * 
		 * @param button Button to add and take ownership of.
		 */
		void add(RawButton* button)
		{
			buttons.emplace(button);
		}

	};

} // namespace nova::input

