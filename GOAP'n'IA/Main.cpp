#include "GameState.h"
#include "IA_GameState.h"

#define UPDATE_TIME 1

/// <summary>
/// Cree les actions
/// </summary>
void CreateAction()
{
    /*
    Action* reviser = new Action("Reviser");
    reviser ->AddEffect(Effet::GagnerDeLaForme);
    reviser ->AddEffect(Effet::GagnerDuGlucose);
    reviser ->AddPrecondition(Precondition(Precondition::PreconditionList::AvoirDormis, 5, ));
    std::cout << *reviser << std::endl;
    delete reviser;*/
}

/// <summary>
/// Execute au demarrage
/// </summary>
void Start(GameState& gameState)
{
    std::cout << "Start" << std::endl;
}

/// <summary>
/// Boucle gameplay
/// </summary>
void Update(GameState& gameState)
{
    std::cout << "Update" << std::endl;
    gameState.Run();
}


/// <summary>
/// Boucle principale, lance le start puis les update
/// </summary>
void Run(GameState& gameState)
{
    time_t t1, t2;
    Start(gameState);
    t1 = time(NULL);

    for (;;)        //probleme de boucle infinie
    {
        t2 = time(NULL);

        if (difftime(t2, t1) == UPDATE_TIME) // exemple pour 5 secondes
        {
            t1 = t2;
            Update(gameState);
            //std::cout << "execution de la tache" << std::endl;
        }
    }
}




int main(std::string args[]) {
    /*GameState gameState = GameState(5, 5, 5, 5, 5);
    Run(gameState);
	return 0;
    */

    IA_GameState Start;

}