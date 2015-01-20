#include "actor.h"

void Actor::draw(SDL_Renderer* renderer) {
	SDL_Texture* bitmap = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP(image_path));

	// Part of the bitmap that we want to draw
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = 61;
	source.h = 61;
	// Part of the screen we want to draw the sprite to
	SDL_Rect destination;
	destination.x = (int) getX();
	destination.y = (int) getY();
	destination.w = 61;
	destination.h = 61;

	SDL_RenderCopy(renderer, bitmap, &source, &destination);
}