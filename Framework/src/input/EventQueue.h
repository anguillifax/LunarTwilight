#pragma once

#include <SDL_events.h>

#include <vector>

namespace nova::input {

	/**
	 * @brief Holds a collection of all SDL Events from this update period.
	 */
	class EventQueue : public std::vector<SDL_Event> {

	public:

		EventQueue() = default;

	};

} // namespace nova::input

