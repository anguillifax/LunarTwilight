#pragma once

#include "../StringName.h"

#include "RawButton.h"

namespace nova::input {

	// Designed to avoid SDL header files in public interface
	class EventQueue;

	class InputSystem {

		struct Data;
		Data* data;

	public:

		// ============
		// Construction
		// ============

		InputSystem();
		~InputSystem();

		InputSystem& operator=(const InputSystem&) = delete;
		InputSystem& operator=(InputSystem&&) = delete;

		InputSystem(const InputSystem&) = delete;
		InputSystem(InputSystem&&) = delete;

		// =========
		// Interface
		// =========

		void update(const EventQueue& events);

		void debug_create_button(const StringName& name, RawButton* rb);

		[[nodiscard]] bool get_pressed(const StringName& button_name) const;
		[[nodiscard]] bool get_just_pressed(const StringName& button_name) const;
		[[nodiscard]] bool get_released(const StringName& button_name) const;
		[[nodiscard]] bool get_just_released(const StringName& button_name) const;

	};

} // namespace nova::input

