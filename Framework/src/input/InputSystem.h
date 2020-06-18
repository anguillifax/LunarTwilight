#pragma once

namespace nova::input {

	// must see all events before from them
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

		void init();

	};

} // namespace nova::input

