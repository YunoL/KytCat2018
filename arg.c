/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** main file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <getopt.h>
#include <signal.h>

int my_printf(char *s, ...);

typedef struct param_s{
    char key_left;
    char key_right;
    char key_turn;
    char key_drop;
    char key_quit;
    char key_pause;
    int map_size[2];
    int hide;
    int debug;
    int level;
    int help;
} param_t;

param_t initialyse(void)
{
    param_t this;
    this.key_left = 'D';
    this.key_right = 'C';
    this.key_turn = 'A';
    this.key_drop = 'B';
    this.key_quit = 'q';
    this.key_pause = ' ';
    this.map_size[0] = 20;
    this.map_size[1] = 10;
    this.hide = 0;
    this.debug = 0;
    this.level = 0;
    this.help = 0;
    return (this);
}

int check_flag(int ac, char **av)
{
    static struct option longopts[] = {
        { "without-next", no_argument, NULL, 'w' },
        { "level", required_argument, NULL, 'L' },
        { "key-left", required_argument, NULL, 'l'},
        { "key-right", required_argument, NULL, 'r'},
        { "key-turn", required_argument, NULL, 't'},
        { "key-drop", required_argument, NULL, 'd'},
        { "key-quit", required_argument, NULL, 'q'},
        { "key-pause", required_argument, NULL, 'p'},
        { "map-size", no_argument, NULL, 1},
        { "debug", no_argument, NULL, 'D'},
        { "help", no_argument, NULL, 'h'},
        { NULL, 0, NULL, 0}
    };
    return (getopt_long(ac, av, "L:l:r:t:d:q:p:wDh", longopts, NULL));
}

void print_help(char *exec_name)
{
    my_printf("Usage:  %s [optional]\n", exec_name);
    my_printf("Option:\n");
    my_printf("--help               Display this help\n\
    -L --level={num}     Start Tetris at level num (def: 1)\n\
    -l --key-left={K}    Move the tetrimino LEFT \
    using the K key (def: left arrow)\n\
    -r --key-right={K}   Move the tetrimino RIGHT using the \
    K key (def: right arrow)\n\
    -t --key-turn={K}    TURN the tetrimino clockwise 90d using t\
    he K key (def: top arrow)\n\
    -d --key-drop={K}    DROP the tetrimino us\
    ing the K key (def: down arrow)\n\
    -q --key-quit={K}    QUIT the game using the K key (def: ‘q’ key)\n\
    -p --key-pause={K}   PAUSE/RESTART the game u\
    sing the K key (def: space bar)\n\
    --map-size={row,col} Set the numbers of rows and col\
    umns of the map (def: 20,10)\n\
    -w --without-next    Hide next tetrimino (def: false)\n\
    -D --debug           Debug mode (def: false)");
}

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i]; i++);
    return (i);
}

void check_opt(void)
{
    if (my_strlen(optarg) != 1 || *optarg == 0)
        exit(84);
}
