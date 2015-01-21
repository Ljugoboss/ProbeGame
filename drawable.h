#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "movable.h"
#include "sdl/SDL.h"
#include <vector>

template <class T>
class Drawable : public virtual Movable {
private:

public:
	int state;
	int frame;
	

	static std::vector<std::vector<SDL_Texture*>> animations;

	int image_width;
	int image_height;

	Drawable() { 
		state = 0;
		frame = 0;
	}

	virtual void setup() = 0;

	void draw();

	SDL_Texture * createBitmap(std::string path);

};

template <class T>
void Drawable<T>::draw() {
	// Part of the bitmap that we want to draw
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = image_width;
	source.h = image_height;
	// Part of the screen we want to draw the sprite to
	SDL_Rect destination;
	destination.x = (int)getX() - image_width / 2;
	destination.y = (int)getY() - image_height / 2;
	destination.w = image_width;
	destination.h = image_height;

	SDL_RenderCopy(getLevel()->getRenderer(), animations[state][frame], &source, &destination);
	//SDL_DestroyTexture(bitmap);

	frame = (frame + 1) % animations[state].size();
}

template <class T>
SDL_Texture * Drawable<T>::createBitmap(std::string path) {
	SDL_Surface * surface = SDL_LoadBMP(path.c_str());
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	SDL_Texture* bitmap = SDL_CreateTextureFromSurface(getLevel()->getRenderer(), surface);
	return bitmap;
}

#endif