#include "main_helper.h"

#include "StringName.h"
#include "input/InputSystem.h"
#include "input/EventQueue.h"
#include "input/GamepadUtility.h"

#include <SDL.h>

#include <iostream>
#include <vector>

namespace nova {

	namespace
	{
		InputSystem input_system;

		void log_vbutton(const std::string& name)
		{
			if (input_system.get_just_pressed(name)) {
				puts(name.c_str());
			}
			if (input_system.get_just_released(name)) {
				puts((name + " ^^^").c_str());
			}

		}
	} // namespace 

	void run()
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);

		SDL_Window* window = SDL_CreateWindow("Framework", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		bool quit = false;
		bool pause = false;
		SDL_Event cur_event{};

		EventQueue events;

		LoadInputs _ip(&input_system);

		while (!quit) {

			events.clear();

			while (SDL_PollEvent(&cur_event) != SDL_FALSE) {
				switch (cur_event.type) {
					case SDL_QUIT:
						quit = true;
						break;
					case SDL_KEYDOWN:
						switch (cur_event.key.keysym.scancode) {
							case SDL_SCANCODE_F4:
								quit = true;
								break;
							case SDL_SCANCODE_P:
								pause = !pause;
								break;
						}
						break;
				}

				events.push_back(cur_event);
			}

			if (!pause) {

				GamepadUtility::update(events);
				input_system.update(events);

				log_vbutton("left");
				log_vbutton("right");
				log_vbutton("up");
				log_vbutton("down");
				log_vbutton("enter");
				log_vbutton("cancel");

				if (input_system.get_mouse_moved()) {
					auto pos = input_system.get_mouse_position();
					std::cout << '(' << pos.x << ", " << pos.y << ")\n";
				}

			}

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