#include <iostream>
#define MAX_PROMO 66
/*Créer un programme pour une école qui gère un ensemble de spécialités.
Déclarer une énumération Spécialité avec cinq éléments : IA, Web, Logiciel,
Système Immersif Et Cybersécurité. Utilisez un tableau pour stocker les
spécialités des étudiants de la promo. Initialiser ce tableau avec les
spécialités et associer le nombre d’étudiants de manière aléatoire (entre 12 et
66). Écrivez une fonction “afficherSpecialite” qui prend une spécialité en

_5

paramètre et affiche son nom ainsi que le nombre de places disponible. Dans
le programme principal, parcourez le tableau de spécialités et utilisez la
fonction “afficherSpecialite” pour afficher le nom de chaque spécialité.
*/

enum Specialite {
    IA,
    Web,
    Logiciel,
    SystemeImmersif,
    Cybersecurite
};

struct SpecialiteEtudiant {
    Specialite specialite;
    int nombreEtudiants;
};

void afficherSpecialite(SpecialiteEtudiant specialiteEtudiant) {
    std::string specialite;
    switch (specialiteEtudiant.specialite) {
        case IA:
            specialite = "IA";
            break;
        case Web:
            specialite = "Web";
            break;
        case Logiciel:
            specialite = "Logiciel";
            break;
        case SystemeImmersif:
            specialite = "Systeme Immersif";
            break;
        case Cybersecurite:
            specialite = "Cybersecurite";
            break;
    }
    std::cout << "Specialite: " << specialite << ", Nombre de place disponible: " << MAX_PROMO  - specialiteEtudiant.nombreEtudiants << std::endl;
}



int main() {
    SpecialiteEtudiant specialites[5] = {
        {IA, rand() % 55 + 12},
        {Web, rand() % 55 + 12},
        {Logiciel, rand() % 55 + 12},
        {SystemeImmersif, rand() % 55 + 12},
        {Cybersecurite, rand() % 55 + 12}
    };

    for (int i = 0; i < 5; i++) {
        afficherSpecialite(specialites[i]);
    }

    return 0;
    
}
