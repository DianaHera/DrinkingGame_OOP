#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Jucatori {
public:
    Jucatori(const string& primeste_nume) : nume(primeste_nume) {}

    virtual void afisare() {
        cout << "Nume: " << nume << "\n";
    }

    const string& getNume() const {
        return nume;
    }

protected:
    string nume;
};

class Reguli {
public:
    Reguli(const string& primeste_regula) : regula(primeste_regula) {}

    void afisare() {
        cout << "Regula: " << regula << "\n";
    }

    const string& getRegula() const {
        return regula;
    }

protected:
    string regula;
};

class DrinkingGame {
public:
    DrinkingGame(const vector<Jucatori*>& jucatori, const vector<Reguli*>& reguli) {
        if (!jucatori.empty()) {
            int randomJucatorIndex = rand() % jucatori.size();
            nume = jucatori[randomJucatorIndex]->getNume();
        }

        if (!reguli.empty()) {
            int randomRegulaIndex = rand() % reguli.size();
            regula = reguli[randomRegulaIndex]->getRegula();
        }
    }
    void afisare() {
        cout << "Nume: " << nume << "\n";
        cout << "Regula: " << regula << "\n";
    }
    ~DrinkingGame()=default;
private:
    string nume;
    string regula;
};

int main() {
    srand(static_cast<unsigned>(time(0))); // Inițializați generatorul de numere aleatoare

    vector<Jucatori*> jucatori;
    jucatori.push_back(new Jucatori("Diana"));
    jucatori.push_back(new Jucatori("Ana"));
    jucatori.push_back(new Jucatori("George"));

    vector<Reguli*> reguli;
    reguli.push_back(new Reguli("Povesteste ultima ta intalnire sau bea de 3 ori"));
    reguli.push_back(new Reguli("Da mail unui profesor si spune-i ca ai 14 warninguri sau termina-ti bautura"));
    reguli.push_back(new Reguli("Cata hartie igienica ai folosit cand te-ai dus la baie, de atatea ori trebuie sa bei"));
    reguli.push_back(new Reguli("Termina proiectul la OOP inainte de termen sau ai restanta"));
    reguli.push_back(new Reguli("Da-i Fuck, Marry, Kill jucatorului din stanga"));


    DrinkingGame game(jucatori, reguli);
    game.afisare();

    // Eliberați memoria pentru obiectele create dinamic
    for (Jucatori* jucator : jucatori) {
        delete jucator;
    }

    for (Reguli* regula : reguli) {
        delete regula;
    }

    return 0;
}
