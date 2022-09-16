#include "IA_Village.h"


IA_Village::IA_Village(int& _villageois, int& _Soldat, int& _maison, int& _food) {
	this->Nombre_Maison = _maison;
	this->Nombre_Villageois = _villageois;
	this->Nombre_Soldat = _Soldat;
	this->Nombre_Nourriture = _food;

	this->Population = Nombre_Villageois + Nombre_Soldat;
}

void IA_Village::Farm() {
	if (Nombre_Villageois > 0) {
		this->Nombre_Nourriture += Nombre_Villageois * 5;
	}
	else { std::cout << "Echec" << std::endl; }
}

void IA_Village::Add_Villageois() {
	if (Nombre_Nourriture >= 100 and Nombre_Maison >= Population + 50) {
		this->Nombre_Villageois += 50;
		this->Nombre_Nourriture -= 100;
		this->Population += 50;
	}
	else { std::cout << "Echec" << std::endl; }
}

void IA_Village::Convert_Villageois_to_Soldier() {
	if (Nombre_Villageois > 50) {
		this->Nombre_Soldat += 50;
		this->Nombre_Villageois -= 50;

	}
	else { std::cout << "Echec" << std::endl; }
}

void IA_Village::Add_maison() {
	if (Nombre_Nourriture >= 50) {
		this->Nombre_Maison += 100;
		this->Nombre_Nourriture -= 50;
	}
	else { std::cout << "Echec" << std::endl; }
}


void IA_Village::Attack(IA_Village Ennemi) {
	int Nombre_Soldat_envoyé = Nombre_Soldat * 0.8;
	Population -= Nombre_Soldat_envoyé;
	Nombre_Soldat -= Nombre_Soldat_envoyé;

	if (Ennemi.Nombre_Soldat - Nombre_Soldat_envoyé * 0.5 >= 0) {
		Ennemi.Nombre_Soldat -= Nombre_Soldat_envoyé * 0.5;
	}
	else {
		Ennemi.Population -= Ennemi.Nombre_Soldat;
		Ennemi.Nombre_Soldat = 0;
		Ennemi.Nombre_Villageois -= Nombre_Soldat_envoyé * 0.5 - Ennemi.Nombre_Soldat;
		Ennemi.Population -= Nombre_Soldat_envoyé * 0.5 - Ennemi.Nombre_Soldat;
	}

}


//==========================

//doit conserver un minimum de 200 
float IA_Village::Calcul_Farm() {
	std::cout << "Collectionner plus de ressources : " << ceil(exp(-4 * Nombre_Nourriture / 200) * 1.1 * 100.0) / 100.0 << std::endl;
	return ceil(exp(-4 * Nombre_Nourriture / 200) * 1.1 * 100.0) / 100.0;
}

//dois converser un minimum de 100 villageois
float IA_Village::Calcul_Villageois() {
	std::cout << "Creer plus de villageois : " << ceil(exp(-4 * Nombre_Villageois / 150) * 100.0) / 100.0 << std::endl;
	return ceil(exp(-4 * Nombre_Villageois / 150) * 100.0) / 100.0;
}

//Plus de villageois sont présent, plus l'IA va en convertir en soldats
float IA_Village::Calcul_Soldier() {
	std::cout << "Creer plus de soldats : " << ceil(exp(-4 * ceil(exp(-4 * Nombre_Villageois / 200) * 100.0) / 100.0) * 100.0) / 100.0 << std::endl;
	return ceil(exp(-4 * Nombre_Soldat / 100) * 100.0) / 100.0;
}

//Si moins de 50 maisons vide et pas assez de villageois à convertir = forcer la construction de maison sinon rien
float IA_Village::Calcul_Maison() {
	if (Population > Nombre_Maison) {
		std::cout << "Creer plus de maisons : 1" << std::endl;
		return 1;
	}

	else {
		if (Nombre_Maison - Population < 50 and Nombre_Villageois < 100) {
			std::cout << "Creer plus de maisons : 1" << std::endl;
			return 1;
		}
		else {

			std::cout << "Creer plus de maisons : 0" << std::endl;
			return 0;
		}
	}
}

float IA_Village::Calcul_Attaque(IA_Village Ennemi) {
	float N_S = (float)Nombre_Soldat;
	float E_P = (float)Ennemi.Population;
	std::cout << "Lancer une attaque : " << N_S * 0.8 / E_P << std::endl;
	return N_S * 0.8 / E_P;
}

