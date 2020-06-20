#pragma once

#include "../StringName.h"

#include "RawButton.h"

#include <initializer_list>

namespace nova {

	// Designed to avoid SDL header files in public interface
	class EventQueue;

	class InputSystem {

		struct Data;
		Data* data;

	public: 

		struct MousePosition {
			int x;
			int y;
		};

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

		void bind(const StringName& name, RawButton* sub_button);
		void bind(const StringName& name, const std::initializer_list<RawButton*>& sub_button_list);

		[[nodiscard]] bool get_pressed(const StringName& button_name) const;
		[[nodiscard]] bool get_just_pressed(const StringName& button_name) const;
		[[nodiscard]] bool get_released(const StringName& button_name) const;
		[[nodiscard]] bool get_just_released(const StringName& button_name) const;

		[[nodiscard]] bool get_mouse_moved() const;
		[[nodiscard]] const MousePosition& get_mouse_position() const;

	};

} // namespace nova

