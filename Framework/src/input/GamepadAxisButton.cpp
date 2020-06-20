#include "GamepadAxisButton.h"

#include "GamepadUtility.h"

#include <cmath>
#include <limits>

#include <iostream>

namespace nova {

	void GamepadAxisButton::add_axis(SDL_GameControllerAxis axis, bool positive)
	{
		for (auto it = axes.begin(); it != axes.end(); ++it) {
			if (it->axis == axis && it->positive == positive) {
				return;
			}
		}
		axes.emplace_back(axis, positive);
	}

	bool GamepadAxisButton::get_pressed() const
	{
		return pressed;
	}

	bool GamepadAxisButton::get_released() const
	{
		return !pressed;
	}

	void GamepadAxisButton::update()
	{
		pressed = false;
		for (SDL_GameController* gamepad : GamepadUtility::get()) {
			for (const Binding& binding : axes) {
				float normalized = static_cast<float>(SDL_GameControllerGetAxis(gamepad, binding.axis)) / std::numeric_limits<Sint16>::max();
				if (binding.positive ? normalized > DEADZONE : normalized < -DEADZONE) {
					pressed = true;
					return;
				}
			}
		}
	}

} // namespace nova