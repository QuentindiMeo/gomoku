/*
** PERSONAL PROJECT, 2019
** gomoku
** File description:
** gomoku detectors 2
*/

#include "../include/gomoku.h"
#include "../include/my.h"

static int someone_won_diagright(char **gb, char p)
{
    for (int y = 6; y <= 19; y++)
        if (gb[1][y] == p && gb[2][y - 1] == p && gb[3][y - 2] == p &&
            gb[4][y - 3] == p && gb[5][y - 4] == p && gb[6][y - 5] != p)
            return (TRUE);
    for (int y = 5; y <= 18; y++)
        if (gb[15][y] == p && gb[16][y - 1] == p && gb[17][y - 2] == p &&
            gb[18][y - 3] == p && gb[19][y - 4] == p && gb[14][y + 1] != p)
            return (TRUE);
    for (int y = 6; y <= 18; y++)
        for (int x = 2; x <= 14; x++)
            if (gb[x][y] == p && gb[x + 4][y - 4] == p && gb[x + 1][y - 1] == p
                && gb[x + 2][y - 2] == p && gb[x + 3][y - 3] == p &&
                !(gb[x + 5][y - 5] == p || gb[x - 1][y + 1] == p))
                return (TRUE);
    for (int x = 2; x <= 15; x++)
        if (gb[x][5] == p && gb[x + 1][4] == p && gb[x + 2][3] == p &&
            gb[x + 3][2] == p && gb[x + 4][1] == p && gb[x - 1][6] != p)
            return (TRUE);
    for (int x = 1; x <= 14; x++)
        if (gb[x][19] == p && gb[x + 1][18] == p && gb[x + 2][17] == p &&
            gb[x + 3][16] == p && gb[x + 4][15] == p && gb[x - 1][14] != p)
            return (TRUE);
    if (someone_won_diagright_corners(gb, p))
        return (TRUE);
    return (FALSE);
}

static int someone_won_diagleft(char **gb, char p)
{
    for (int x = 1; x <= 14; x++)
        if (gb[x][1] == p && gb[x + 1][2] == p && gb[x + 2][3] == p &&
            gb[x + 3][4] == p && gb[x + 4][5] == p && gb[x + 5][6] != p)
            return (TRUE);
    for (int x = 2; x <= 15; x++)
        if (gb[x][15] == p && gb[x + 1][16] == p && gb[x + 2][17] == p &&
            gb[x + 3][18] == p && gb[x + 4][19] == p && gb[x - 1][14] != p)
            return (TRUE);
    for (int y = 2; y <= 14; y++)
        for (int x = 2; x <= 14; x++)
            if (gb[x][y] == p && gb[x + 4][y + 4] == p && gb[x + 1][y + 1] == p
                && gb[x + 2][y + 2] == p && gb[x + 3][y + 3] == p &&
                !(gb[x + 5][y + 5] == p || gb[x - 1][y - 1] == p))
                return (TRUE);
    for (int y = 1; y <= 14; y++)
        if (gb[1][y] == p && gb[2][y + 1] == p && gb[3][y + 2] == p &&
            gb[4][y + 3] == p && gb[5][y + 4] == p && gb[6][y + 5] != p)
            return (TRUE);
    for (int y = 2; y <= 15; y++)
        if (gb[15][y] == p && gb[16][y + 1] == p && gb[17][y + 2] == p &&
            gb[18][y + 3] == p && gb[19][y + 4] == p && gb[14][y - 1] != p)
            return (TRUE);
    if (someone_won_diagleft_corners(gb, p))
        return (TRUE);
    return (FALSE);
}

static int someone_won_col(char **gb, char p)
{
    for (int y = 1; y < LENGTH_BOARD - 1; y++)
        if (gb[1][y] == p && gb[2][y] == p && gb[3][y] == p &&
            gb[4][y] == p && gb[5][y] == p && gb[6][y] != p)
            return (TRUE);
    for (int y = 1; y < LENGTH_BOARD - 1; y++)
        for (int x = 2; x <= 14; x++)
            if (gb[x][y] == p && gb[x + 1][y] == p && gb[x + 4][y] == p &&
                gb[x + 2][y] == p && gb[x + 3][y] == p &&
                !(gb[x - 1][y] == p || gb[x + 5][y] == p))
                return (TRUE);
    for (int y = 1; y < LENGTH_BOARD - 1; y++)
        if (gb[15][y] == p && gb[16][y] == p && gb[17][y] == p &&
            gb[18][y] == p && gb[19][y] == p && gb[14][y] != p)
            return (TRUE);
    return (FALSE);
}

static int someone_won_row(char **gb, char p)
{
    for (int x = 1; x < HEIGHT_BOARD - 1; x++)
        if (gb[x][1] == p && gb[x][2] == p && gb[x][3] == p &&
            gb[x][4] == p && gb[x][5] == p && gb[x][6] != p)
            return (TRUE);
    for (int x = 1; x < HEIGHT_BOARD - 1; x++)
        for (int y = 2; y <= 14; y++)
            if (gb[x][y] == p && gb[x][y + 1] == p && gb[x][y + 4] == p &&
                gb[x][y + 2] == p && gb[x][y + 3] == p &&
                !(gb[x][y - 1] == p || gb[x][y + 5] == p))
                return (TRUE);
    for (int x = 1; x < HEIGHT_BOARD - 1; x++)
        if (gb[x][15] == p && gb[x][16] == p && gb[x][17] == p &&
            gb[x][18] == p && gb[x][19] == p && gb[x][14] != p)
            return (TRUE);
    return (FALSE);
}

int is_win(data *game)
{
    if (someone_won_row(game->board,game->p1) ||
        someone_won_col(game->board,game->p1) ||
        someone_won_diagleft(game->board,game->p1) ||
        someone_won_diagright(game->board,game->p1) ||
        someone_won_row(game->board,game->p2) ||
        someone_won_col(game->board,game->p2) ||
        someone_won_diagleft(game->board,game->p2) ||
        someone_won_diagright(game->board,game->p2))
        return (TRUE);
    return (FALSE);
}
