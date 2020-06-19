#include "GamepadButton.h"

namespace nova::input {

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

	void GamepadButton::update(const EventQueue& events)
	{
		
	}

} // namespace nova::input
