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
    

    private:
        std::string nom;
    public:
        Pingouin(std::string nom) {
          vitesse_nage = 2.5;
          vitesse_marche = 1.5;
          this->nom = nom;
        }

        void nage() {
          std::cout << "Je nage à " << vitesse_nage << " m/s" << std::endl;
        }

        void marche() {
          std::cout << "Je marche à " << vitesse_marche << " m/s" << std::endl;
        }

    void sePresenter() {
      std::cout << "Je suis " << nom << std::endl;
    }
};


int main() {
    Pingouin pingouin("Tux");
    pingouin.sePresenter();
    pingouin.nage();
    pingouin.marche();
    return 0;
}