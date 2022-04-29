#ifndef Game_hpp
#define Game_hpp
#include <SDL.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include "HUD.hpp"
#include "Flipper.hpp"
#include <vector>
#include <random>
/**
 * @brief 
 * 
 */
class Game {
    private:
        bool is_running_;
        SDL_Window* window_;
        SDL_Renderer* renderer_;
        Player player_;
        std::vector<Bullet> bullets_;
        HUD hud_;
        Level level_;
        std::vector<Enemy*> enemies_;
        SDL_Texture* texture_;
        SDL_Rect dst_;
    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        void test_collisions();
        void generate_enemies();
        inline SDL_Renderer* get_renderer() const {return renderer_;};
        const Level& get_level() const {return level_;};
        inline bool running() const {return is_running_;};
};
#endif
