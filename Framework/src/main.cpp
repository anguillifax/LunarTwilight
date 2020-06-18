#include "StringName.h"
#include "input/KeyboardButton.h"

#include <SDL.h>

#include <iostream>
#include <vector>

int main(int, char* [])
{
	using namespace nova;
	std::cout << std::boolalpha;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Framework", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool quit = false;
	SDL_Event cur_event{};
	std::vector<SDL_Event> events;

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
		btn.update(events);

		SDL_RenderClear(renderer);

		if (btn.get_just_pressed()) puts("jpressed");
		if (btn.get_pressed()) puts("pressed");
		if (btn.get_just_released()) puts("j^");
		if (btn.get_released()) puts("^");

		SDL_RenderPresent(renderer);
		SDL_Delay(static_cast<Uint32>(1000 / 60));
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}