#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <map>
#include <random>
#include <algorithm>
#include <set>
#include <unordered_map>

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
    std::string nom;
    double vitesse_nage;
    double vitesse_marche;
    double vitesse_glisse;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;
    std::unordered_map<std::string, std::string> journal;

    // Ajout du multiset pour stocker les temps enregistrés lors des compétitions
    std::multiset<double> tempsCompetitions;

    Pingouin() : vitesse_nage(0), vitesse_marche(0), vitesse_glisse(0), nom(""), competences() {}

    Pingouin(std::string nom, double nage, double marche, double glisse, int niveauMax)
        : vitesse_nage(nage), vitesse_marche(marche), vitesse_glisse(glisse), nom(nom), competences(niveauMax) {}

    Pingouin(const Pingouin &autre)
        : vitesse_nage(autre.vitesse_nage), vitesse_marche(autre.vitesse_marche), vitesse_glisse(autre.vitesse_glisse),
          nom(autre.nom), competences(autre.competences), journal(autre.journal), tempsCompetitions(autre.tempsCompetitions) {}

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

    void ajouterAmi(const std::shared_ptr<Pingouin>& ami) {
        amis.insert(ami);
    }

    void retirerAmi(const std::shared_ptr<Pingouin>& ami) {
        amis.erase(ami);
    }

    void afficherAmis() const {
        std::cout << "Amis de " << nom << " :" << std::endl;
        for (const auto& amiWeakPtr : amis) {
            if (auto amiSharedPtr = amiWeakPtr.lock()) {
                std::cout << "- " << amiSharedPtr->nom << std::endl;
            }
        }
    }

    void ajouterEntreeJournal(const std::string& date, const std::string& description) {
        journal[date] = description;
    }

    void retirerEntreeJournal(const std::string& date) {
        journal.erase(date);
    }

    void afficherJournal() const {
        std::cout << "Journal de " << nom << " :" << std::endl;
        for (const auto& entry : journal) {
            std::cout << "- Date : " << entry.first << ", Description : " << entry.second << std::endl;
        }
    }

    // Fonction pour ajouter un temps de compétition au multiset
    void ajouterTempsCompetition(double temps) {
        tempsCompetitions.insert(temps);
    }

    // Fonction pour afficher les temps de compétition triés dans l'ordre croissant
    void afficherTempsCompetitions() const {
        std::cout << "Temps de compétitions de " << nom << " :" << std::endl;
        for (const auto& temps : tempsCompetitions) {
            std::cout << "- " << temps << " secondes" << std::endl;
        }
    }
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

    int niveauMaxCompetences = 10;

    Pingouin::colony.push_back(std::make_shared<Pingouin>("Toto", 2.5, 1.5, 0, niveauMaxCompetences));
    Pingouin::colony.push_back(std::make_shared<Pingouin>("Loulou", 2.5, 1.5, 0, niveauMaxCompetences));
    Pingouin::colony.push_back(std::make_shared<Pingouin>("Titi", 2.5, 1.5, 0, niveauMaxCompetences));

    for (const auto& pingouinPtr : Pingouin::colony) {
        pingouinPtr->competences.modifierNiveauxAleatoires(niveauMaxCompetences);
    }

    for (const auto& pingouinPtr : Pingouin::colony) {
        for (const auto& amiPtr : Pingouin::colony) {
            if (pingouinPtr != amiPtr) {
                pingouinPtr->ajouterAmi(amiPtr);
            }
        }
    }

    for (const auto& pingouinPtr : Pingouin::colony) {
        pingouinPtr->ajouterEntreeJournal("2024-04-03", "Première entrée dans le journal");
        pingouinPtr->ajouterEntreeJournal("2024-04-04", "Seconde entrée dans le journal");
    }

    // Ajout de temps de compétition pour chaque pingouin
    Pingouin::colony[0]->ajouterTempsCompetition(20.5);
    Pingouin::colony[0]->ajouterTempsCompetition(18.2);
    Pingouin::colony[1]->ajouterTempsCompetition(21.8);
    Pingouin::colony[2]->ajouterTempsCompetition(19.6);
    Pingouin::colony[2]->ajouterTempsCompetition(22.0);

    for (const auto& pingouinPtr : Pingouin::colony) {
        pingouinPtr->sePresenter();
        pingouinPtr->nage();
        pingouinPtr->marche();
        pingouinPtr->changerVitesseGlisse(2.0);
        std::cout << "Compétences du pingouin " << pingouinPtr->getNom() << ":" << std::endl;
        pingouinPtr->competences.afficherCompetences();
        pingouinPtr->afficherAmis();
        pingouinPtr->afficherJournal();
        pingouinPtr->afficherTempsCompetitions(); // Afficher les temps de compétition
        std::cout << std::endl;
    }

    std::sort(Pingouin::colony.begin(), Pingouin::colony.end(), [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
        return a->tempsParcours() < b->tempsParcours();
    });

    Pingouin::afficherTempsParcours();

    return 0;
}
