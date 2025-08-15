#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct
{
    // Player Attributes
    int player_id;
    char name[51];
    float defense;
    float attack;
    float life;
    float accuracy;

    // team_id = (1 - Red Team / 2 - Blue Team)
}Player;


void Start_Teams(Player* team, int qtd_players, int team_id)
{
    printf("\033[1;33m===================================\033[m\n");

    if (team_id == 1)
    {
        printf("\033[1;31m             RED TEAM\033[m\n");
    }
    else if (team_id == 2)
    {
        printf("\033[1;36m             BLUE TEAM\033[m\n");
    }

    printf("\033[1;33m===================================\033[m\n\n");

    for (int i = 0; i < qtd_players; i++)
    {
        printf("\033[1;33m===================================\033[m\n");
        
        team[i].player_id = i; // ID

        printf("Enter Player Name: ");
        fgets(team[i].name, sizeof(team[i].name), stdin); // Player Name
        team[i].name[strcspn(team[i].name, "\n")] = '\0';

        team[i].defense = rand()%11 + 1;

        team[i].attack = rand()%11 + 1;

        team[i].life = 100;

        team[i].accuracy = 0;
    }

    printf("\033[1;33m===================================\033[m\n");
}


int Set_Teams(int* time_team)
{
    int random_num = rand()%2 + 1;
    *time_team  = random_num;
    return *time_team; 
}


void Game_Scene(Player* attacking_team, Player* defensing_team, int qtd_players, int attack_team_id)
{
    for (int i = 0; i < qtd_players; i++)
    {
        printf("\033[1;33m===================================\033[m\n");
        
        if (attack_team_id == 1)
        {
            printf("TEAM: \033[1;31mRED\033[m\n");
        }
        else if (attack_team_id == 2)
        {
            printf("TEAM: \033[1;36mBLUE\033[m\n");
        }

        printf("WAR NAME: %s\n", attacking_team[i].name);

        printf("DEFENSE: %.2f\n", attacking_team[i].defense);

        printf("ATTACK: %.2f\n", attacking_team[i].attack);
        
        printf("LIFE: %.2f\n", attacking_team[i].life);

        printf("\033[1;33m===================================\033[m\n\n");

        for (int c = 0; c < qtd_players; c++)
        {
            printf("\033[1;33m===================================\033[m\n");

            if (attack_team_id == 1)
            {
                printf("TEAM: \033[1;36mBLUE\033[m\n");
            }
            else if (attack_team_id == 2)
            {
                printf("TEAM: \033[1;31mRED\033[m\n");
            }

            printf("WAR NAME: %s\n", defensing_team[c].name);

            printf("LIFE: %.2f\n", attacking_team[c].life);
         
            printf("\033[1;33m===================================\033[m\n");
        }
    }

}


int main()
{
    srand(time(NULL));

    // Variables
    int qtd_players = 4;
    int time_team = 0; // time_team = (1 - Red Team / 2 - Blue Team)

    // Vectors
    Player red_team[qtd_players];
    Player blue_team[qtd_players];

    Start_Teams(red_team, qtd_players, 1);
    system("clear");
    Start_Teams(blue_team, qtd_players, 2);
    system("clear");

    time_team = Set_Teams(&time_team);

    if (time_team == 1)
    {
        Game_Scene(red_team, blue_team, qtd_players, 1);
    }
    else if (time_team == 2)
    {
        Game_Scene(blue_team, red_team, qtd_players, 2);
    }
}
