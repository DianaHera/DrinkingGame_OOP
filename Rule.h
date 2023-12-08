#ifndef RULE_HPP
#define RULE_HPP

#include <iostream>
#include <string>
#include <memory>

class Rule {
public:
    Rule(const std::string& get_rule);
    virtual ~Rule() = default;

    virtual std::unique_ptr<Rule> clone() const = 0;
    virtual void display() const;

    const std::string& getRule() const;

protected:
    std::string rule;
};

class RegularRule : public Rule {
public:
    RegularRule(const std::string& get_rule);

    std::unique_ptr<Rule> clone() const override;
};

class SpecialRule : public Rule {
public:
    SpecialRule(const std::string& get_rule, const std::string& get_special_effect);

    std::unique_ptr<Rule> clone() const override;
    void display() const override;

private:
    std::string special_effect;
};

#endif // RULE_HPP
