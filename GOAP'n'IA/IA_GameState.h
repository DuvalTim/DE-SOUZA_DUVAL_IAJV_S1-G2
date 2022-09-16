#pragma once
#include "IA_Village.h"

class IA_GameState
{
public:

	//Valeurs à modifier pour tester

	//prioritise: 100 food > maisons > 100 villageois > Soldat

	int IA_villageois = 40;
	int IA_soldat = 10;
	int IA_food = 100;
	int IA_maison = 200;

	int J_villageois = 60;
	int J_soldat = 800;
	int J_food = 100;
	int J_maison = 1000;

	IA_GameState();

	void IA_Reflexion(IA_Village AI, IA_Village Joueur);
};

