#include "GamepadUtility.h"

#include <algorithm>
#include <iostream>

namespace nova {

	GamepadCollection GamepadUtility::gamepads;

	void GamepadUtility::update(const EventQueue& queue)
	{
		for (const SDL_Event& ev : queue) {
			switch (ev.type) {
				case SDL_CONTROLLERDEVICEADDED:
				{
					std::cout << "Added at index " << ev.cdevice.which << '\n';
					gamepads.emplace_back(SDL_GameControllerOpen(ev.cdevice.which));
				}
				break;
				case SDL_CONTROLLERDEVICEREMOVED:
				{
					auto* gc = SDL_GameControllerFromInstanceID(ev.cdevice.which);
					std::cout << "Removed at id " << ev.cdevice.which << '\n';
					SDL_GameControllerClose(gc);
					gamepads.erase(std::find(gamepads.begin(), gamepads.end(), gc));
				}
				break;
				case SDL_CONTROLLERDEVICEREMAPPED:
				{
					std::cout << "Mapped at id " << ev.cdevice.which << '\n';
				}
				break;
			}
		}
	}

} // namespace nova
