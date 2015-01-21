#include "level.h"

void Level::execute() {
	 read();
	 for (auto const &it : actors) {
		 it.second->act();
	 }

	 std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));
 }

void Level::addActor(std::shared_ptr<Actor> actor) {
	current_id++;
	actors[current_id] = actor;
}

void Level::destroyActor(int id) {
	destroyed.push_back(id);
}

void Level::cleanup() {
	for (int id : destroyed) {
		actors.erase(id);
	}
	destroyed.clear();
}

void Level::read() {
	SDL_Event event;
	int movingX;
	int movingY;
	while (SDL_PollEvent(&event)){
		switch (event.type){
		case SDL_KEYDOWN:
			movingX = getPlayer()->getMovingX();
			movingY = getPlayer()->getMovingY();
			switch (event.key.keysym.sym){
			case SDLK_LEFT:
				if (!keys[SDLK_LEFT]) {
					getPlayer()->setMovingX(movingX - 1);
				}
				keys[SDLK_LEFT] = true;
				break;
			case SDLK_RIGHT:
				if (!keys[SDLK_RIGHT]) {
					getPlayer()->setMovingX(movingX + 1);
				}
				keys[SDLK_RIGHT] = true;
				break;
			case SDLK_UP:
				if (!keys[SDLK_UP]) {
					getPlayer()->setMovingY(movingY - 1);
				}
				keys[SDLK_UP] = true;
				break;
			case SDLK_DOWN:
				if (!keys[SDLK_DOWN]) {
					getPlayer()->setMovingY(movingY + 1);
				}
				keys[SDLK_DOWN] = true;
				break;
			case SDLK_SPACE:
				addActor(std::make_shared<Bolt>(Bolt(getPlayer()->getX(), getPlayer()->getY(), current_id + 1, shared_from_this(), 1, 0)));
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			movingX = getPlayer()->getMovingX();
			movingY = getPlayer()->getMovingY();
			switch (event.key.keysym.sym){
			case SDLK_LEFT:
				if (keys[SDLK_LEFT]) {
					getPlayer()->setMovingX(movingX + 1);
				}
				keys[SDLK_LEFT] = false;
				break;
			case SDLK_RIGHT:
				if (keys[SDLK_RIGHT]) {
					getPlayer()->setMovingX(movingX - 1);
				}
				keys[SDLK_RIGHT] = false;
				break;
			case SDLK_UP:
				if (keys[SDLK_UP]) {
					getPlayer()->setMovingY(movingY + 1);
				}
				keys[SDLK_UP] = false;
				break;
			case SDLK_DOWN:
				if (keys[SDLK_DOWN]) {
					getPlayer()->setMovingY(movingY - 1);
				}
				keys[SDLK_DOWN] = false;
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

std::shared_ptr<Actor> Level::getPlayer() {
	return main_character;
}

SDL_Renderer * Level::getRenderer() {
	return renderer;
}
