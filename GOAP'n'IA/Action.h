#pragma once

#include <vector>
#include "Precondition.h"
#include "Effet.h"


class Action
{
private:
	/// <summary>
	/// Nom de l action
	/// </summary>
	std::string Name;

	/// <summary>
	/// Effets de l action
	/// </summary>
	std::vector<Effet> Effets;

	/// <summary>
	/// Preconditions de l action
	/// </summary>
	std::vector<Precondition> Preconditions;

	/// <summary>
	/// Actions predecesseurs
	/// </summary>
	std::vector<Action*> PreviousActions;

	int Cout;
public:

	/// <summary>
	/// Constructeur de l action
	/// </summary>
	/// <param name="_name">nom de l action</param>
	/// <param name="_cout">cout de l action</param>
	Action(const std::string& _name, const int& _cout = 1);

	/// <summary>
	/// Ajoute une precondition a l action
	/// </summary>
	/// <param name="_precondition">la precondition a ajouter</param>
	void AddPrecondition(const Precondition _precondition);

	/// <summary>
	/// Ajoute un effet a cette action
	/// </summary>
	/// <param name="_effet">l effet a ajouter</param>
	void AddEffect(const Effet _effet);

	/// <summary>
	/// Ajoute une action en tant qu action predecesseure
	/// </summary>
	/// <param name="_action">l action predecesseure</param>
	void AddPreviousAction(const Action& _action);

	/// <summary>
	/// Effets a effectuer en cas d action validee
	/// </summary>
	void OnActionValid();

	/// <summary>
	/// Operateur ostream pour lire les donnes de l action
	/// </summary>
	/// <param name="os">le stream de sortie</param>
	/// <param name="action">l action a lire</param>
	/// <returns>le stream avec les donnes de l action ajoutes</returns>
	friend std::ostream& operator<<(std::ostream& os, const Action& action);

	/// <summary>
	/// Renvoie la liste des preconditions
	/// </summary>
	/// <returns></returns>
	std::vector<Precondition> GetPreconditions() const {
		return Preconditions;
	}

	/// <summary>
	/// renvoie le nom de l action 
	/// </summary>
	/// <returns>action name</returns>
	std::string GetName() const {
		return Name;
	}

	/// <summary>
	/// renvoie le cout de l action
	/// </summary>
	/// <returns>action cout</returns>
	int GetCout() const
	{
		return Cout;
	}

	/// <summary>
	/// Calcule le cout pour executer une action
	/// </summary>
	/// <param name="_Couts">liste des couts totaux de chaque serie d action</param>
	/// <param name="_Actions">liste des actions a effectuer pour exectuer la premiere</param>
	/// <param name="localCouts">copie locale du cout au moment de l appel</param>
	/// <param name="localActions">copie local de l action au moment de l appel</param>
	/// <param name="_CombinaisonIndex">index de la combinaison pour savoir sur quelle serie d action on est</param>
	void CalculateCost(
		std::vector<int>* _Couts,
		std::vector<std::vector<Action>>* _Actions,
		std::vector<int> localCouts,
		std::vector<std::vector<Action>> localActions,
		const size_t& _CombinaisonIndex) const;
};

