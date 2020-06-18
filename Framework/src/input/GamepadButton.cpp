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
	bool GamepadButton::get_just_pressed() const
	{
		return just_pressed;
	}
	bool GamepadButton::get_released() const
	{
		return !pressed;
	}
	bool GamepadButton::get_just_released() const
	{
		return just_released;
	}
	void GamepadButton::update(const EventQueue& events)
	{
		
	}

} // namespace nova::input
