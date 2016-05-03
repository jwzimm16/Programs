#include <iostream>
#include <stdlib.h>

using namespace std;

void DrawSeparator( int length )
{
    for (int a = length; a > 0; a--)
    {
        cout << "-";
    }
}

void DisplayMenu (int round, int playerHP, int enemyHP)
{
    DrawSeparator(30);
    cout << endl << "ROUND " << round << endl;
    cout << "Your HP: " << playerHP << "\tEnemy HP: " << enemyHP << endl << endl;
    cout << "1. Attack" << endl;
    cout << "2. Heal" << endl << endl;
}

int GetChoice (int minimum, int maximum)
{
    bool done = false;
    int choice;

    while (!done)
    {
        cout << "What do you do?" << endl;
        cout << ">> ";
        cin >> choice;
        cout << endl;
        if (choice < minimum || choice > maximum)
        {
            cout << "Invalid choice, try again." << endl << endl;
        }
        else
        {
            done = true;
        }
    }

    return choice;
}

int GetAttack ()
{
    int random = rand() % 10;
    return random;
}

int GetHealing ()
{
    int random = rand() % 7;
    return random;
}

int main()
{
    int playerHP = 100;
    int enemyHP = 100;
    int round = 1;

    while (playerHP > 0 && enemyHP > 0)
    {
        DisplayMenu(round, playerHP, enemyHP);
        int choice;
        choice = GetChoice(1, 2);
        if (choice == 1)
        {
            int damage = GetAttack();
            cout << "You attack your ENEMY for " << damage << " damage!" << endl;
            enemyHP = enemyHP - damage;
        }
        else
        {
            int heal = GetHealing();
            cout << "You heal for " << heal << " points!" << endl;
            playerHP = playerHP + heal;
        }

        int enemyChoice = rand() % 2;
        if (enemyChoice == 0)
        {
            int heal = GetHealing();
            cout << "ENEMY heals THEMSELF for " << heal << " points!" << endl;
            enemyHP = enemyHP + heal;
        }
        else
        {
            int damage = GetAttack();
            cout << "ENEMY attacks you for " << damage << " damage!" << endl;
            playerHP = playerHP - damage;
        }

        round++;
    }

    if (enemyHP > 0)
    {
        cout << endl << "You lose!";
    }
    else
    {
        cout << endl << "You win!";
    }

    return 0;
}
