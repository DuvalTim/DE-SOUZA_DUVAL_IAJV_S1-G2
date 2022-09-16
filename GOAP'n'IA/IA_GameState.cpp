#include "IA_GameState.h"
#include "IA_Village.h"

IA_GameState::IA_GameState() {

    //Création des villages
    IA_Village IA(IA_villageois, IA_soldat, IA_maison, IA_food);
    IA_Village J(J_villageois, J_soldat, J_maison, J_food);

    IA_Reflexion(IA, J);

}

void IA_GameState::IA_Reflexion(IA_Village AI, IA_Village Joueur) {
    //Calcule des Actions

    //problème de modification de la valeur Max_Score

    int Max_Score = AI.Calcul_Farm();
    std::string Action_A_Realiser = "Collectionner plus de ressources";


    int v = AI.Calcul_Villageois();
    if (Max_Score < v) {
        int Max_Score = v;
        std::string Action_A_Realiser = "Creer plus de villageois";

    }

    int s = AI.Calcul_Soldier();
    if (Max_Score < s) {
        int Max_Score = s;
        std::string Action_A_Realiser = "Creer plus de soldats";

    }

    int m = AI.Calcul_Maison();
    if (Max_Score < m) {
        int Max_Score = m;
        std::string Action_A_Realiser = "Creer plus de maisons";

    }

    int a = AI.Calcul_Attaque(Joueur);
    if (Max_Score < a) {
        int Max_Score = a;
        std::string Action_A_Realiser = "Lancer une attaque :";

    }
    std::cout << std::endl;
    
    //std::cout << "Action a realiser : " << Action_A_Realiser << std::endl;

}