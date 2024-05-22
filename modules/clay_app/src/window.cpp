#include <clay_app/window.h>
#include <clay_core/log.h>

#include <SDL.h>

namespace clay
{
namespace app
{
void Window::init(const WindowConfig& config)
{
    CLAY_LOG_INFO("Initializing window...");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        CLAY_LOG_ERROR("Failed to initialize SDL: %s", SDL_GetError());
        return;
    }

    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    platform_handle = SDL_CreateWindow(config.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.width, config.height, window_flags);

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
                    case SDL_WINDOWEVENT_SIZE_CHANGED:
                    case SDL_WINDOWEVENT_RESIZED: {
                        u32 new_width  = (u32)(event.window.data1);
                        u32 new_height = (u32)(event.window.data2);
                        if (new_width != width || new_height != height)
                        {
                            resized = true;
                            width   = new_width;
                            height  = new_height;
                            CLAY_LOG_INFO("Window resized to {}x{}", width, height);
                        }
                        break;
                    }
                    case SDL_WINDOWEVENT_MAXIMIZED: {
                        minimized = false;
                        CLAY_LOG_INFO("Window maximized");
                        break;
                    }
                    case SDL_WINDOWEVENT_MINIMIZED: {
                        minimized = true;
                        CLAY_LOG_INFO("Window minimized");
                        break;
                    }
                    case SDL_WINDOWEVENT_RESTORED: {
                        minimized = false;
                        CLAY_LOG_INFO("Window restored");
                        break;
                    }
                    case SDL_WINDOWEVENT_CLOSE: {
                        requested_exit = true;
                        CLAY_LOG_INFO("Window close event received.");
                        break;
                    }
                }
                break;
        }
    }
}
} // namespace app
} // namespace clay