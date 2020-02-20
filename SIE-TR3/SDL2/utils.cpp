#include "headers.h"

SDL_Texture *textureFile(const char* file_name, SDL_Renderer *renderer) {
    SDL_Surface *image = IMG_Load(file_name);
    SDL_Texture * image_texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    return image_texture;
}

void DrawText(SDL_Renderer *renderer, bool isAuto) {
    TTF_Font * font = TTF_OpenFont("/Users/enzogiova/Documents/GitHub/SDL2/SDL2/files/FreeSans.ttf", 25);
    if (font == NULL) {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }
    SDL_Surface * fontSurface = TTF_RenderText_Solid(font, isAuto ? "Mode: Automa" : "Mode: Manual", {255, 255, 255});
    SDL_Texture * fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(fontTexture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {575, 20, texW, texH};
    SDL_RenderCopy(renderer, fontTexture, NULL, &dstrect);
}

void DrawLines(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, 0, 350, 800, 350);
    SDL_RenderDrawLine(renderer, 500, 75, 800, 75);
    SDL_RenderDrawLine(renderer, 500, 0, 500, 350);
}

void DrawRotationArrow(SDL_Renderer *renderer, const char* file_name, int posX, int posY, double rotation) {
    SDL_Surface *image = IMG_Load(file_name);
    SDL_Texture * image_texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    SDL_Texture * toRender = image_texture;
    SDL_Rect dest = {0, 0, 0, 0};
    SDL_QueryTexture(toRender, NULL, NULL, &dest.w, &dest.h);
    if (posX >= 900) posX = 900;
    if (posY >= 600) posY = 600;
    dest.x = (posX - dest.w) / 2;
    dest.y = (posY - dest.h) / 2;
    SDL_RenderCopyEx(renderer, toRender, NULL, &dest, rotation, NULL, SDL_FLIP_NONE);
}
