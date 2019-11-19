/*
** PERSONAL PROJECT, 2019
** gomoku
** File description:
** gomoku header
*/

#ifndef GOMOKU_H_
#define GOMOKU_H_

struct data {
    char **board;
    char p1;
    char p2;
    int played_x;
    int played_y;
    char *name1;
    char *name2;
};
typedef struct data data;

typedef enum {
    P1 = 'X',
    P2 = 'O',
    HEIGHT_BOARD = 19 + 2,
    LENGTH_BOARD = 19 + 2,
    EMP = '.',
} default_tictactoe_t;

typedef enum {
    DRAW = 0,
    PLAYER1 = 1,
    PLAYER2 = 2,
    W_DRAW = 0,
    W_PLAYER1 = 1,
    W_PLAYER2 = 2,
    END_OF_FILE2 = -2,
} return_values_tictactoe_t;

int help(void);

void err_invalid_choice(void);
int err_out_of_range(int id);
char *err_invalid_arg(void);

int check_played_xy(data *game);
int check_played_x(data *game);

int someone_won_diagright_corners(char **gb, char p);
int someone_won_diagleft_corners(char **gb, char p);

int is_win(data *game);
int is_there_any_hole_left(data *game);
void switch_name(data **game);
int switch_turn(int id);
int get_y(data **game);
int get_x(data **game);
int game_loop(data *game);
int swap2(data *game);

char *get_names(data **game);
int get_parameters(int ac, char **av, data *game);
void initial_print(data *game);
void setup(data **game);

int quit(char *to_be_freed);
data *freer(data *game);
data *mallocator(void);

#endif
