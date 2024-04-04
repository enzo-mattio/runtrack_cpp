#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>

class Aquatique {
protected:
    double vitesse_nage;
public:
    virtual void nage() = 0;
};

class Terrestre {
protected:
    double vitesse_marche;
public:
    virtual void marche() = 0;
};



class Pingouin : public Aquatique, public Terrestre {
public:
    // Constructeur par défaut
    Pingouin() : vitesse_nage(0), vitesse_marche(0), vitesse_glisse(0), nom("") {}

    // Constructeur avec paramètre nom
    Pingouin(std::string nom) : vitesse_nage(2.5), vitesse_marche(1.5), vitesse_glisse(0), nom(nom) {}

    // Constructeur par copie
    Pingouin(const Pingouin &autre) : vitesse_nage(autre.vitesse_nage), vitesse_marche(autre.vitesse_marche), vitesse_glisse(autre.vitesse_glisse), nom(autre.nom) {}

    // Vecteur de pingouins
    static std::vector<std::shared_ptr<Pingouin>> colony;
    

    // Méthode pour calculer le temps de parcours
    double tempsParcours() {
        double temps = 0;
        temps += 15 / vitesse_glisse;
        temps += 20 / vitesse_marche;
        temps += 50 / vitesse_nage;
        temps += 15 / vitesse_marche;
        return temps;
    }

    // Méthode statique pour afficher le nom et le temps de parcours de la piste de tous les pingouins
    static void afficherTempsParcours() {
        for (const auto& pingouinPtr : colony) {
            std::cout << "Le pingouin " << pingouinPtr->nom << " met " << pingouinPtr->tempsParcours() << " secondes pour parcourir la piste." << std::endl;
        }
    }

    // Méthodes publiques de la classe Pingouin
    void nage() override {
        std::cout << "Je nage à " << vitesse_nage << " m/s" << std::endl;
    }

    void marche() override {
        std::cout << "Je marche à " << vitesse_marche << " m/s" << std::endl;
    }

    void changerVitesseGlisse(double vitesse) {
        vitesse_glisse = vitesse;
        std::cout << "Je glisse maintenant à " << vitesse_glisse << " m/s" << std::endl;
    }

    void sePresenter() {
        std::cout << "Je suis " << nom << std::endl;
    }

private:
    // Attributs de la classe Pingouin
    std::string nom;
    double vitesse_nage;
    double vitesse_marche;
    double vitesse_glisse;
};

// Les triés par temps de parcours 
std::vector<std::shared_ptr<Pingouin>> Pingouin::colony;


int main() {
    // Initialisation du générateur de nombres aléatoires
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister 19937

    // Définition de la plage des nombres aléatoires
    int min = 100;
    int max = 200;
    
    // Création et ajout des pingouins au vecteur
    Pingouin::colony.push_back(std::make_shared<Pingouin>("Toto"));
    Pingouin::colony.push_back(std::make_shared<Pingouin>("Loulou"));
    Pingouin::colony.push_back(std::make_shared<Pingouin>("Titi"));

    
    // Parcourir et présenter chaque pingouin
    for (const auto& pingouinPtr : Pingouin::colony) {
        std::uniform_int_distribution<> distrib(min, max); // Distribution uniforme d'entiers entre min et max

        // Génération d'un nombre aléatoire
        int randomNumber = distrib(gen);
        pingouinPtr->sePresenter();
        pingouinPtr->nage();
        pingouinPtr->marche();
        pingouinPtr->changerVitesseGlisse(2 * (randomNumber/100.0));
        std::cout << std::endl;
    }
    std::sort(Pingouin::colony.begin(), Pingouin::colony.end(), [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
        return a->tempsParcours() < b->tempsParcours();
    });
    Pingouin::afficherTempsParcours();

    return 0;
}