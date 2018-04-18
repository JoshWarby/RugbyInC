#include <stdio.h>
#include <string.h>
#include "headers.h"

struct team {
    int leaguescore;
    char name[15];
};

int main(){
    int teamA;
    int teamAscore;
    int teamB;
    int teamBscore;
    int arraylen;
    arraylen = 19;
    clearscrean();
    printf("\n\nWelcome to the 18 Nations league tracker, open the console larger to enjoyt he ascii art.\n");
/* Initiating Teams - No, it isn't pretty, yes I could have used a for loop,
 * however I needed to type out all the names anyway so this didn't take much longer and it
 * helped me visualise what I was creating*/
    struct team teamlist[arraylen];
/*This first team within [0] is used as a temporary struct when swapping teams within the bubble sort,
 * It, rather helpfully, also increments all the teams by one allowing for the first team, England, to
 * be in position 1 rather than 0*/
    strcpy(teamlist[0].name,"TempHolder");
    teamlist[0].leaguescore=0;
    strcpy(teamlist[1].name,"England");
    teamlist[1].leaguescore=0;
    strcpy(teamlist[2].name,"Ireland");
    teamlist[2].leaguescore=0;
    strcpy(teamlist[3].name,"Scotland");
    teamlist[3].leaguescore=0;
    strcpy(teamlist[4].name,"Wales");
    teamlist[4].leaguescore=0;
    strcpy(teamlist[5].name,"France");
    teamlist[5].leaguescore=0;
    strcpy(teamlist[6].name,"Italy");
    teamlist[6].leaguescore=0;
    strcpy(teamlist[7].name,"Germany");
    teamlist[7].leaguescore=0;
    strcpy(teamlist[8].name,"Uraguay");
    teamlist[8].leaguescore=0;
    strcpy(teamlist[9].name,"Belgium");
    teamlist[9].leaguescore=0;
    strcpy(teamlist[10].name,"U S A");
    teamlist[10].leaguescore=0;
    strcpy(teamlist[11].name,"Mexico");
    teamlist[11].leaguescore=0;
    strcpy(teamlist[12].name,"Australia");
    teamlist[12].leaguescore=0;
    strcpy(teamlist[13].name,"Belize (1)");
    teamlist[13].leaguescore=0;
    strcpy(teamlist[14].name,"Denmark");
    teamlist[14].leaguescore=0;
    strcpy(teamlist[15].name,"Sweden");
    teamlist[15].leaguescore=0;
    strcpy(teamlist[16].name,"Belize (2)");
    teamlist[16].leaguescore=0;
    strcpy(teamlist[17].name,"South Africa");
    teamlist[17].leaguescore=0;
    strcpy(teamlist[18].name,"Algeria");
    teamlist[18].leaguescore=0;

/* Used later to sort without changing the order of the initial array of teams */
    struct team teamlistcopy[arraylen];
    int option;
    int i;
    int j;
    int game;

/* 153 is the total amount of unique games. */
    for (game=1;game<=153-1;game++) {
        printtitle();
        printf("\n\nMain Menu\nPress 0 to continue adding matches.\nPress 1 to show current league table.\nPress 2 to modify existing table.\nEnter here: ");
        scanf(" %i", &option);

/* Allows the user to loop through a menu until they are ready to add a new match */
        while (option != 0){
            switch (option) {
                case 1:
                    memcpy(&teamlistcopy, &teamlist, sizeof(teamlist));
                    for (i = 1; i < arraylen; i++) {
                        for (j = 1; j < arraylen - 1; j++) {
                            if (teamlistcopy[j].leaguescore > teamlistcopy[j + 1].leaguescore) {
                                teamlistcopy[0] = teamlistcopy[j];
                                teamlistcopy[j] = teamlistcopy[j + 1];
                                teamlistcopy[j + 1] = teamlistcopy[0];
                            }
                        }
                    }
                    printf("\n");

                    clearscrean();
                    printtitle();
                    printf("\n\n");
                    printf("Team Name          League Score\n");
                    printf("------------------------------------\n");
                    for (i = arraylen-1; i > 0; i--) {
                        printf("%s           \t%i \n", teamlistcopy[i].name, teamlistcopy[i].leaguescore);
                    }

                    printf("\nMain Menu\nPress 0 to continue adding matches.\nPress 1 to show current league table.\nPress 2 to modify existing table.\nEnter here: ");
                    scanf(" %i", &option);
                    break;

                case 2:

                    clearscrean();
                    printteamlist();
                    printf("Team to modify: ");
                    scanf(" %i",&teamA);
                    printf("Change score by (e.g. 4 or -4): ");
                    scanf(" %i",&teamAscore);
                    teamlist[teamA].leaguescore+=teamAscore;
                    clearscrean();
                    printtitle();

                    printf("\n\nMain Menu\nPress 0 to continue adding matches.\nPress 1 to show current league table.\nPress 2 to modify existing table.\nEnter here: ");
                    scanf(" %i", &option);

                    break;
            }
        }
/* User is asked to enter the teams that have played along with their scores
 * Full team names are then referred to for the rest of the printf's rather than "Team A" or B*/
        clearscrean();
        printteamlist();
        printf("Game %i of %i\n",game,(18*11));
        printf("Team A (number from above) #: ");
        scanf(" %i", &teamA);
        printf("Team B (number from above) #: ");
        scanf(" %i", &teamB);
        printf("Team %s Score : ", teamlist[teamA].name);
        scanf(" %i", &teamAscore);
        printf("Team %s Score : ", teamlist[teamB].name);
        scanf(" %i", &teamBscore);

        char tries;
        tries = 'n';
/* Checks to see if teams meet the requirements for a bonus point and increases League score appropriately*/
        if (teamAscore > teamBscore) {

            teamlist[teamA].leaguescore += 4;
            printf("Did %s score 4 or more tries? y/n : ", teamlist[teamA].name);
            scanf(" %c", &tries);
            if (tries == 'y') {
                teamlist[teamA].leaguescore += 1;
            }
            tries = 'n';
            printf("Did %s score 4 or more tries? y/n : ", teamlist[teamB].name);
            scanf(" %c", &tries);
            if (tries == 'y') {
                teamlist[teamB].leaguescore += 1;
            }
            if (teamAscore-teamBscore<=7) {
                printf("Lost within a margin of 7 - Bonus point added.");
                teamlist[teamB].leaguescore += 1;
            }

        } else if (teamBscore > teamAscore) {
            teamlist[teamB].leaguescore += 4;
            printf("Did %s score 4 or more tries? y/n : ", teamlist[teamA].name);
            scanf(" %c", &tries);
            if (tries == 'y') {
                teamlist[teamA].leaguescore += 1;
            }
            if (teamBscore-teamAscore<=7) {
                printf("Lost within a margin of 7 - Bonus point added.\n");
                teamlist[teamA].leaguescore += 1;
            }
            tries = 'n';
            printf("Did %s score 4 or more tries? y/n : ", teamlist[teamB].name);
            scanf(" %c", &tries);
            if (tries == 'y') {
                teamlist[teamB].leaguescore += 1;
            }
        } else {
            teamlist[teamA].leaguescore += 2;
            teamlist[teamB].leaguescore += 2;

            printf("Did %s score 4 or more tries? y/n : ", teamlist[teamA].name);
            scanf(" %c", &tries);
            if (tries == 'y') {
                teamlist[teamA].leaguescore += 1;
            }
            tries = 'n';
            printf("Did team %s score 4 or more tries? y/n : ", teamlist[teamB].name);
            scanf(" %c", &tries);
            if (tries == 'y') {
                teamlist[teamB].leaguescore += 1;
            }
        }

/*Allows for time before the next iteration to stop the screen filling before the user can read it all.*/
        printf("\nPress any key to continue");
        getchar();
        getchar();
        clearscrean();

/*  V - HERE MARKS END OF (Huge) game LOOP*/
    }
/*After all matches have been inputted the screen is cleared and the final table is displayed.*/
    clearscrean();
    printf("Team Name          League Score\n");
    printf("------------------------------------\n");
    for (i = arraylen-1; i > 0; i--) {
        printf("%s           \t%i \n", teamlistcopy[i].name, teamlistcopy[i].leaguescore);
    }
    printf("\nPress any key to quit.");
    getchar();
    getchar();
    return 0;
}
