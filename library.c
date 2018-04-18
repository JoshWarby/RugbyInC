#include <stdio.h>
# include "headers.h"

int clearscrean(){
    int clr;
    for (clr=0;clr<50;clr++){
        printf("\n");
    }
    return 0;
}

int printtitle(){
    printf("__________            ___.           .____                                        \n"
                   "\\______   \\__ __  ____\\_ |__ ___.__. |    |    ____ _____     ____  __ __   ____  \n"
                   " |       _/  |  \\/ ___\\| __ <   |  | |    |  _/ __ \\\\__  \\   / ___\\|  |  \\_/ __ \\ \n"
                   " |    |   \\  |  / /_/  > \\_\\ \\___  | |    |__\\  ___/ / __ \\_/ /_/  >  |  /\\  ___/ \n"
                   " |____|_  /____/\\___  /|___  / ____| |_______ \\___  >____  /\\___  /|____/  \\___  >\n"
                   "        \\/     /_____/     \\/\\/              \\/   \\/     \\//_____/             \\/ ");
    return 0;
}

int printteamlist(){
/* I didn't put a for loop here because I wrote it all out in a text document first so I could get the spacing the way
 * I wanted it, then the easiest thing to do was copy and paste */
    printf("\nTeam No | Team Name\n1         England\n2         Ireland\n3         Scotland\n4         Wales\n5         France\n6         Italy\n7         Germany\n8         Uraguay\n9         Belgium\n10        USA\n11        Mexico\n12        Australia\n13        Belize (1)\n14        Denmark\n15        Sweeden\n16        Belize (2)\n17        South Africa\n18        Algeria\n\n");
    return 0;
}
