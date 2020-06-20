#pragma once

#include "EventQueue.h"

#include <SDL_gamecontroller.h>

#include <memory>
#include <vector>

namespace nova {

	class GamepadCollection : public std::vector<SDL_GameController*> {
	public:
		GamepadCollection() = default;
	};

	class GamepadUtility {

		static GamepadCollection gamepads;

	public:

		static void update(const EventQueue& queue);

		static GamepadCollection& get() noexcept
		{
			return gamepads;
		}

	};

} // namespace nova
