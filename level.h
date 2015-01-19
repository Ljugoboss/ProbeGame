#include <memory>
#include <chrono>
#include <thread>
#include "sdl/SDL.h"

#ifndef LEVEL_H
#define LEVEL_H

class Level {
private:
	std::map<int, std::shared_ptr<Actor>> actors;
	std::weak_ptr<Player> main_character;
public:
	Level() {}

	void execute() {
		read();
		for (auto const &it1 : actors) {
			for (auto const &it2 : it1.second) {
				it2->act();
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	void read() {
		while (SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym){
						case SDLK_LEFT:
							break;
						case SDLK_RIGHT:
							break;
						case SDLK_UP:
							break;
						case SDLK_DOWN:
							break;
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					switch (event.key.keysym.sym){
						case SDLK_LEFT:
							break;
						case SDLK_RIGHT:
							break;
						case SDLK_UP:
							break;
						case SDLK_DOWN:
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}
	}
};

#endif