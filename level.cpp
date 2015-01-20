#include "level.h"

bool Level::execute() {
	 if(!read()) {
		 return false;
	 }
	 for (auto const &it : actors) {
		 it.second->act();
	 }

	 std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));
	 return true;
 }

bool Level::read() {
	SDL_Event event;
	while (SDL_PollEvent(&event)){
		switch (event.type){
		case SDL_QUIT:
			return false;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
			case SDLK_LEFT:
				getPlayer()->setMovingX(-1);
				break;
			case SDLK_RIGHT:
				getPlayer()->setMovingX(1);
				break;
			case SDLK_UP:
				getPlayer()->setMovingY(-1);
				break;
			case SDLK_DOWN:
				getPlayer()->setMovingY(1);
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym){
			case SDLK_LEFT:
				if (getPlayer()->getMovingX() == -1) {
					getPlayer()->setMovingX(0);
				}
				break;
			case SDLK_RIGHT:
				if (getPlayer()->getMovingX() == 1) {
					getPlayer()->setMovingX(0);
				}
				break;
			case SDLK_UP:
				if (getPlayer()->getMovingY() == -1) {
					getPlayer()->setMovingY(0);
				}
				break;
			case SDLK_DOWN:
				if (getPlayer()->getMovingY() == 1) {
					getPlayer()->setMovingY(0);
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	return true;
}

std::shared_ptr<Actor> Level::getPlayer() {
	return main_character.lock();
}

