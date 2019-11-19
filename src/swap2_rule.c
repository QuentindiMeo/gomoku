/*
** PERSONAL PROJECT, 2019
** gomoku
** File description:
** gomoku swap2 rule
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/gomoku.h"
#include "../include/my.h"

static int p2_choice(data **game)
{
    char *entry = NULL;
    size_t buf = 0;
    int nb[3] = {1, 2, 3};

    my_putstr("\n");
    my_putstr((*game)->name2);
    my_putstr(", please choose '1', '2' or '3':\n 1) play with \033[1m");
    my_putchar((*game)->p1);
    my_putstr("\033[0ms\n 2) play with \033[1m");
    my_putchar((*game)->p2);
    my_putstr("\033[0ms and place one piece\n 3) place two pieces and let ");
    my_putstr((*game)->name1);
    my_putstr(" choose which piece they want to play with\n");
    while (1) {
        my_putstr("\nChoice: ");
        if (getline(&entry, &buf, stdin) == END_OF_FILE) {
            free(entry);
            return (END_OF_FILE);
        }
        if (my_int_isinarray(nb, my_atou(entry), 3)) {
            buf = my_atou(entry);
            free(entry);
            return (buf);
        }
        err_invalid_choice();
    }
}

static void play(data **game, uchar whose_turn, int i)
{
    if (i != 2)
        (*game)->board[(*game)->played_x][(*game)->played_y] =
            (whose_turn == PLAYER1 ? (*game)->p1 : (*game)->p2);
    else
        (*game)->board[(*game)->played_x][(*game)->played_y] =
            (whose_turn == PLAYER2 ? (*game)->p1 : (*game)->p2);
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

static int user_play(data *game, uchar whose_turn, int i)
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
    play(&game, whose_turn, i);
    return (SUCCESS);
}

static int choice3(data *game)
{
    char *entry = NULL;
    size_t buf = 0;
    int played = 0;

    for (uint i = 0; i < 2; i++) {
        my_putstr("\n");
        my_putstr(game->name2);
        my_putstr(", which player's piece do you want to place ? (1/2) ");
        while (!played) {
            if (getline(&entry, &buf, stdin) == END_OF_FILE)
                return (quit(entry));
            if (my_str_isequal(entry, "1\n") || my_str_isequal(entry, "2\n"))
                played = my_getnbr(entry);
        }
        if (user_play(game, PLAYER2, (played == 2 ? 1 : 2)) == END_OF_FILE)
            return (quit(entry));
        played = 0;
    }
    my_putstr("\n\n");
    my_putstr(game->name1);
    my_putstr(", which player's piece do you want to play with ? (1/2)\n");
    for (int playedd = 0; !playedd;) {
        if (getline(&entry, &buf, stdin) == END_OF_FILE)
            return (quit(entry));
        if (my_str_isequal(entry, "1\n") || my_str_isequal(entry, "2\n")) {
            if (my_getnbr(entry) == 2)
                switch_name(&game);
            playedd = 1;
        }
    }
    free(entry);
    return (SUCCESS);
}

int swap2(data *game)
{
    int ret_v;

    for (uint i = 0; i < 3; i++) {
        my_putstr("\n\nIt's ");
        my_putstr(game->name1);
        my_putstr("'s turn, placing a '");
        my_putchar(i != 2 ? game->p1 : game->p2);
        my_putstr("':\n");
        if (user_play(game, PLAYER1, i) == END_OF_FILE)
            return (END_OF_FILE);
    }
    ret_v = p2_choice(&game);
    if (ret_v == END_OF_FILE)
        return (END_OF_FILE);
    if (ret_v == 1)
        switch_name(&game);
    else if (ret_v == 2) {
        my_putstr("\nIt's ");
        my_putstr(game->name2);
        my_putstr("'s turn:\n");
        if (user_play(game, PLAYER2, 0) == END_OF_FILE)
            return (END_OF_FILE);
    } else
        if (choice3(game) == END_OF_FILE)
            return (END_OF_FILE);
    return (SUCCESS);
}
