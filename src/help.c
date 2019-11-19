/*
** PERSONAL PROJECT, 2019
** gomoku
** File description:
** gomoku help
*/

#include "../include/gomoku.h"
#include "../include/my.h"

static void help2(void)
{
    my_putstr("\n\n   \033[1mOptions:\033[0m\n\t\033[1m-1\033[0m \033[4mPI"
    "ECE\033[0m, \033[1m--p1\033[0m=\033[4mPIECE\033[0m\n\t\033[1m-2\033[0m "
    "\033[4mPIECE\033[0m, \033[1m--p2\033[0m=\033[4mPIECE\033[0m\n\t\tChange t"
    "he players' pieces. \033[4mPIECE\033[0m  has  to  be  a  printable\n\t\tc"
    "haracter and it can't be a space (' ') or a dot ('.').\n\n\t\033[1m--name"
    "s\033[0m\n\t\tMake the program ask for two names to use as player names."
    "\n\n\t\033[1m-h\033[0m, \033[1m--help\033[0m\n\t\tDisplay this help.\n\n "
    "  \033[1mExit status:\033[0m\n\t0\tif the game ended with a draw or the g"
    "ame was quit (CTRL+D),\n\t1\tif the game ended and Player 1 won,\n\t2\tif"
    " the game ended and Player 2 won,\n\t84\tif the program ended with an err"
    "or.\n\n \033[1mAUTHOR\033[0m\n\tWritten by Quentin di Meo.\n\n \033[1mREP"
    "ORTING BUGS\033[0m\n\tReport any bug or functioning error to <quentin.di-"
    "meo@epitech.eu>\n\n");
}

int help(void)
{
    my_putstr("\n\tWelcome to Gomoku\n\n \033[1mUSAGE\033[0m\n\t./gomoku "
    "[\033[4mOPTION\033[0m]\n\n \033[1mDESCRIPTION\033[0m\n\tThis game is made"
    " of a 19x19 grid, and you play against one another.\n\tThe goal is to mak"
    "e a line of five  while getting your opponent away\n\tfrom doing it thems"
    "elf.   This is Standard Gomoku, which means lines\n\tthat are made of mor"
    "e than five pieces (overlines) do not count as a\n\twin. The game begins "
    "with the Swap2 rule, defined below. By default,\n\tPlayer 1's pieces will"
    " be \033[1mX\033[0ms, and Player 2's pieces will be \033[1mO\033[0ms.\n\n"
    "   \033[1mSwap2 rule:\033[0m\n\tThe game starts with Player 1 placing two"
    " of their pieces and one of\n\tPlayer 2's pieces. Then, Player 2 chooses "
    "either to play with Player\n\t1's pieces, to keep his piece and place one"
    ",  or to place two pieces\n\t(both  can  be  any  piece) and let Player 1"
    " choose which piece they\n\tplay with. The game then continues in a turn-"
    "based manner.");
    help2();
    return (SUCCESS);
}
