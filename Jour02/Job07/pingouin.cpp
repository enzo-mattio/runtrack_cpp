#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <map>
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

class Competences {
public: 

    std::map<std::string, int> competences;

    Competences() {}

    // Constructeur pour initialiser les compétences avec des niveaux aléatoires
    Competences(int niveauMax) {
        std::vector<std::string> nomsCompetences = {"nage", "marche", "glisse"};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, niveauMax);

        for (const auto& nom : nomsCompetences) {
            competences[nom] = distrib(gen);
        }
    }

    void changerNiveauCompetence(const std::string& nom, int nouveauNiveau) {
        competences[nom] = nouveauNiveau;
    }

    void modifierNiveauxAleatoires(int niveauMax) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, niveauMax);

        for (auto& competence : competences) {
            competence.second = distrib(gen);
        }
    }

    void afficherCompetences() const {
        std::cout << "Liste des compétences :\n";
        for (const auto& competence : competences) {
            std::cout << "- " << competence.first << " : Niveau " << competence.second << std::endl;
        }
    }
};

class Pingouin : public Aquatique, public Terrestre {
public:
    
    Competences competences;
    Pingouin() : vitesse_nage(0), vitesse_marche(0), vitesse_glisse(0), nom(""), competences() {}

    Pingouin(std::string nom, double nage, double marche, double glisse, int niveauMax)
        : vitesse_nage(nage), vitesse_marche(marche), vitesse_glisse(glisse), nom(nom), competences(niveauMax) {}

    Pingouin(const Pingouin &autre) 
        : vitesse_nage(autre.vitesse_nage), vitesse_marche(autre.vitesse_marche), vitesse_glisse(autre.vitesse_glisse), 
        nom(autre.nom), competences(autre.competences) {}

    static std::vector<std::shared_ptr<Pingouin>> colony;

    double tempsParcours() {
        double temps = 0;
        temps += 15 / (vitesse_glisse * competences.competences["glisse"]);
        temps += 20 / (vitesse_marche * competences.competences["marche"]);
        temps += 50 / (vitesse_nage * competences.competences["nage"]);
        temps += 15 / (vitesse_marche * competences.competences["marche"]);
        return temps;
    }

    static void afficherTempsParcours() {
        for (const auto& pingouinPtr : colony) {
            std::cout << "Le pingouin " << pingouinPtr->nom << " met " << pingouinPtr->tempsParcours() << " secondes pour parcourir la piste." << std::endl;
        }
    }

    void nage() override {
        std::cout << "Je nage à " << vitesse_nage << " m/s" << std::endl;
    }

    void marche() override {
        std::cout << "Je marche à " << vitesse_marche << " m/s" << std::endl;
    }

    std::string getNom() {
        return nom;
    }
    void changerVitesseGlisse(double vitesse) {
        vitesse_glisse = vitesse;
        std::cout << "Je glisse maintenant à " << vitesse_glisse << " m/s" << std::endl;
    }

    void sePresenter() {
        std::cout << "Je suis " << nom << std::endl;
    }

    ~Pingouin() {
        std::cout << "Destruction de " << nom << std::endl;
    }
private:
    std::string nom;
    double vitesse_nage;
    double vitesse_marche;
    double vitesse_glisse;
};

class LieuxRencontre {
public:
    static std::list<std::string> lieux;

    static void insererLieu(const std::string& lieu) {
        lieux.push_back(lieu);
    }

    static void retirerLieu(const std::string& lieu) {
        auto it = std::find(lieux.begin(), lieux.end(), lieu);
        if (it != lieux.end()) {
            lieux.erase(it);
        }
    }

    static void afficherLieux() {
        std::cout << "Liste des lieux de rencontre :\n";
        for (const auto& lieu : lieux) {
            std::cout << "- " << lieu << std::endl;
        }
    }
};

std::vector<std::shared_ptr<Pingouin>> Pingouin::colony;

std::list<std::string> LieuxRencontre::lieux;

int main() {
    LieuxRencontre::insererLieu("lac");
    LieuxRencontre::insererLieu("glacier");
    LieuxRencontre::insererLieu("montagne");

    LieuxRencontre::afficherLieux();

    int niveauMaxCompetences = 10; // Niveau maximal des compétences

    // Création des pingouins avec des compétences aléatoires
    Pingouin::colony.push_back(std::make_shared<Pingouin>("Toto", 2.5, 1.5, 0, niveauMaxCompetences));
    Pingouin::colony.push_back(std::make_shared<Pingouin>("Loulou", 2.5, 1.5, 0, niveauMaxCompetences));
    Pingouin::colony.push_back(std::make_shared<Pingouin>("Titi", 2.5, 1.5, 0, niveauMaxCompetences));

    // Modifier aléatoirement les niveaux de compétences pour chaque pingouin
    for (const auto& pingouinPtr : Pingouin::colony) {
        pingouinPtr->competences.modifierNiveauxAleatoires(niveauMaxCompetences);
    }

    for (const auto& pingouinPtr : Pingouin::colony) {
        pingouinPtr->sePresenter();
        pingouinPtr->nage();
        pingouinPtr->marche();
        pingouinPtr->changerVitesseGlisse(2.0);
        std::cout << "Compétences du pingouin " << pingouinPtr->getNom() << ":" << std::endl;
        pingouinPtr->competences.afficherCompetences();
        std::cout << std::endl;
    }

    std::sort(Pingouin::colony.begin(), Pingouin::colony.end(), [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
        return a->tempsParcours() < b->tempsParcours();
    });

    Pingouin::afficherTempsParcours();

    return 0;
}
