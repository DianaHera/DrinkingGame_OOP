#include "Rule.h"

Rule::Rule(const std::string& get_rule) : rule(get_rule) {}

void Rule::display() const {
    std::cout << "Regula: " << rule << "\n";
}

const std::string& Rule::getRule() const {
    return rule;
}

RegularRule::RegularRule(const std::string& get_rule) : Rule(get_rule) {}

std::unique_ptr<Rule> RegularRule::clone() const {
    return std::make_unique<RegularRule>(*this);
}

SpecialRule::SpecialRule(const std::string& get_rule, const std::string& get_special_effect)
        : Rule(get_rule), special_effect(get_special_effect) {}

std::unique_ptr<Rule> SpecialRule::clone() const {
    return std::make_unique<SpecialRule>(*this);
}

void SpecialRule::display() const {
    Rule::display();
    std::cout << "Efect special: " << special_effect << "\n";
}
