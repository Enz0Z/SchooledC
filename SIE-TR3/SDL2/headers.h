#include <stdio.h>
#include <regex>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

void DrawLines(SDL_Renderer *renderer);
void DrawText(SDL_Renderer *renderer, bool isAuto);
void DrawRotationArrow(SDL_Renderer *renderer, const char* file_name, int posX, int posY, double rotation);
SDL_Texture *textureFile(const char* file_name, SDL_Renderer *renderer);

void startHost();
void setPosX(int x);
void setPosY(int y);
