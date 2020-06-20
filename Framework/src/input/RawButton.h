#pragma once

#include "EventQueue.h"

namespace nova {

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
		 * @brief The button is currently released.
		 */
		virtual bool get_released() const = 0;

		/**
		 * @brief Update the internal state of the button.
		 * 
		 * Call once per update period.
		 * 
		 * @param events All events from this update period.
		 */
		virtual void update() = 0;

	};

} // namespace nova
