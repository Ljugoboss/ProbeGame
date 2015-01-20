#include <memory>
#include <chrono>
#include <thread>
#include <map>
#include "sdl/SDL.h"
#include "actor.h"
#include "player.h"

#ifndef LEVEL_H
#define LEVEL_H

class Level : public std::enable_shared_from_this<Level> {
private:
	std::map<int, std::shared_ptr<Actor>> actors;
	std::weak_ptr<Actor> main_character;
public:
	int FPS;

	Level() { 
		FPS = 120;
	}

	void init() {
		std::shared_ptr<Actor> player = std::make_shared<Player>(Player(50, 50, shared_from_this()));
		actors[0] = player;
		main_character = player;
	}

	void execute();

	void read();

	std::shared_ptr<Actor> getPlayer();
};

#endif