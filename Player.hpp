#ifndef Player_hpp
#define Player_hpp
#include "Object.hpp"
#include "Level.hpp"
#include "Bullet.hpp"


class Player: public Object {
    private:
        int nb_lives_;
        int score_;
        bool is_shooting_;
    public:
        Player(const Player& player);
        Player(const Level& terrain);
        Player();
        virtual ~Player(){};

        void move_right(const Level& terrain);
        void move_left(const Level& terrain);
        void shoot();
        inline int get_score() const {return score_;};
        inline int get_nb_lives() const {return nb_lives_;};
        
        void update();

        void set_is_shooting(bool is_shooting) { is_shooting_ = is_shooting; }
        const bool& get_is_shooting() const { return is_shooting_; }
};

#endif