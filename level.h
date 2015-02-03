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
#include "QuadTree\QuadTree.h"

class Level : public std::enable_shared_from_this<Level> {
private:

	SDL_Renderer * renderer;

	std::map<int, bool> keys;

	std::vector<std::shared_ptr<Actor>> actor_list;

	QuadTree grid;

	std::map<int, std::shared_ptr<Actor>> actors;
	std::shared_ptr<Player> main_character;

	int current_id;

	int max_actors;

	std::vector<int> destroyed;
public:
	int FPS;

	Level(SDL_Renderer* l_renderer);

	void init();

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