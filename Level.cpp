#include "Level.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Lane.hpp"
#include <fstream>

Level::Level() :
    lanes_{},
    player_pos_{0},
    circular_{false},
    center_{0,0},
    renderer_{nullptr}
{   
}

Level::Level(const Level& level) :
    lanes_{level.lanes_},
    player_pos_{level.player_pos_},
    circular_{level.circular_},
    center_{level.center_},
    renderer_{level.renderer_}
{
    std::cout << "Level copy constructor called" << std::endl;
}

void Level::init(SDL_Renderer* renderer,unsigned int lvl)
{
    int width,height;
    SDL_GetRendererOutputSize(renderer,&width,&height);
    std::ifstream file;
    file.open("../Assets/Levels/level"+std::to_string(lvl)+".txt");
    if (file.is_open()) 
    {   
        float xmin,xmax,ymin,ymax;
        int x_center,y_center;
        float scale;
        file >> circular_;
        file >> xmin >> xmax;
        file >> ymin >> ymax;
        file >> x_center >> y_center;
        file >> scale;
        center_ = v_normalize(x_center,xmin,xmax,y_center,ymin,ymax,height,height);
        while(!file.eof())
        {
            float x_FR,y_FR,x_FL,y_FL; // FR = Front Right, FL = Front Left
            file >> x_FR >> y_FR >> x_FL >> y_FL;
            const vertex fr_norm = v_normalize(x_FR,xmin,xmax,y_FR,ymin,ymax,height,height);
            const vertex fl_norm = v_normalize(x_FL,xmin,xmax,y_FL,ymin,ymax,height,height);
            lanes_.push_back(Lane(center_,scale,fr_norm,fl_norm));
        }
    }
    else
        std::cout << "Error opening file" << std::endl;
}
void Level::update(unsigned int player_pos)
{
    player_pos_ = player_pos;
    for (auto &lane : lanes_) {
        lane.set_active(false);
    }
    lanes_[player_pos_].set_active(true);
}

void Level::render(SDL_Renderer* renderer)
{
    
    for (auto lane : lanes_) {
        lane.render(renderer);
    }
    lanes_[player_pos_].render(renderer);
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // SDL_RenderClear(renderer);
    
}

void Level::clean()
{
    
}