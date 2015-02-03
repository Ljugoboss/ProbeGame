#include "level.h"
#include "QuadTree\QuadTree.h"

Level::Level(SDL_Renderer* l_renderer) : actor_list(), grid(AABB(Vec2f(0, 0), Vec2f(640, 480))) {
	keys[SDLK_LEFT] = false;
	keys[SDLK_RIGHT] = false;
	keys[SDLK_UP] = false;
	keys[SDLK_DOWN] = false;
	keys[SDLK_SPACE] = false;

	FPS = 120;
	current_id = 0;

	renderer = l_renderer;
}

void Level::init() {
	std::shared_ptr<Player> player = std::make_shared<Player>(Player(50, 50, shared_from_this()));
	player->addAbility();
	addActor(player);
	main_character = player;
	std::shared_ptr<Player> test = std::make_shared<Player>(Player(200, 200, shared_from_this()));
	addActor(test);
}

void Level::execute() {
	auto begin = std::chrono::high_resolution_clock::now();
	int collision_count = 0;
	for (auto const &it1 : actor_list) {
		it1->act();

		std::vector<QuadTreeOccupant*> queryResult = std::vector<QuadTreeOccupant*>();
		grid.Query(it1->aabb, queryResult);
		for (auto const &it2 : queryResult) {
			if (it1.get() != it2) {
				if (it1->collision(*it2)) {
					collision_count++;
				}
			}
		}
	}

	std::cout << collision_count << std::endl;
	read();

	auto end = std::chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	
	auto wait = 1000 / FPS - ms;
	if (wait < 0) {
		wait = 0;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(wait));
 }

void Level::addActor(std::shared_ptr<Actor> actor) {
	current_id++;
	actor->actor_id = current_id;
	actors[current_id] = actor;
	actor_list.push_back(actor);
	grid.AddOccupant(actor.get());
}

void Level::destroyActor(int id) {
	destroyed.push_back(id);
}

void Level::cleanup() {
	for (int id : destroyed) {
		actors[id]->RemoveFromTree();
		actor_list.erase(std::find(actor_list.begin(), actor_list.end(), actors[id]));
		actors.erase(id);
	}
	destroyed.clear();
}

std::shared_ptr<Actor> Level::getActor(int id) {
	return actors[id];
}


int Level::getCurrentId() const {
	return current_id;
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
				if (!keys[SDLK_SPACE]) {
					getPlayer()->useAbility();
				}
				keys[SDLK_SPACE] = true;
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
			case SDLK_SPACE:
				keys[SDLK_SPACE] = false;
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

std::shared_ptr<Player> Level::getPlayer() {
	return main_character;
}

SDL_Renderer * Level::getRenderer() {
	return renderer;
}
