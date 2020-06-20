#include "MouseButton.h"

namespace nova {

	MouseButton::MouseButton(const std::initializer_list<SDL_MouseButton>& button_list)
		: buttons(button_list)
	{
	}

	void MouseButton::add_mouse_button(SDL_MouseButton button)
	{
		buttons.emplace(button);
	}

	bool MouseButton::get_pressed() const
	{
		return pressed;
	}

	bool MouseButton::get_released() const
	{
		return !pressed;
	}

	void MouseButton::update(const EventQueue&)
	{
		SDL_MouseButton mask = 0u;
		for (SDL_MouseButton btn : buttons) {
			mask |= SDL_BUTTON(static_cast<Uint32>(btn));
		}

		pressed = false;
		if (mask == SDL_GetMouseState(nullptr, nullptr)) {
			pressed = true;
		}
	}
} // namespace nova
