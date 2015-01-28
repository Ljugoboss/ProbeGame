#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "rapidxml/rapidxml.hpp"
#include <utility>      
#include "locatable.h"
#include "sdl/SDL.h"
#include <sstream>  
#include <fstream>
#include <vector>

struct frame {
	int xlocation;
	int ylocation;
	int duration;
};

template <class T>
class Drawable {
private:
	static int image_height;
	static int image_width;

	static bool initialized;
	static std::vector<SDL_Texture*> images;
	static std::vector<std::vector<frame>> frames;

	SDL_Renderer * renderer;
	std::string image_path;
	int FPS;

	int state;
	int time;
	int current_frame;
public:
	Drawable(SDL_Renderer * source, int fps, std::string path) {
		time = 0;
		state = 0;
		current_frame = 0;

		renderer = source;
		FPS = fps;
		image_path = path;

		if (!initialized) {
			setup(image_path);
			initialized = true;
 		}
	}

	void setup(std::string path);

	void draw(double x, double y);
	void draw(int x, int y);

	SDL_Texture * createBitmap(std::string path);

	void parseXML(std::string path);

	void setState(int value);
};

template <class T>
int Drawable<T>::image_height = 0;

template <class T>
int Drawable<T>::image_width = 0;

template <class T>
bool Drawable<T>::initialized = false;

template <class T>
std::vector<SDL_Texture*> Drawable<T>::images = std::vector<SDL_Texture*>();

template <class T>
std::vector<std::vector<frame>> Drawable<T>::frames = std::vector<std::vector<frame>>();

template <class T>
void Drawable<T>::draw(double x, double y) {
	draw((int) x, (int) y);
}

template <class T>
void Drawable<T>::draw(int x, int y) {
	// Part of the bitmap that we want to draw
	SDL_Rect source;
	source.x = frames[state][current_frame].xlocation;
	source.y = frames[state][current_frame].ylocation;
	source.w = image_width;
	source.h = image_height;
	// Part of the screen we want to draw the sprite to
	SDL_Rect destination;
	destination.x = x - image_width / 2;
	destination.y = y - image_height / 2;
	destination.w = image_width;
	destination.h = image_height;

	SDL_RenderCopy(renderer, images[state], &source, &destination);
	//SDL_DestroyTexture(bitmap);

	time++;
	if (time >= frames[state][current_frame].duration / (1000 / FPS)) {
		current_frame = (current_frame + 1) % frames[state].size();
		time = 0;
	}
}

template <class T>
SDL_Texture * Drawable<T>::createBitmap(std::string path) {
	SDL_Surface * surface = SDL_LoadBMP(path.c_str());
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	SDL_Texture* bitmap = SDL_CreateTextureFromSurface(renderer, surface);
	return bitmap;
}

template <class T>
void Drawable<T>::parseXML(std::string path) {
	using namespace rapidxml;
	xml_document<> doc;
	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	image_height = atoi(pRoot->first_attribute("height")->value());
	image_width = atoi(pRoot->first_attribute("width")->value());
	for (xml_node<> *pNode = pRoot->first_node("animation"); pNode; pNode = pNode->next_sibling()) {
		images.push_back(createBitmap(pNode->first_attribute("image")->value()));
		frames.push_back(std::vector<frame>());
		for (xml_node<> *fNode = pNode->first_node("frame"); fNode; fNode = fNode->next_sibling()) {
			frame nFrame;
			nFrame.xlocation = atoi(fNode->first_attribute("xlocation")->value());
			nFrame.ylocation = atoi(fNode->first_attribute("ylocation")->value());
			nFrame.duration = atoi(fNode->first_attribute("duration")->value());
			frames[images.size() - 1].push_back(nFrame);
		}
	}
}

template <class T>
void Drawable<T>::setState(int value) {
	state = value;
	current_frame = 0;
	time = 0;
}

template <class T>
void Drawable<T>::setup(std::string path) {
	parseXML(path);
}



#endif