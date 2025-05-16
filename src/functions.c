#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include <signal.h>
#include "functions.h"

node_t *NewNode(node_t *_head)
{
    node_t *current = _head->back;
    current->next = malloc(sizeof(node_t));
    if (current->next == NULL)
    {
        exit(EXIT_FAILURE);
    }
    _head->back = current->next;
    current->next->back = current;
    current = current->next;
    current->next = _head;
    for (int x = 0; x < 10; x++)
    {
        current->name[0] = 0;
    }
    return current;
}

void DeleteLastNode(node_t *_head)
{
    node_t *current = _head->back;
    current->back->next = current->next;
    current->next->back = current->back;
    free(current);
}

int PrintRandoms(int min, int max)
{
    int rd_num = rand() % (max - min + 1) + min;
    return rd_num;
}

int Start(int *pyMax, int *pxMax)
{
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    int yMax = *pyMax;
    int xMax = *pxMax;
    WINDOW *stwin = newwin(6, 24, (int)yMax / 2 - 1, (int)xMax / 2 - 12);
    box(stwin, 0, 0);
    wattron(stwin, COLOR_PAIR(1));
    mvwprintw(stwin, 1, 1, " __  ___  __  __  ___ ");
    mvwprintw(stwin, 2, 1, "(__   |  [__][__)  |  ");
    mvwprintw(stwin, 3, 1, " __)  |  |  ||  \\  |  ");
    mvwprintw(stwin, 4, 1, "                      ");
    wattroff(stwin, COLOR_PAIR(1));
    refresh();
    wrefresh(stwin);
    int c;
    do
    {
        flushinp();
        c = wgetch(stwin);
        if (c == 'u')
        {
            halfdelay(5);
            flushinp();
            c = wgetch(stwin);
            if (c == 'w')
            {
                flushinp();
                c = wgetch(stwin);
                cbreak();
                if (c == 'u')
                {
                    init_pair(2, COLOR_RED, COLOR_BLACK);
                    delwin(stwin);
                    clear();
                    refresh();
                    WINDOW *boykisser_win = newwin(50, 50, (int)yMax / 2 - 13, (int)xMax / 2 - 20);
                    // box(stwin, 0, 0);
                    wattron(stwin, COLOR_PAIR(2));
                    char buffer = '%';
                    mvwprintw(boykisser_win, 1, 1, "     @@@=                         @@ @\n"); // 4
                    mvwprintw(boykisser_win, 2, 1, "   @@  @@                      @@    @\n");
                    mvwprintw(boykisser_win, 3, 1, "   @     @                   @@      @\n");
                    mvwprintw(boykisser_win, 4, 1, "  @       @@   @@@@@@       @         @\n");
                    mvwprintw(boykisser_win, 5, 1, "  @        =@  @     @@    @          @ \n");
                    mvwprintw(boykisser_win, 6, 1, " @+          @  @       @%c@           @\n", buffer);
                    mvwprintw(boykisser_win, 7, 1, " @            @@                      @\n");
                    mvwprintw(boykisser_win, 8, 1, " @           @@@@@@                   @\n");
                    mvwprintw(boykisser_win, 9, 1, " @                                    @\n");
                    mvwprintw(boykisser_win, 10, 1, "  @                                  @-\n");
                    mvwprintw(boykisser_win, 11, 1, "  @                         -+*=     @\n");
                    mvwprintw(boykisser_win, 12, 1, "   @    @@@@@@@@       @@@@@@@@    *@\n");
                    mvwprintw(boykisser_win, 13, 1, "@- %c@   @   @@@#       @@@@   #   @@@@@", buffer);
                    mvwprintw(boykisser_win, 14, 1, "@@      @@  @@@@       @@@@   @     +@\n");
                    mvwprintw(boykisser_win, 15, 1, "  @@             @@@              @@\n");
                    mvwprintw(boykisser_win, 16, 1, "   @ =====    @   @    @    ===    @#\n");
                    mvwprintw(boykisser_win, 17, 1, " @            @@@@@@@@             @@\n");
                    mvwprintw(boykisser_win, 18, 1, "  @@-*@=@@                    @@-*@=\n");
                    mvwprintw(boykisser_win, 19, 1, "         @@-*@=@@          @=\n");
                    mvwprintw(boykisser_win, 20, 1, "       @               @=\n");
                    mvwprintw(boykisser_win, 21, 1, "            @@              @@\n");
                    mvwprintw(boykisser_win, 22, 1, "           @                 @\n");
                    mvwprintw(boykisser_win, 23, 1, "             @:               @\n");
                    mvwprintw(boykisser_win, 24, 1, "            @                 @\n");
                    wattroff(boykisser_win, COLOR_PAIR(1));
                    move(0, 0);
                    wrefresh(boykisser_win);
                    halfdelay(50);
                    flushinp();
                    flushinp();
                    wgetch(boykisser_win);
                    clear();
                    refresh();
                    delwin(boykisser_win);
                    return 2;
                }
            }
        }
    } while (c != 10);
    clear();
    refresh();
    delwin(stwin);
    return 1;
}

int Menu(int *pyMax, int *pxMax)
{
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    int yMax = *pyMax;
    int xMax = *pxMax;
    WINDOW *menuwin = newwin(9, 14, (int)yMax / 2 - 5, (int)xMax / 2 - 7);
    keypad(menuwin, true);
    char choices[3][10] = {"NEW GAME", "LOAD GAME", "EXIT"};
    int choice;
    int highlight = 0;
    box(menuwin, 0, 0);
    clear();
    refresh();

    while (true)
    {
        wrefresh(menuwin);
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
            {
                wattron(menuwin, COLOR_PAIR(1));
            }
            mvwprintw(menuwin, 2 * i + 2, 2, "%s", choices[i]);
            wattroff(menuwin, COLOR_PAIR(1));
        }
        flushinp();
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
        case 'w':
        {
            if (highlight != 0)
            {
                highlight--;
            }
            break;
        }
        case KEY_DOWN:
        case 's':
        {
            if (highlight != 2)
            {
                highlight++;
            }
        }
        default:
            break;
        }
        if (choice == 10)
        {
            delwin(menuwin);
            return highlight;
        }
    }
}

int ItemCount(item_t items[])
{
    int count = 0;
    for (int x = 0; x < 20; x++)
    {
        if (items[x].name[0] > 0)
        {
            count++;
        }
    }
    return count;
}

int has_leading_blank(const char *str)
{
    return isspace((unsigned char)str[0]);
}

int has_trailing_blank(const char *str)
{
    size_t len = strlen(str);
    return len > 0 && isspace((unsigned char)str[len - 1]);
}

void EditCharacter(int *pyMax, int *pxMax, node_t *_head, unsigned int *points, item_t items[], unsigned int *level, int *u)
{
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    char buffer[8];
    buffer[0] = 0;
    int yMax = *pyMax;
    int xMax = *pxMax;
    WINDOW *stwin = newwin(19, 30, (int)yMax / 2 - 10, (int)xMax / 2 - 15);
    keypad(stwin, true);
    char choices[8][14] = {"Name:", "Level:", "Health:", "Attack:", "Defence:", "Skill Points:", "Items:", "Confirm"};
    int choice;
    int highlight = 0;
    box(stwin, 0, 0);
    clear();
    refresh();

    while (true)
    {
        wrefresh(stwin);
        for (int i = 0; i < 8; i++)
        {
            if (i == highlight)
            {
                wattron(stwin, COLOR_PAIR(1));
            }
            if (i == 7)
            {
                wattron(stwin, A_REVERSE);
                mvwprintw(stwin, 2 * i + 2, 12, "%s", choices[i]);
                wattroff(stwin, A_REVERSE);
            }
            else
            {
                mvwprintw(stwin, 2 * i + 2, 1, "  %s", choices[i]);
            }
            wattroff(stwin, COLOR_PAIR(1));
            switch (i)
            {
            case 0:
                mvwprintw(stwin, 2 * i + 2, 9, "                  ");
                mvwprintw(stwin, 2 * i + 2, 27 - strlen(_head->name), "%s", _head->name);
                break;
            case 1:
                sprintf(buffer, "%d", *level);
                mvwprintw(stwin, 2 * i + 2, 27 - strlen(buffer), "%s", buffer);
                break;
            case 2:
                sprintf(buffer, "%d/%d", _head->health, _head->maxhealth);
                mvwprintw(stwin, 2 * i + 2, 27 - strlen(buffer), "%s", buffer);
                break;
            case 3:
                sprintf(buffer, "%d", _head->attack);
                mvwprintw(stwin, 2 * i + 2, 27 - strlen(buffer), "%s", buffer);
                break;
            case 4:
                sprintf(buffer, "%d", _head->defense);
                mvwprintw(stwin, 2 * i + 2, 27 - strlen(buffer), "%s", buffer);
                break;
            case 5:
                sprintf(buffer, "%d", *points);
                mvwprintw(stwin, 2 * i + 2, 27 - strlen(buffer), "%s", buffer);
                break;
            case 6:
                sprintf(buffer, "%d", ItemCount(items));
                mvwprintw(stwin, 2 * i + 2, 27 - strlen(buffer), "%s", buffer);
                break;
            default:
                break;
            }
        }
        wrefresh(stwin);
        flushinp();
        choice = wgetch(stwin);

        switch (choice)
        {
        case KEY_UP:
        case 'w':
        {
            if (highlight != 0)
            {
                highlight--;
            }
            break;
        }
        case KEY_DOWN:
        case 's':
        {
            if (highlight != 7)
            {
                highlight++;
            }
        }
        default:;
        }
        if (choice == 10)
        {
            if (highlight == 0 && *u != 2)
            {
                do
                {
                    mvwprintw(stwin, 2, 9, "                  ");
                    echo();
                    wattron(stwin, COLOR_PAIR(1));
                    wmove(stwin, 2, 9);
                    curs_set(1);
                    wgetnstr(stwin, _head->name, 10);
                    mvwprintw(stwin, 2, 9, "%s", _head->name);
                    curs_set(0);
                    wrefresh(stwin);
                    wattroff(stwin, COLOR_PAIR(1));
                    noecho();
                    if (has_leading_blank(_head->name) || has_trailing_blank(_head->name) || strlen(_head->name) == 0)
                    {
                        mvwprintw(stwin, 2, 9, "                  ");

                        wattron(stwin, COLOR_PAIR(3));
                        mvwprintw(stwin, 2, 15, "Invalid name");
                        wrefresh(stwin);
                        halfdelay(50);
                        flushinp();
                        wgetch(stwin);
                        wattroff(stwin, COLOR_PAIR(3));
                        cbreak();
                    }
                } while (has_leading_blank(_head->name) || has_trailing_blank(_head->name) || strlen(_head->name) == 0);
            }
            if (highlight == 2)
            {
                unsigned int bufferh = _head->maxhealth;
                do
                {
                    wattron(stwin, COLOR_PAIR(1));
                    sprintf(buffer, "%d/%d", _head->health, _head->maxhealth);
                    mvwprintw(stwin, 2 * highlight + 2, 27 - strlen(buffer), "%s", buffer);
                    wrefresh(stwin);
                    flushinp();
                    choice = wgetch(stwin);
                    if ((choice == KEY_UP || choice == 'w' || choice == '+') && *points > 0)
                    {
                        _head->maxhealth = _head->maxhealth + 1;
                        _head->health = _head->health + 1;
                        *points = *points - 1;
                    }
                    if ((choice == KEY_DOWN || choice == 's' || choice == '-') && _head->maxhealth > bufferh && _head->maxhealth >= _head->health)
                    {
                        _head->maxhealth = _head->maxhealth - 1;
                        _head->health = _head->health - 1;
                        *points = *points + 1;
                    }
                    sprintf(buffer, "%d/%d", _head->health, _head->maxhealth);
                    mvwprintw(stwin, 2 * highlight + 2, 9, "                  ");
                    mvwprintw(stwin, 2 * highlight + 2, 27 - strlen(buffer), "%s", buffer);
                    wattroff(stwin, COLOR_PAIR(1));

                    sprintf(buffer, "%d", *points);
                    mvwprintw(stwin, 2 * 5 + 2, 27 - 8, "        ");
                    mvwprintw(stwin, 2 * 5 + 2, 27 - strlen(buffer), "%s", buffer);
                    wrefresh(stwin);
                } while (choice != '\n');
            }

            if (highlight == 3)
            {
                unsigned int bufferh = _head->attack;
                do
                {
                    wattron(stwin, COLOR_PAIR(1));
                    sprintf(buffer, "%d", _head->attack);
                    mvwprintw(stwin, 2 * highlight + 2, 27 - strlen(buffer), "%s", buffer);
                    wrefresh(stwin);
                    flushinp();
                    choice = wgetch(stwin);
                    if ((choice == KEY_UP || choice == 'w' || choice == '+') && *points > 0)
                    {
                        _head->attack = _head->attack + 1;
                        *points = *points - 1;
                    }
                    if ((choice == KEY_DOWN || choice == 's' || choice == '-') && _head->attack > bufferh)
                    {
                        _head->attack = _head->attack - 1;
                        *points = *points + 1;
                    }
                    sprintf(buffer, "%d", _head->attack);
                    mvwprintw(stwin, 2 * highlight + 2, 27 - 10, "           ");
                    mvwprintw(stwin, 2 * highlight + 2, 27 - strlen(buffer), "%s", buffer);
                    wattroff(stwin, COLOR_PAIR(1));

                    sprintf(buffer, "%d", *points);
                    mvwprintw(stwin, 2 * 5 + 2, 27 - 10, "           ");
                    mvwprintw(stwin, 2 * 5 + 2, 27 - strlen(buffer), "%s", buffer);
                    wrefresh(stwin);
                } while (choice != '\n');
            }

            if (highlight == 4)
            {
                unsigned int bufferh = _head->defense;
                do
                {
                    wattron(stwin, COLOR_PAIR(1));
                    sprintf(buffer, "%d", _head->defense);
                    mvwprintw(stwin, 2 * highlight + 2, 27 - strlen(buffer), "%s", buffer);
                    wrefresh(stwin);
                    flushinp();
                    choice = wgetch(stwin);
                    if ((choice == KEY_UP || choice == 'w' || choice == '+') && *points > 0)
                    {
                        _head->defense = _head->defense + 1;
                        *points = *points - 1;
                    }
                    if ((choice == KEY_DOWN || choice == 's' || choice == '-') && _head->defense > bufferh)
                    {
                        _head->defense = _head->defense - 1;
                        *points = *points + 1;
                    }
                    sprintf(buffer, "%d", _head->defense);
                    mvwprintw(stwin, 2 * highlight + 2, 27 - 10, "           ");
                    mvwprintw(stwin, 2 * highlight + 2, 27 - strlen(buffer), "%s", buffer);
                    wattroff(stwin, COLOR_PAIR(1));

                    sprintf(buffer, "%d", *points);
                    mvwprintw(stwin, 2 * 5 + 2, 27 - 10, "           ");
                    mvwprintw(stwin, 2 * 5 + 2, 27 - strlen(buffer), "%s", buffer);
                    wrefresh(stwin);
                } while (choice != '\n');
            }

            if (highlight == 6)
            {
                cbreak();
                keypad(stwin, false);
                wclear(stwin);
                clear();
                refresh();
                PrintItem(items);
                box(stwin, 0, 0);
                keypad(stwin, true);
            }

            if (highlight == 7 && strlen(_head->name) == 0)
            {
                mvwprintw(stwin, 2, 9, "                  ");

                wattron(stwin, COLOR_PAIR(3));
                mvwprintw(stwin, 2, 17, "Empty name");
                wrefresh(stwin);
                halfdelay(50);
                flushinp();
                wgetch(stwin);
                wattroff(stwin, COLOR_PAIR(3));
                cbreak();
            }
            if (highlight == 7 && strlen(_head->name) != 0)
            {
                if (*u != 2)
                {
                    *u = 2;
                }
                cbreak();
                keypad(stwin, false);
                wclear(stwin);
                delwin(stwin);
                clear();
                refresh();
                return;
            }
        }
    }
}

void PrintItem(item_t items[])
{
    clear();
    int highlight = 0;
    int choice = 0;
    int wcount = ItemCount(items);
    int length = 8;
    for (int i = 0; i < wcount; i++)
    {
        if (length < strlen(items[i].name))
        {
            length = strlen(items[i].name);
        }
    }
    char choices[wcount + 1][length + 1];
    for (int i = 0; i < wcount; i++)
    {
        strcpy(choices[i], items[i].name);
    }
    strcpy(choices[wcount], "Confirm");
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *itemwin = newwin(2 * wcount + 5, 14 + length, (int)yMax / 2 - 10, (int)xMax / 2 - 15);
    keypad(itemwin, true);
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    box(itemwin, 0, 0);
    clear();
    refresh();

    while (true)
    {
        clear();
        wrefresh(itemwin);
        mvwprintw(itemwin, 2, 2, "Items: ");
        for (int i = 0; i <= wcount; i++)
        {
            if (i != wcount && items[i].in_use == true)
            {
                wattron(itemwin, COLOR_PAIR(2));
            }
            if (i == highlight)
            {
                wattron(itemwin, COLOR_PAIR(1));
            }
            if (i == wcount && wcount == 0)
            {
                wattron(itemwin, A_REVERSE);
                mvwprintw(itemwin, 2 * i + 3, ((12 + length) / 2) - 2, "%s", choices[i]);
            }
            else if (i == wcount)
            {
                wattron(itemwin, A_REVERSE);
                mvwprintw(itemwin, 2 * i + 2, ((12 + length) / 2) - 2, "%s", choices[i]);
            }
            if (i < wcount)
            {
                mvwprintw(itemwin, 2 * i + 2, 9, "%s", choices[i]);
            }
            wattroff(itemwin, COLOR_PAIR(1));
            wattroff(itemwin, COLOR_PAIR(2));
            wattroff(itemwin, A_REVERSE);
        }

        wrefresh(itemwin);
        flushinp();
        choice = wgetch(itemwin);

        switch (choice)
        {
        case KEY_UP:
        case 'w':
        {
            if (highlight > 0)
            {
                highlight--;
            }
            break;
        }
        case KEY_DOWN:
        case 's':
        {
            if (highlight < wcount)
            {
                highlight++;
            }
            break;
        }
        case 10:
        {
            if (highlight == wcount)
            {
                delwin(itemwin);
                refresh();
                return;
            }
            else
            {
                items[highlight].in_use = !items[highlight].in_use;
            }
        }
        default:
            break;
        }
    }
}

void Fight(int *yMax, int *xMax, node_t *_head, unsigned int *points, item_t items[], unsigned int *level, int *u, item_t itemlist[])
{
    clear();
    refresh();
    WINDOW *fightwin = newwin(*yMax - 2, *xMax - 2, 1, 1);
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    char choices[3][6] = {"Fight", "Act", "Item"};
    int choice = 0;
    int highlight = 0;
    box(fightwin, 0, 0);
    keypad(fightwin, true);
    refresh();
    int lvlbuffer = *level;

    node_t *enemy = _head->back;
    if (_head->back = _head)
    {
        enemy = NewNode(_head);
        enemy->maxhealth = (*level) * ((rand() % 3) + 1);
        enemy->health = enemy->maxhealth;
        enemy->attack = (*level) * ((rand() % 5) + 1);
        enemy->defense = (*level) * ((rand() % 3) + 1);
        strcpy(enemy->name, "M18 Hellcat");
    }

    while (true)
    {
        mvwprintw(fightwin, (*yMax / 4) - 6 + 1, (*xMax / 2) - 11, "       (\\___/)");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 2, (*xMax / 2) - 11, "      (  ¤_¤  )");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 3, (*xMax / 2) - 11, "     /| .___. |\\");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 4, (*xMax / 2) - 11, "    /_|_______|_\\");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 5, (*xMax / 2) - 11, "    | | \\___/ | |");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 6, (*xMax / 2) - 11, "    |_| |   | |_|");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 7, (*xMax / 2) - 11, "   / /| |   | |\\ \\");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 8, (*xMax / 2) - 11, "  /_/ | |   | | \\_\\");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 9, (*xMax / 2) - 11, " / /  |  ---  |  \\ \\");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 10, (*xMax / 2) - 11, "(_/   |_______|   \\_)");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 11, (*xMax / 2) - 11, "      |   |   |");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 12, (*xMax / 2) - 11, "      |_  |  _|");
        mvwprintw(fightwin, (*yMax / 4) - 6 + 13, (*xMax / 2) - 11, "      (___|___)");
        wmove(fightwin, *yMax / 2, 1);
        for (int i = 0; i < *xMax - 4; i++)
        {
            wprintw(fightwin, "_");
        }
        wattron(fightwin, A_REVERSE);
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
            {
                wattron(fightwin, COLOR_PAIR(1));
            }
            mvwprintw(fightwin, (*yMax / 4) * 3, (*xMax / 4) * (i + 1) - (strlen(choices[i]) / 2), "%s", choices[i]);
            wattroff(fightwin, COLOR_PAIR(1));
        }
        wattroff(fightwin, A_REVERSE);
        wrefresh(fightwin);
        flushinp();
        choice = wgetch(fightwin);

        switch (choice)
        {
        case KEY_LEFT:
        case 'a':
        {
            if (highlight > 0)
            {
                highlight--;
            }
            break;
        }
        case KEY_RIGHT:
        case 'd':
        {
            if (highlight < 2)
            {
                highlight++;
            }
        }
        default:;
            if (choice == 10)
            {
                switch (highlight)
                {
                case 0:
                {
                    cbreak();
                    keypad(fightwin, false);
                    wclear(fightwin);
                    clear();
                    refresh();
                    char text[3][30] = {"Normal Attack", "Ultimate Attack", "Back"};
                    int c = MenuForThreeChoices(yMax, xMax, text);
                    if (c == 0 || c == 1)
                    {
                        for (int i = 0; i < 20; i++)
                        {
                            if (items[i].id != 0 && items[i].in_use == 1)
                            {
                                _head->attack = (int)_head->attack + (int)items[i].pattack;
                                _head->defense = (int)_head->defense + (int)items[i].pdefense;
                                _head->maxhealth = (int)_head->maxhealth + (int)items[i].pmaxhealth;
                                _head->health = (int)_head->health + (int)items[i].phealth;
                                items[i].in_use = 0;
                                items[i].id = 0;
                                strcpy(items[i].name, "");
                                items[i].pattack = 0;
                                items[i].pdefense = 0;
                                items[i].phealth = 0;
                                items[i].pmaxhealth = 0;
                            }
                        }
                    }
                    switch (c)
                    {
                    case 0:
                    {
                        Attack(yMax, xMax, enemy, 0);
                        wattroff(fightwin, COLOR_PAIR(1));
                        box(fightwin, 0, 0);
                        keypad(fightwin, true);
                        cbreak();
                        break;
                    }
                    case 1:
                    {
                        Attack(yMax, xMax, enemy, 1);
                        wattroff(fightwin, COLOR_PAIR(1));
                        box(fightwin, 0, 0);
                        keypad(fightwin, true);
                        cbreak();
                        break;
                    }
                    case 2:
                        box(fightwin, 0, 0);
                        keypad(fightwin, true);
                        cbreak();
                        break;
                    }
                    if ((int)enemy->health <= 0)
                    {
                        if (rand() % 2)
                        {
                            for (int i = 0; i < 20; i++)
                            {
                                if (items[i].id == 0)
                                {
                                    int itmid = (rand() % 20) + 1;
                                    items[i].id = itmid;
                                    strcpy(items[i].name, itemlist[itmid].name);
                                    items[i].pattack = itemlist[itmid].pattack;
                                    items[i].pdefense = itemlist[itmid].pdefense;
                                    items[i].phealth = itemlist[itmid].phealth;
                                    items[i].pmaxhealth = itemlist[itmid].pmaxhealth;
                                    items[i].in_use = 0;
                                    break;
                                }
                            }
                        }
                        *points = *points + (enemy->maxhealth / 2);
                        (*level)++;
                        _head->health = _head->health + (_head->maxhealth / 2);
                        if ((int)_head->health > (int)_head->maxhealth)
                        {
                            _head->health = _head->maxhealth;
                        }
                        enemy = NewNode(_head);
                        enemy->maxhealth = (*level) * ((rand() % 3) + 1);
                        enemy->health = enemy->maxhealth;
                        enemy->attack = (*level) * ((rand() % 5) + 1);
                        enemy->defense = (*level) * ((rand() % 3) + 1);
                        strcpy(enemy->name, "Demon cat");
                        cbreak();
                        keypad(fightwin, false);
                        wclear(fightwin);
                        clear();
                        refresh();
                        Next(yMax, xMax);
                        EditCharacter(yMax, xMax, _head, points, items, level, u);
                        box(fightwin, 0, 0);
                        keypad(fightwin, true);
                        cbreak();
                        break;
                    }
                    else
                    {
                        int damage = enemy->attack - _head->defense;
                        if (damage < 0)
                        {
                            damage = 1;
                        }
                        _head->health = _head->health - damage;
                    }
                    box(fightwin, 0, 0);
                    keypad(fightwin, true);
                    cbreak();
                    break;
                }
                case 1:
                {
                    cbreak();
                    keypad(fightwin, false);
                    wclear(fightwin);
                    clear();
                    refresh();
                    char text[3][30] = {"Enemy Stat", "My Stat", "Back"};
                    int c = MenuForThreeChoices(yMax, xMax, text);
                    switch (c)
                    {
                    case 0:
                    {
                        EnemyStat(*yMax, *xMax, enemy);
                        box(fightwin, 0, 0);
                        keypad(fightwin, true);
                        cbreak();
                        break;
                    }
                    case 1:
                    {
                        EditCharacter(yMax, xMax, _head, points, items, level, u);
                        box(fightwin, 0, 0);
                        keypad(fightwin, true);
                        cbreak();
                        break;
                    }
                    case 2:
                        box(fightwin, 0, 0);
                        keypad(fightwin, true);
                        cbreak();
                        break;
                    }
                    break;
                }
                case 2:
                {
                    cbreak();
                    keypad(fightwin, false);
                    wclear(fightwin);
                    clear();
                    refresh();
                    PrintItem(items);
                    box(fightwin, 0, 0);
                    keypad(fightwin, true);
                    cbreak();
                    break;
                }
                default:
                    break;
                }
                if (_head->health <= 0)
                {
                    delwin(fightwin);
                    clear();
                    Death(yMax, xMax);
                    keypad(fightwin, false);
                    remove("SaveFile.pam");
                    clear();
                    endwin();
                    DeleteLinkedList(_head);
                    exit(0);
                }
            }
        }
        Safe(_head, points, items, level);
    }
}

void EnemyStat(int yMax, int xMax, node_t *enemy)
{
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    char buffer[8];
    buffer[0] = 0;
    WINDOW *enemywin = newwin(13, 30, yMax / 2 - 7, xMax / 2 - 15);
    keypad(enemywin, true);
    char choices[5][14] = {"Name:", "Health:", "Attack:", "Defense:", "Back"};
    int choice;
    int highlight = 4;
    box(enemywin, 0, 0);
    clear();
    refresh();

    while (true)
    {
        wrefresh(enemywin);
        for (int i = 0; i < 5; i++)
        {
            if (i == highlight)
            {
                wattron(enemywin, COLOR_PAIR(1));
            }
            if (i == 4)
            {
                wattron(enemywin, A_REVERSE);
                mvwprintw(enemywin, 2 * i + 2, 12, "%s", choices[i]);
                wattroff(enemywin, A_REVERSE);
            }
            else
            {
                mvwprintw(enemywin, 2 * i + 2, 1, "  %s", choices[i]);
            }
            wattroff(enemywin, COLOR_PAIR(1));
            switch (i)
            {
            case 0:
                mvwprintw(enemywin, 2 * i + 2, 9, "                  ");
                mvwprintw(enemywin, 2 * i + 2, 27 - strlen(enemy->name), "%s", enemy->name);
                break;
            case 1:
                sprintf(buffer, "%d/%d", enemy->health, enemy->maxhealth);
                mvwprintw(enemywin, 2 * i + 2, 27 - strlen(buffer), "%s", buffer);
                break;
            case 2:
                sprintf(buffer, "%d", enemy->attack);
                mvwprintw(enemywin, 2 * i + 2, 27 - strlen(buffer), "%s", buffer);
                break;
            case 3:
                sprintf(buffer, "%d", enemy->defense);
                mvwprintw(enemywin, 2 * i + 2, 27 - strlen(buffer), "%s", buffer);
                break;
            default:
                break;
            }
        }
        wrefresh(enemywin);
        flushinp();
        choice = wgetch(enemywin);
        if (choice == 10)
        {
            delwin(enemywin);
            clear();
            refresh();
            return;
        }
    }
}

int MenuForThreeChoices(int *yMax, int *xMax, char choices[3][30])
{
    int length = strlen(choices[0]);
    for (int i = 0; i < 3; i++)
    {
        if (length < strlen(choices[i]))
        {
            length = strlen(choices[i]);
        }
    }
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    WINDOW *choicewin = newwin(9, length + 4, *yMax / 2 - 4, *xMax / 2 - ((length + 2) / 2));
    keypad(choicewin, true);
    int choice;
    int highlight = 0;
    box(choicewin, 0, 0);
    while (true)
    {
        wrefresh(choicewin);
        wattron(choicewin, A_REVERSE);
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
            {
                wattron(choicewin, COLOR_PAIR(1));
            }
            mvwprintw(choicewin, 2 * i + 2, 2, "%s", choices[i]);
            wattroff(choicewin, COLOR_PAIR(1));
        }
        wattroff(choicewin, A_REVERSE);
        flushinp();
        choice = wgetch(choicewin);

        switch (choice)
        {
        case KEY_UP:
        case 'w':
        {
            if (highlight > 0)
            {
                highlight--;
            }
            break;
        }
        case KEY_DOWN:
        case 's':
        {
            if (highlight < 2)
            {
                highlight++;
            }
            break;
        }
        case 10:
        {
            delwin(choicewin);
            clear();
            refresh();
            return highlight;
        }
        }
    }
}

void Attack(int *yMax, int *xMax, node_t *enemy, int type)
{
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    int c;
    int damage = 0;
    if (type == 0)
    {
        c = 4;
    }
    if (type == 1)
    {
        c = 10;
    }
    int key[c];
    for (int i = 0; i < c; i++)
    {
        key[i] = (rand() % 4);
    }
    WINDOW *attackwin = newwin(3, 2 * c + 4, *yMax / 2 - 4, *xMax / 2 - ((c + 2) / 2));
    box(attackwin, 0, 0);
    wrefresh(attackwin);
    keypad(attackwin, true);
    wmove(attackwin, 1, 1);
    for (int i = 0; i < c; i++)
    {
        switch (key[i])
        {
        case 0:
            wprintw(attackwin, "w ");
            break;
        case 1:
            wprintw(attackwin, "s ");
            break;
        case 2:
            wprintw(attackwin, "a ");
            break;
        case 3:
            wprintw(attackwin, "d ");
            break;
        default:
            break;
        }
        wrefresh(attackwin);
    }
    if (type == 0)
    {
        halfdelay(20);
    }
    if (type == 1)
    {
        halfdelay(10);
    }
    wmove(attackwin, 1, 1);
    int symbol;
    for (int i = 0; i < c; i++)
    {
        flushinp();
        symbol = wgetch(attackwin);
        if ((symbol == 'w' || symbol == KEY_UP) && key[i] == 0)
        {
            damage++;
            wattron(attackwin, COLOR_PAIR(5));
        }
        else if ((symbol == 's' || symbol == KEY_DOWN) && key[i] == 1)
        {
            damage++;
            wattron(attackwin, COLOR_PAIR(5));
        }
        else if ((symbol == 'a' || symbol == KEY_LEFT) && key[i] == 2)
        {
            damage++;
            wattron(attackwin, COLOR_PAIR(5));
        }
        else if ((symbol == 'd' || symbol == KEY_RIGHT) && key[i] == 3)
        {
            damage++;
            wattron(attackwin, COLOR_PAIR(5));
        }
        else
        {
            wattron(attackwin, COLOR_PAIR(6));
        }
        switch (key[i])
        {
        case 0:
            wprintw(attackwin, "w ");
            break;
        case 1:
            wprintw(attackwin, "s ");
            break;
        case 2:
            wprintw(attackwin, "a ");
            break;
        case 3:
            wprintw(attackwin, "d ");
            break;
        default:
            break;
        }
        symbol = -1;
        wattroff(attackwin, COLOR_PAIR(5));
        wattroff(attackwin, COLOR_PAIR(6));
        wrefresh(attackwin);
    }
    damage = damage + enemy->next->attack - enemy->defense;
    if (damage <= 0)
    {
        damage = 1;
    }
    delwin(attackwin);
    cbreak();
    refresh();
    enemy->health = enemy->health - damage;
    return;
}

void Safe(node_t *_head, unsigned int *points, item_t items[], unsigned int *level)
{
    FILE *save = fopen("SaveFile.pam", "w");
    if (save == NULL)
    {
        return;
    }
    char array[56] = {0};
    char offset = 0;
    memcpy(array + offset, _head->name, 10);
    offset = offset + 10;
    memcpy(array + offset, &(_head->maxhealth), 4);
    offset = offset + 4;
    memcpy(array + offset, &(_head->health), 4);
    offset = offset + 4;
    memcpy(array + offset, &(_head->attack), 4);
    offset = offset + 4;
    memcpy(array + offset, &(_head->defense), 4);
    offset = offset + 4;
    for (int i = 0; i < 20; i++)
    {
        memcpy(array + offset, &(items[i].id), 1);
        offset++;
    }
    memcpy(array + offset, points, 4);
    offset = offset + 4;
    memcpy(array + offset, level, 4);
    offset = offset + 4;
    char crc = 0;
    for (int i = 0; i < offset; i++)
    {
        crc = crc ^ array[i];
    }
    memcpy(array + offset, &crc, 1);
    offset = offset + 1;

    fwrite(array, sizeof(char), 56, save);
    fclose(save);
    return;
}
void OpenItem(item_t items[])
{
    FILE *fitem = fopen("items", "r");
    if (fitem == NULL)
    {
        exit(-1);
    }
    char *p = NULL;
    size_t number = 0;
    int i = 0;
    while (-1 != getline(&p, &number, fitem))
    {
        char buffer[20] = {0};
        if (sscanf(p, "%d,%19[^,],%d,%d,%d,%d", &items[i].id, buffer, &items[i].phealth, &items[i].pmaxhealth, &items[i].pattack, &items[i].pdefense))
        {
            strcpy(items[i].name, buffer);
            i++;
        }
        else
        {
            fprintf(stderr, "Invalid data format in items file: %s\n", p);
        }
    }
    fclose(fitem);
    return;
}

int Load(node_t *_head, unsigned int *points, item_t items[], unsigned int *level)
{
    FILE *save = fopen("SaveFile.pam", "r");
    if (save == NULL)
    {
        return;
    }
    char array[56] = {0};
    char offset = 0;
    fread(array, sizeof(char), 56, save);
    memcpy(_head->name, array + offset, 10);
    offset = offset + 10;
    memcpy(&(_head->maxhealth), array + offset, 4);
    offset = offset + 4;
    memcpy(&(_head->health), array + offset, 4);
    offset = offset + 4;
    memcpy(&(_head->attack), array + offset, 4);
    offset = offset + 4;
    memcpy(&(_head->defense), array + offset, 4);
    offset = offset + 4;
    for (int i = 0; i < 20; i++)
    {
        memcpy(&(items[i].id), array + offset, 1);
        offset++;
    }
    memcpy(points, array + offset, 4);
    offset = offset + 4;
    memcpy(level, array + offset, 4);
}

void Next(int *pyMax, int *pxMax)
{
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    int yMax = *pyMax;
    int xMax = *pxMax;
    WINDOW *endwin = newwin(3, 12, (int)yMax / 2 - 2, (int)xMax / 2 - 5);
    box(endwin, 0, 0);
    wattron(endwin, COLOR_PAIR(1));
    mvwprintw(endwin, 1, 1, "Next level");
    wattroff(endwin, COLOR_PAIR(1));
    refresh();
    wrefresh(endwin);
    int c = 0;
    flushinp();
    do
    {
        c = wgetch(endwin);
    } while (c != 10);
    delwin(endwin);
    clear();
}

void Death(int *pyMax, int *pxMax)
{
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    int yMax = *pyMax;
    int xMax = *pxMax;
    WINDOW *endwin = newwin(3, 10, (int)yMax / 2 - 2, (int)xMax / 2 - 4);
    box(endwin, 0, 0);
    wattron(endwin, COLOR_PAIR(1));
    mvwprintw(endwin, 1, 1, "You died");
    wattroff(endwin, COLOR_PAIR(1));
    refresh();
    wrefresh(endwin);
    int c = 0;
    flushinp();
    do
    {
        c = wgetch(endwin);
    } while (c != 10);
    delwin(endwin);
    clear();
}

void DeleteLinkedList(node_t *head)
{
    if (head == NULL)
        return;

    node_t *current = head->next;
    while (current != head)
    {
        node_t *tmp = current;
        current = current->next;
        free(tmp);
    }
    free(head);
}