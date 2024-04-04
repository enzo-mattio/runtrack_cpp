#include <iostream>


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

    // Méthodes publiques de la classe Pingouin
    void nage() {
        std::cout << "Je nage à " << vitesse_nage << " m/s" << std::endl;
    }

    void marche() {
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



int main() {
    Pingouin pingouin("Tux");
    pingouin.sePresenter();
    pingouin.nage();
    pingouin.marche();
    pingouin.changerVitesseGlisse(3.5);
    return 0;
}