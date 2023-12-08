#include "Player.h"

Player::Player(const std::string& get_name) : name(get_name) {}

void Player::display() const {
    std::cout << "Nume: " << name << "\n";
}

const std::string& Player::getName() const {
    return name;
}

RegularPlayer::RegularPlayer(const std::string& get_name) : Player(get_name) {}

std::unique_ptr<Player> RegularPlayer::clone() const {
    return std::make_unique<RegularPlayer>(*this);
}

SpecialPlayer::SpecialPlayer(const std::string& get_name, const std::string& get_special_trait)
        : Player(get_name), special_trait(get_special_trait) {}

std::unique_ptr<Player> SpecialPlayer::clone() const {
    return std::make_unique<SpecialPlayer>(*this);
}

void SpecialPlayer::display() const {
    Player::display();
    std::cout << "Trasatura speciala: " << special_trait << "\n";
}
