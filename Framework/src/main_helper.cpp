#include "main_helper.h"

#include "input/GamepadAxisButton.h"
#include "input/GamepadButton.h"
#include "input/KeyboardButton.h"
#include "input/MouseButton.h"

#include <SDL_gamecontroller.h>
#include <SDL_mouse.h>
#include <SDL_scancode.h>

namespace nova {

	void LoadInputs::load()
	{
		{
			auto* a = new KeyboardButton{ SDL_SCANCODE_A, SDL_SCANCODE_J, SDL_SCANCODE_LEFT };
			auto* b = new GamepadButton{ SDL_CONTROLLER_BUTTON_DPAD_LEFT };
			auto* c = new GamepadAxisButton;
			c->add_axis(SDL_CONTROLLER_AXIS_LEFTX, false);
			c->add_axis(SDL_CONTROLLER_AXIS_RIGHTX, false);

			inputs->bind("left", { a, b, c });
		}

		{
			auto* a = new KeyboardButton{ SDL_SCANCODE_D, SDL_SCANCODE_L, SDL_SCANCODE_RIGHT };
			auto* b = new GamepadButton{ SDL_CONTROLLER_BUTTON_DPAD_RIGHT };
			auto* c = new GamepadAxisButton;
			c->add_axis(SDL_CONTROLLER_AXIS_LEFTX, true);
			c->add_axis(SDL_CONTROLLER_AXIS_RIGHTX, true);

			inputs->bind("right", { a, b, c });
		}

		{
			auto* a = new KeyboardButton{ SDL_SCANCODE_W, SDL_SCANCODE_I, SDL_SCANCODE_UP };
			auto* b = new GamepadButton{ SDL_CONTROLLER_BUTTON_DPAD_UP };
			auto* c = new GamepadAxisButton;
			c->add_axis(SDL_CONTROLLER_AXIS_LEFTY, false);
			c->add_axis(SDL_CONTROLLER_AXIS_RIGHTY, false);

			inputs->bind("up", { a, b, c });
		}

		{
			auto* a = new KeyboardButton{ SDL_SCANCODE_S, SDL_SCANCODE_K, SDL_SCANCODE_DOWN };
			auto* b = new GamepadButton{ SDL_CONTROLLER_BUTTON_DPAD_DOWN };
			auto* c = new GamepadAxisButton;
			c->add_axis(SDL_CONTROLLER_AXIS_LEFTY, true);
			c->add_axis(SDL_CONTROLLER_AXIS_RIGHTY, true);

			inputs->bind("down", { a, b, c });
		}

		{
			auto* a = new KeyboardButton{ SDL_SCANCODE_RETURN, SDL_SCANCODE_RETURN2, SDL_SCANCODE_SPACE };
			auto* b = new GamepadButton{ SDL_CONTROLLER_BUTTON_A, SDL_CONTROLLER_BUTTON_X };
			auto* d = new MouseButton{ SDL_BUTTON_LEFT };

			inputs->bind("enter", { a, b, d });
		}

		{
			auto* a = new KeyboardButton{ SDL_SCANCODE_ESCAPE, SDL_SCANCODE_BACKSPACE };
			auto* b = new GamepadButton{ SDL_CONTROLLER_BUTTON_B, SDL_CONTROLLER_BUTTON_Y };
			auto* d = new MouseButton{ SDL_BUTTON_RIGHT };

			inputs->bind("cancel", { a, b, d });
		}
	}

} // namespace nova
