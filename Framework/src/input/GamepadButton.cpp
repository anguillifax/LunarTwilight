#include "GamepadButton.h"

#include "GamepadUtility.h"

namespace nova {

	GamepadButton::GamepadButton(const std::initializer_list<SDL_GameControllerButton>& button_list)
		: buttons(button_list)
	{
	}

	void GamepadButton::add_button(SDL_GameControllerButton button)
	{
		buttons.emplace(button);
	}
	
	bool GamepadButton::get_pressed() const
	{
		return pressed;
	}

	bool GamepadButton::get_released() const
	{
		return !pressed;
	}

	void GamepadButton::update(const EventQueue&)
	{
		pressed = false;
		for (SDL_GameController* gamepad : GamepadUtility::get()) {
			for (SDL_GameControllerButton btn : buttons) {
				if (SDL_GameControllerGetButton(gamepad, btn) == 1) {
					pressed = true;
					return;
				}
			}
		}
	}

} // namespace nova
