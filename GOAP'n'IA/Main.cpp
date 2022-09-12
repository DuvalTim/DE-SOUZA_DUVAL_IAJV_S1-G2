#include "Action.h"
#include <iostream>

#define UPDATE_TIME 5

/// <summary>
/// Boucle principale, lance le start puis les update
/// </summary>
void Run()
{
    time_t t1, t2;
    Start();
    t1 = time(NULL);

    for (;;)        //probleme de boucle infinie
    {
        t2 = time(NULL);

        if (difftime(t2, t1) == UPDATE_TIME) // exemple pour 5 secondes
        {
            t1 = t2;
            Update();
            //std::cout << "execution de la tache" << std::endl;
        }
    }
}


/// <summary>
/// Cree les actions
/// </summary>
void CreateAction()
{
    Action* couperDuBois = new Action("Couper du bois");
    couperDuBois->AddEffect(Effets::GagnerDuBois);
    couperDuBois->AddPrecondition(Preconditions::AvoirUneHache);
    couperDuBois->ShowAction();
    delete couperDuBois;
}

/// <summary>
/// Execute au demarrage
/// </summary>
void Start() 
{
    CreateAction();
}

/// <summary>
/// Boucle gameplay
/// </summary>
void Update() 
{
    
}


int main(std::string args[]) {
    Run();
	std::cout << "ok" << std::endl;
	return 0;
}