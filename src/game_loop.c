/*
** PERSONAL PROJECT, 2019
** gomoku
** File description:
** gomoku game loop
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/gomoku.h"
#include "../include/my.h"

static void play(data **game, uchar whose_turn)
{
    (*game)->board[(*game)->played_x][(*game)->played_y] =
        (whose_turn == PLAYER1 ? (*game)->p1 : (*game)->p2);
    my_putstr(whose_turn == PLAYER1 ? (*game)->name1 : (*game)->name2);
    my_putstr(" placed a piece on ");
    my_putnbr((*game)->played_x);
    my_putchar(',');
    my_putnbr((*game)->played_y);
    my_putchar('\n');
    my_putstr(" 1234567890123456789 \n");
    for (uint i = 0; i < HEIGHT_BOARD; i++) {
        my_putstr((*game)->board[i]);
        if (i && i < 20)
            my_putnbr(i % 10);
        my_putchar('\n');
    }
}

int get_y(data **game)
{
    char *entry = NULL;
    size_t buff = 0;
    int nb[19] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                    12, 13, 14, 15, 16, 17, 18, 19};

    (*game)->played_y = (my_putstr("Column: ")) ? 0 : 0;
    while (!(*game)->played_y) {
        if (getline(&entry, &buff, stdin) == ERROR)
            return (quit(entry));
        (*game)->played_y = my_getnbr(entry);
        if (!my_int_isinarray(nb, (*game)->played_y, 19)) {
            err_out_of_range(1);
            get_x(game);
            get_y(game);
            break;
        }
    }
    free(entry);
    return (SUCCESS);
}

int get_x(data **game)
{
    char *entry = NULL;
    size_t buff = 0;
    int ret_v;
    int nb[19] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                  12, 13, 14, 15, 16, 17, 18, 19};

    (*game)->played_x = 0;
    my_putstr("Line: ");
    while (!(*game)->played_x) {
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (quit(entry));
        (*game)->played_x = my_getnbr(entry);
        if (!my_int_isinarray(nb, (*game)->played_x, 19))
            (*game)->played_x = (err_out_of_range(0)) ? 0 : 0;
    }
    free(entry);
    return (SUCCESS);
}

static int user_play(data *game, uchar whose_turn)
{
    int ret_v;

    do {
        ret_v = get_x(&game);
    } while (ret_v != END_OF_FILE && check_played_x(game) == FAILURE);
    if (ret_v == END_OF_FILE)
        return (END_OF_FILE);
    do {
        ret_v = get_y(&game);
        while (ret_v != END_OF_FILE && check_played_xy(game) == FAILURE) {
            do {
                ret_v = get_x(&game);
            } while (ret_v != END_OF_FILE && check_played_x(game) == FAILURE);
            ret_v = get_y(&game);
        }
    } while (ret_v != END_OF_FILE && check_played_xy(game) == FAILURE);
    if (ret_v == END_OF_FILE)
        return (END_OF_FILE);
    play(&game, whose_turn);
    return (SUCCESS);
}

int game_loop(data *game)
{
    uchar whose_turn = PLAYER2;
    int loop = 1;

    for (uchar over = FALSE; over != TRUE;) {
        whose_turn = switch_turn(whose_turn);
        my_putstr(loop != 1 ? "\n\nIt's " : "\nIt's ");
        my_putstr(whose_turn == PLAYER1 ? game->name1 : game->name2);
        my_putstr("'s turn:\n");
        if (user_play(game, whose_turn) == END_OF_FILE)
            return (END_OF_FILE);
        if (!(is_there_any_hole_left(game) == YES && !is_win(game)))
            over = TRUE;
        loop++;
    }
    if (!is_win(game))
        whose_turn = DRAW;
    return (whose_turn);
}
