#include "DrinkingGame.h"

int DrinkingGame::number_rounds = 0;

DrinkingGame::DrinkingGame(const std::vector<std::unique_ptr<Player>>& players, const std::vector<std::unique_ptr<Rule>>& rules) {
    if (!players.empty()) {
        int random_player = rand() % players.size();
        current_player = players[random_player]->clone();
    } else {
        throw std::out_of_range("Vectorul de jucatori este gol");
    }

    if (!rules.empty()) {
        int random_rule = rand() % rules.size();
        current_rule = rules[random_rule]->clone();
    } else {
        throw std::out_of_range("Vectorul de reguli este gol");
    }
}

void DrinkingGame::write() const {
    current_player->display();
    current_rule->display();
    number_rounds++;
}
    int DrinkingGame::get_nr() {
       return number_rounds;
}