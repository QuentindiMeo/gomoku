/*
** PERSONAL PROJECT, 2019
** gomoku
** File description:
** gomoku detectors
*/

#include "../include/gomoku.h"
#include "../include/my.h"

int check_played_xy(data *game)
{
    if (game->board[game->played_x][game->played_y] != EMP) {
        my_putstr("Error: this place is already taken\n");
        return (FAILURE);
    }
    return (SUCCESS);
}

int check_played_x(data *game)
{
    for (int i = 1; i < LENGTH_BOARD; i++)
        if (game->board[game->played_x][i] == EMP)
            return (SUCCESS);
    my_putstr("Error: this line is already full\n");
    return (FAILURE);
}

static int is_there_any_hole_left_line(char *line)
{
    for (int x = 0; x < LENGTH_BOARD; x++)
        if (line[x] == EMP)
            return (YES);
    return (NO);
}

int is_there_any_hole_left(data *game)
{
    for (int y = 0; y < HEIGHT_BOARD - 1; y++)
        if (is_there_any_hole_left_line(game->board[y]))
            return (YES);
    return (NO);
}

int switch_turn(int id)
{
    int save = id;

    if (save == PLAYER1)
        id = PLAYER2;
    if (save == PLAYER2)
        id = PLAYER1;
    return (id);
}
