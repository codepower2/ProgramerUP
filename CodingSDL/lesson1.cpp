/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

// 将SDL函数和数据类型包含进来
#include "SDL/SDL.h"

int main()
{
    // 声明表面
    SDL_Surface* hello = NULL;
    SDL_Surface* screen = NULL;

    // 启动SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    // 设置窗口
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

    // 加载图像
    hello = SDL_LoadBMP("hello.bmp");

    // 将图像应用到窗口上
    SDL_BlitSurface(hello, NULL, screen, NULL);

    // 更新窗口
    SDL_Flip(screen);

    // 暂停
    SDL_Delay(2000);

    // 释放已加载的图像
    SDL_FreeSurface(hello);

    // 退出SDL
    SDL_Quit();

    return 0;
}
