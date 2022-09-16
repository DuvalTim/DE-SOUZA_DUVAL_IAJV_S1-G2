#pragma once
#include <iostream>

class IA_Village
{

public:
	uint16_t Nombre_Villageois;
	uint16_t Nombre_Soldat;
	uint16_t Nombre_Nourriture;
	uint16_t Nombre_Maison;
	uint16_t Population;


	IA_Village(int& _villageois, int& _Soldat, int& _maison, int& _food);
	void Farm();
	void Add_Villageois();
	void Convert_Villageois_to_Soldier();
	void Add_maison();
	void Attack(IA_Village Ennemi);

	float Calcul_Farm();
	float Calcul_Villageois();
	float Calcul_Soldier();
	float Calcul_Maison();
	float Calcul_Attaque(IA_Village Ennemi);



};

