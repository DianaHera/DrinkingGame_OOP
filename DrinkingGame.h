#ifndef DRINKING_GAME_HPP
#define DRINKING_GAME_HPP

#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "Player.h"
#include "Rule.h"

class DrinkingGame {
public:
    DrinkingGame(const std::vector<std::unique_ptr<Player>>& players, const std::vector<std::unique_ptr<Rule>>& rules);

    static int number_rounds;
    static int get_nr();

    void write() const;

private:
    std::unique_ptr<Player> current_player;
    std::unique_ptr<Rule> current_rule;
};

#endif // DRINKING_GAME_HPP
