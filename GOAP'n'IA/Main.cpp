#include "GameState.h"

#define UPDATE_TIME 3

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

void OnApplicationLeave(GameState& gameState)
{
    std::cout << "End" << std::endl;
    ~gameState;
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
    OnApplicationLeave(gameState);
}

int main(std::string args[]) {
    GameState gameState = GameState(5, 5, 5, 5, 5);
    Run(gameState);
	return 0;
}