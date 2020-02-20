#include "headers.h"

bool isAppRunning = true;
bool isConsole = false;
bool isAuto = true;

int PosX = 0;
int PosY = 0;
double Rotation = 0;

int main(int argc, char ** argv) {
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    startHost();
    
    SDL_Window * window = SDL_CreateWindow("Remote Control", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, isConsole ? 400 : 350, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    
    SDL_Texture * imageAll = textureFile("all.png", renderer);
    SDL_Texture * imageUp = textureFile("up.png", renderer);
    SDL_Texture * imageLeft = textureFile("left.png", renderer);
    SDL_Texture * imageRight = textureFile("right.png", renderer);
    
    SDL_Texture * toRender = imageAll;
    SDL_Rect dest = {0, 0, 0, 0};
    SDL_QueryTexture(toRender, NULL, NULL, &dest.w, &dest.h);
    dest.x = (1300 - dest.w) / 2;
    dest.y = (400 - dest.h) / 2;
    
    while (isAppRunning) {
        SDL_Delay(1000 / 30);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        
        while(SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                isAppRunning = false;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
                        isAuto = !isAuto;
                        break;
                    case SDLK_DOWN:
                        if (!isAuto) toRender = imageAll;
                        //if (isAuto) posY = posY + 10;
                        break;
                    case SDLK_UP:
                        if (!isAuto) toRender = imageUp;
                        //if (isAuto) posY = posY - 10;
                        break;
                    case SDLK_LEFT:
                        if (!isAuto) toRender = imageLeft;
                        //if (isAuto) posX = posX - 10;
                        break;
                    case SDLK_RIGHT:
                        if (!isAuto) toRender = imageRight;
                        //if (isAuto) posX = posX + 10;
                        break;
                }
            }
        }
        if (isAuto) toRender = imageAll;
        if (Rotation > 359) Rotation = 0;
        Rotation = Rotation + 1;
        
        SDL_RenderCopy(renderer, toRender, NULL, &dest);
        DrawRotationArrow(renderer, "up.png", PosX, PosY, Rotation);
        DrawText(renderer, isAuto);
        DrawLines(renderer);
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}

void setPosX(int x) {
    PosX = x;
}

void setPosY(int y) {
    PosY = y;
}
