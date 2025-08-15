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


int main()
{
    srand(time(NULL));

    // Variables
    int qtd_players = 4;

    // Vectors
    Player red_team[qtd_players];
    Player blue_team[qtd_players];

    Start_Teams(red_team, qtd_players, 2);

}
