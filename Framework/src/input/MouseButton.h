#pragma once

#include "RawButton.h"

#include "SDL_mouse.h"

#include <initializer_list>
#include <unordered_set>

namespace nova {

	class MouseButton : public RawButton {
	public:

		typedef Uint32 SDL_MouseButton;

	private:

		std::unordered_set<SDL_MouseButton> buttons;
		bool pressed = false;

	public:

		MouseButton() = default;
		MouseButton(const std::initializer_list<SDL_MouseButton>& button_list);

		void add_mouse_button(SDL_MouseButton button);

		// Inherited via RawButton
		[[nodiscard]] bool get_pressed() const override;
		[[nodiscard]] bool get_released() const override;
		void update(const EventQueue& events) override;
	};

} // namespace nova
