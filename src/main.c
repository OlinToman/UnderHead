#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <ctype.h>
#include <signal.h>
#include "functions.h"

typedef struct handle 
{
    node_t * head;
    unsigned int * point;
    item_t * item;
    unsigned int * lvl;
} handle_t;
node_t * head_;
handle_t _sig;
void HandleSIGINT(int sig)
{
    Safe(_sig.head, _sig.point, _sig.item, _sig.lvl);
    endwin();
    clear();
    DeleteLinkedList(head_);
    exit(0);
} 

int main(int argc, char *argv[])
{
    // priprava ncurses
    initscr();
    noecho();
    cbreak();
    start_color();
    curs_set(0);

    // alokace pameti pro postavu hrace
    node_t *head = malloc(sizeof(node_t));
    head_ = head;
    head->next = head;
    head->back = head;

    // pridani zakladnich statu
    head->name[0] = 0;
    head->health = 10;
    head->maxhealth = 10;
    head->attack = 1;
    head->defense = 1;
    item_t items[20];
    item_t itemlist[20];
    
    for (int i = 0; i < 20; i++)
    {
        items[i].id = 0;
        items[i].in_use = false;
        items[i].phealth = 0;
        items[i].pmaxhealth = 0;
        items[i].pattack = 0;
        items[i].pdefense = 0;
        for (int x = 0; x < 20; x++)
        {
            items[i].name[x] = 0;
            itemlist[i].name[x] = 0;
        }
    }
    OpenItem(itemlist);
    unsigned int points = 11;
    unsigned int level = 1;

    _sig.head = head;
    _sig.item = items;
    _sig.lvl = &level;
    _sig.point = &points;
    signal(SIGINT, HandleSIGINT);

    // deklarace promene pro zjisteni co ma program delat nasledovne
    int DoNext;

    // zjisteni velikosti terminalu
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // u je easter egg a slouzi pro nemoznost zmeny jmena hrace po tom co ho jednou zadal
    int u = DoNext = Start(&yMax, &xMax);

    if (u == 2 && argc > 1 && strcmp(argv[1], "uwu") == 0)
    {
        strcpy(head->name, "=^.^=");
        head->health = 9;
        head->maxhealth = 11;
        head->attack = 2;
        head->defense = 0;
        strcpy(items[0].name, "2977");
        points = 0;
    }
    else
    {
        u = 1;
    }

    getmaxyx(stdscr, yMax, xMax);
    DoNext = Menu(&yMax, &xMax);


    if (DoNext == 0)
    {
        EditCharacter(&yMax, &xMax, head, &points, items, &level, &u);
        Safe(head, &points, items, &level);
        Fight(&yMax, &xMax, head, &points, items, &level, &u, itemlist);
        return 0;
    }
    if (DoNext == 1)
    {
        Load(head, &points, items, &level);
        Fight(&yMax, &xMax, head, &points, items, &level, &u, itemlist);
        return 0;
    }
    if (DoNext == 2)
    {
        endwin();
        return 0;
    }

    endwin();
    return 0;
}