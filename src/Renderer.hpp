#pragma once

#include <cstdint>
#include <string>

#include "SDL.h"
#include "SDL_opengl.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include <opencv2/opencv.hpp>

#include "SimComponentBase.hpp"

class Renderer : public SimComponentBase
{
public:
    Renderer(class Simulator* simulator, std::string dest_ip);
    ~Renderer();

    void update();

private:
    GLuint convertCVmatToGLtexture(cv::Mat* mat);

    /// Chip simulator window name
    std::string sim_chip_window_ = "Chip Simulator";

    /// Marble simulator window name
    std::string sim_marble_window_ = "Marble Simulator";

    // Window size
    int32_t win_width_;
    int32_t win_height_;

    SDL_Window* win_;
    SDL_GLContext gl_context_;
    SDL_Renderer* renderer_;
    
    ImGuiContext* imgui_context_;

    ImGuiIO* io_;

    /// Chip simulator texture
    cv::Mat sim_chip_img_;

public:
    /// Pixel size in simulator
    uint32_t pixel_size_;

    /// Destination ip address for mouse event
    std::string dest_ip_;
};
