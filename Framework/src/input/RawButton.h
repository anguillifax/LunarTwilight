#pragma once

#include <SDL_events.h>

#include <vector>

namespace nova::input {

	/**
	 * @brief Protocol for all buttons.
	 */
	class RawButton {
	public:

		// ============
		// Construction
		// ============

		RawButton() = default;
		virtual ~RawButton() = default;

		RawButton(const RawButton&) = delete;
		RawButton& operator=(const RawButton&) = delete;

		RawButton(RawButton&&) = delete;
		RawButton& operator=(RawButton&&) = delete;

		// =========
		// Interface
		// =========

		/**
		 * @brief The button is currently held down.
		 */
		virtual bool get_pressed() const = 0;

		/**
		 * @brief The button was pressed this update period.
		 */
		virtual bool get_just_pressed() const = 0;

		/**
		 * @brief The button is currently released.
		 */
		virtual bool get_released() const = 0;

		/**
		 * @brief The button was released this frame.
		 */
		virtual bool get_just_released() const = 0;

		/**
		 * @brief Update the internal state of the button.
		 * 
		 * Call once per update period.
		 * 
		 * @param events All events from this update period.
		 */
		virtual void update(const std::vector<SDL_Event>& events) = 0;

	};

} // namespace nova::input
