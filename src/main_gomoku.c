/*
** PERSONAL PROJECT, 2019
** gomoku
** File description:
** main gomoku
*/

#include <stdlib.h>
#include "../include/gomoku.h"
#include "../include/my.h"

static int print_winner(int id, data *game)
{
    if (!id)
        return (my_putstr("\nIt's a draw!!\n") ? W_DRAW : W_DRAW);
    if (id == PLAYER1) {
        my_putchar('\n');
        my_putstr(game->name1);
        my_putstr(" wins!!\n");
        return (W_PLAYER1);
    }
    if (id == PLAYER2) {
        my_putchar('\n');
        my_putstr(game->name2);
        my_putstr(" wins!!\n");
        return (W_PLAYER2);
    }
    if (id == END_OF_FILE || id == END_OF_FILE2) {
        my_putstr("\nYou quit the game.\n");
        return (id == END_OF_FILE ? SUCCESS : END_OF_FILE);
    }
    return (FAILURE);
}

static int main_gomoku(int ac, char **av, data *game)
{
    int ret_v;
    int winner;

    setup(&game);
    ret_v = get_parameters(ac, av, game);
    if (ret_v == FAILURE || ret_v == END_OF_FILE2)
        return (ret_v);
    if (ret_v == END_OF_FILE)
        return ((freer(game)) ? END_OF_FILE : END_OF_FILE);
    initial_print(game);
    if (swap2(game) == END_OF_FILE)
        return (END_OF_FILE);
    winner = game_loop(game);
    if (winner == END_OF_FILE || winner == DRAW)
        return ((winner == END_OF_FILE) ? END_OF_FILE : W_DRAW);
    return (winner == PLAYER1 ? W_PLAYER1 : W_PLAYER2);
}

int main(int ac, char **av)
{
    int ret_v;
    data *game = NULL;

    if (ac == 2 &&
        (my_str_isequal(av[1], "-h") || my_str_isequal(av[1], "--help")))
        return (help());
    game = mallocator();
    ret_v = main_gomoku(ac, av, game);
    ret_v = print_winner(ret_v, game);
    if (ret_v != END_OF_FILE)
        freer(game);
    return ((ret_v == END_OF_FILE) ? SUCCESS : ret_v);
}
