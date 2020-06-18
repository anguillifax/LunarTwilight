#include "StringName.h"
#include "input/KeyboardButton.h"
#include "input/InputSystem.h"
#include "input/EventQueue.h"

#include <SDL.h>

#include <iostream>
#include <vector>

namespace nova {

	void run()
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);

		SDL_Window* window = SDL_CreateWindow("Framework", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		bool quit = false;
		SDL_Event cur_event{};

		input::EventQueue events;
		input::InputSystem input_system;

		input::KeyboardButton btn;

		while (!quit) {

			events.clear();

			while (SDL_PollEvent(&cur_event)) {
				switch (cur_event.type) {
					case SDL_QUIT:
						quit = true;
						break;
					case SDL_KEYDOWN:
						if (cur_event.key.keysym.scancode == SDL_SCANCODE_F4) {
							quit = true;
						}
						break;
				}

				events.push_back(cur_event);
			}

			input_system.update(events);

			SDL_RenderClear(renderer);

			SDL_RenderPresent(renderer);
			SDL_Delay(static_cast<Uint32>(1000 / 60));
		}

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

}

int main(int, char* [])
{
	std::cout << std::boolalpha;
	try {
		nova::run();
	} catch (std::exception& e) {
		std::cerr << "Game framework threw exception\n" << e.what() << '\n';
		return 1;
	}
	return 0;
}