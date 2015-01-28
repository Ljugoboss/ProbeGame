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
class Drawable : public virtual Locatable {
private:
public:
	int state;
	int time;
	int current_frame;
	

	static std::vector<SDL_Texture*> images;
	static std::vector<std::vector<frame>> frames;

	int image_width;
	int image_height;

	Drawable() { 
		time = 0;
		state = 0;
		current_frame = 0;
	}

	virtual void setup() = 0;

	void draw();

	SDL_Texture * createBitmap(std::string path);

	void parseXML(std::string file_name);

	void setState(int value);
};

template <class T>
void Drawable<T>::draw() {
	// Part of the bitmap that we want to draw
	SDL_Rect source;
	source.x = frames[state][current_frame].xlocation;
	source.y = frames[state][current_frame].ylocation;
	source.w = image_width;
	source.h = image_height;
	// Part of the screen we want to draw the sprite to
	SDL_Rect destination;
	destination.x = (int)getX() - image_width / 2;
	destination.y = (int)getY() - image_height / 2;
	destination.w = image_width;
	destination.h = image_height;

	SDL_RenderCopy(getLevel()->getRenderer(), images[state], &source, &destination);
	//SDL_DestroyTexture(bitmap);

	time++;
	if (time >= frames[state][current_frame].duration / (1000 / getLevel()->FPS)) {
		current_frame = (current_frame + 1) % frames[state].size();
		time = 0;
	}
}

template <class T>
SDL_Texture * Drawable<T>::createBitmap(std::string path) {
	SDL_Surface * surface = SDL_LoadBMP(path.c_str());
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	SDL_Texture* bitmap = SDL_CreateTextureFromSurface(getLevel()->getRenderer(), surface);
	return bitmap;
}

template <class T>
void Drawable<T>::parseXML(std::string file_name) {
	using namespace rapidxml;
	xml_document<> doc;
	std::ifstream file(file_name);
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
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



#endif