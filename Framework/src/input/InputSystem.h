#pragma once

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

	};

} // namespace nova::input

