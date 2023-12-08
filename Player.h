#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <memory>

class Player {
public:
    Player(const std::string& get_name);
    virtual ~Player() = default;

    virtual std::unique_ptr<Player> clone() const = 0;
    virtual void display() const;

    const std::string& getName() const;

protected:
    std::string name;
};

class RegularPlayer : public Player {
public:
    RegularPlayer(const std::string& get_name);

    std::unique_ptr<Player> clone() const override;
};

class SpecialPlayer : public Player {
public:
    SpecialPlayer(const std::string& get_name, const std::string& get_special_trait);

    std::unique_ptr<Player> clone() const override;
    void display() const override;

private:
    std::string special_trait;
};

#endif // PLAYER_HPP
