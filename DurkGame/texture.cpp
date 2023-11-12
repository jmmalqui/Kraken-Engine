#include "pch.h"
#include "Texture.hpp"


namespace dk {
	Texture::Texture(dk::RenderWindow& window, const char* fileDir)
	: window(window) {
		loadTextureFile(fileDir);
	}

	Texture::Texture(dk::RenderWindow& window, dk::Surface& surface)
	: window(window) {
		texture = SDL_CreateTextureFromSurface(window.getRenderer(), surface.get());
		if (!texture) {
			std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			exit(3);
		}

		int w, h;
		SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
		this->rect = { 0, 0, w, h };
	}

	void Texture::loadTextureFile(const char* fileDir) {
		texture = IMG_LoadTexture(window.getRenderer(), fileDir);
		if (!texture) {
			std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			exit(3);
		}

		int w, h;
		SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
		this->rect = { 0, 0, w, h };
	}

	void Texture::blit(dk::Rect dstRect) {
		SDL_RenderCopyF(window.getRenderer(), texture, nullptr, &dstRect);
	}

	void Texture::blitAngle(dk::Rect dstRect, float angleDeg) {
		SDL_RenderCopyExF(window.getRenderer(), texture, nullptr, &dstRect, angleDeg, nullptr, SDL_FLIP_NONE);
	}

	dk::math::Vector2 dk::Texture::getSize() const {
		return { rect.w, rect.h };
	}

	void Texture::setSize(int w, int h) {
		rect.w = (float)w;
		rect.h = (float)h;
	}

	void Texture::scaleBy(float scale) {
		rect.w = rect.w * scale;
		rect.h = rect.h * scale;
	}

	dk::Rect Texture::getRect() const {
		return rect;
	}
}