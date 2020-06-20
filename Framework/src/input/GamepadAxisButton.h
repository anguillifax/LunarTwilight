#pragma once

#include "RawButton.h"

#include <SDL_gamecontroller.h>

#include <vector>

namespace nova {

	class GamepadAxisButton : public RawButton {

		static constexpr float DEADZONE = 0.5f;

		struct Binding {
			SDL_GameControllerAxis axis;
			bool positive;

			Binding(SDL_GameControllerAxis axis, bool positive)
				: axis(axis), positive(positive)
			{
			}
		};

		std::vector<Binding> axes;
		bool pressed = false;

	public:

		void add_axis(SDL_GameControllerAxis axis, bool positive);

		// Inherited via RawButton
		[[nodiscard]] bool get_pressed() const override;
		[[nodiscard]] bool get_released() const override;
		void update(const EventQueue& events) override;

	};

} // namespace nova
