#include "SDL_video.h"
#include <clay_app/window.h>
#include <clay_core/log.h>

#include <SDL.h>

namespace clay
{
namespace app
{

void Window::init()
{
    CLAY_LOG_INFO("Initializing window...");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        CLAY_LOG_ERROR("Failed to initialize SDL: %s", SDL_GetError());
        return;
    }

    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    platform_handle = SDL_CreateWindow("Clay", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);

    CLAY_LOG_INFO("Window initialized successfully!");
}

void Window::shutdown()
{
    SDL_DestroyWindow((SDL_Window*)platform_handle);
    SDL_Quit();

    CLAY_LOG_INFO("Window has been shut down!");
}

void Window::handle_events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                requested_exit = true;
                break;
            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {
                    case SDL_WINDOWEVENT_RESIZED:
                        resized = true;
                        width   = event.window.data1;
                        height  = event.window.data2;
                        break;
                    case SDL_WINDOWEVENT_MINIMIZED:
                        minimized = true;
                        break;
                    case SDL_WINDOWEVENT_RESTORED:
                        minimized = false;
                        break;
                }
                break;
        }
    }
}

} // namespace app
} // namespace clay