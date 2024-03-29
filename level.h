#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <map>
#include "sdl/SDL.h"
#include "actor.h"
#include "player.h"
#include "bolt.h"

class Level : public std::enable_shared_from_this<Level> {
private:
	SDL_Renderer * renderer;

	std::map<int, bool> keys;

	std::map<int, std::shared_ptr<Actor>> actors;
	std::shared_ptr<Player> main_character;

	int current_id;

	int max_actors;

	std::vector<int> destroyed;
public:
	int FPS;

	Level(SDL_Renderer* l_renderer) {
		keys[SDLK_LEFT] = false;
		keys[SDLK_RIGHT] = false;
		keys[SDLK_UP] = false;
		keys[SDLK_DOWN] = false;

		FPS = 120;
		current_id = 0; 

		renderer = l_renderer;
	}

	void init() {
		std::shared_ptr<Player> player = std::make_shared<Player>(Player(50, 50, 0, shared_from_this()));
		player->addAbility();
		actors[0] = player;
		main_character = player;
		std::shared_ptr<Player> test = std::make_shared<Player>(Player(200, 200, 1, shared_from_this()));
		actors[1] = test;
		current_id++;

	}

	std::shared_ptr<Actor> getActor(int id);
	void addActor(std::shared_ptr<Actor> actor);

	void destroyActor(int id);

	void cleanup();

	void execute();

	void read();

	int getCurrentId() const;

	std::shared_ptr<Player> getPlayer();

	SDL_Renderer * getRenderer();
};

#endif