#ifndef GAME_H
#define GAME_H

// #include <memory>
// #include <typeinfo>
// #include <vector>

#include "background.h"
#include "ball.h"
#include "brick.h"
#include "constants.h"
#include "paddle.h"


using entityVectory = std::vector<std::unique_ptr<entity>>;
using entityAliasVector = std::vector<entity *>;

class EntityManager {

    entityVectory allEntities;
    std::map<size_t, entityAliasVector> groupedEntities; //key is stored es size_t hash

public:

    template<typename T, typename... Args>
    T& create(Args&&... args)
    {

        static_assert(std::is_base_of<entity, T>::value,
                      R"("T" type parameter in create() must be derived from "entity")");

        auto ptr{std::make_unique<T>(std::forward<Args>(args)...)};

        auto ptrAlias = ptr.get();

        auto hash = typeid(T).hash_code();

        groupedEntities[hash].emplace_back(ptrAlias);

        allEntities.emplace_back(std::move(ptr));

        return *ptrAlias;
    }

    void refresh();
    void clear();

    template <typename T>
    auto& getAll() {
        return groupedEntities[typeid(T).hash_code()];
    }

    template <typename T, typename Func>
    void applyAll(const Func& func){
        auto& entityGroup{getAll<T>()};

        for (auto ptr : entityGroup)
            func(*dynamic_cast<T*>(ptr));
    }

    void update();
    void draw(sf::RenderWindow& window);
};


class game {

    sf::RenderWindow game_window{{constants::window_width, constants::window_height},
			       "Simple Breakout Game Version 1",};


    EntityManager manager;

    enum class gameState {
        paused,
        gameOver,
        running,
        playerWins,
    };

    sf::Font veranda;
    sf::Text textState, textLives;

    gameState state;

    int lives{constants::playerLives};

    public:

    game();
    void reset();
    void run();

};



#endif // GAME_H
