#include "actor.h"
#include "level.h"

/*
void Actor::draw() {
	// Part of the bitmap that we want to draw
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = image_width;
	source.h = image_height;
	// Part of the screen we want to draw the sprite to
	SDL_Rect destination;
	destination.x = (int) getX() - image_width / 2;
	destination.y = (int) getY() - image_height / 2;
	destination.w = image_width;
	destination.h = image_height;

	SDL_RenderCopy(getLevel()->getRenderer(), bitmap, &source, &destination);
	//SDL_DestroyTexture(bitmap);
}

void Actor::createBitmap() {
	SDL_Surface * surface = SDL_LoadBMP(image_path.c_str());
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	bitmap = SDL_CreateTextureFromSurface(getLevel()->getRenderer(), surface);
}
*/