/*
** PERSONAL PROJECT, 2019
** gomoku
** File description:
** gomoku detectors 3
*/

#include <stdlib.h>
#include "../include/gomoku.h"
#include "../include/my.h"

int someone_won_diagright_corners(char **gb, char p)
{
    if (gb[5][1] == p && gb[4][2] == p && gb[3][3] == p
        && gb[2][4] == p && gb[1][5] == p)
        return (TRUE);
    if (gb[19][15] == p && gb[18][16] == p && gb[17][17] == p
        && gb[16][18] == p && gb[15][19] == p)
        return (TRUE);
    return (FALSE);
}

int someone_won_diagleft_corners(char **gb, char p)
{
    if (gb[1][15] == p && gb[2][16] == p && gb[3][17] == p
        && gb[4][18] == p && gb[5][19] == p)
        return (TRUE);
    if (gb[15][1] == p && gb[16][2] == p && gb[17][3] == p
        && gb[18][4] == p && gb[19][5] == p)
        return (TRUE);
    return (FALSE);
}

void switch_name(data **game)
{
    char *temp = my_strdup((*game)->name1);

    free((*game)->name1);
    (*game)->name1 = my_strdup((*game)->name2);
    free((*game)->name2);
    (*game)->name2 = my_strdup(temp);
    free(temp);
}
