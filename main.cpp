#include <iostream>
#include <vector>
#include "DrinkingGame.h"
#include "Player.h"
#include "Rule.h"

int main() {
    try {
        srand(static_cast<unsigned>(time(0)));

        std::vector<std::unique_ptr<Player>> players;
        players.push_back(std::make_unique<RegularPlayer>("Diana"));
        players.push_back(std::make_unique<RegularPlayer>("Ana"));
        players.push_back(std::make_unique<SpecialPlayer>("Andreea", "Esti expert la joc, bei un shot cu alt jucator"));

        std::vector<std::unique_ptr<Rule>> rules;
        rules.push_back(std::make_unique<RegularRule>("Povesteste ultima ta intalnire sau bea de 3 ori"));
        rules.push_back(std::make_unique<SpecialRule>("Da mail unui profesor si spune-i ca ai 14 warninguri sau termina-ti bautura", "Profesorul va fi impresionat si vei scapa de bautura"));
        rules.push_back(std::make_unique<RegularRule>("Cata hartie igienica ai folosit cand te-ai dus la baie, de atatea ori trebuie sa bei"));
        rules.push_back(std::make_unique<RegularRule>("Termina proiectul la OOP inainte de termen sau ai restanta"));
        rules.push_back(std::make_unique<SpecialRule>("Da-i Fuck, Marry, Kill jucatorului din stanga", "Vei primi o misiune dificila, dar vei aduce zambete pe fata multora"));

        DrinkingGame game(players, rules);
        game.write();
        std::cout << "Numar runde:" << " " << DrinkingGame::get_nr() << "\n";

    } catch (const std::out_of_range& e) {
        std::cerr << "Exceptie: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
