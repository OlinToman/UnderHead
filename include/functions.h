#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <ncurses.h>
#include <signal.h>

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
typedef struct node // linked list pro entity (hlava je samotny hrac dalsi prvky listu budou nepratele)
{
    char name[10];
    int health;
    int maxhealth;
    int attack;
    int defense;
    struct node *next;
    struct node *back;
} node_t;

typedef struct item // struktura pro vlastnosti predmetu
{
    char name[20];
    int phealth;
    int pmaxhealth;
    int pattack;
    int pdefense;
    bool in_use;
    char id;
} item_t;

node_t *NewNode(node_t *_head);                                                                                                        // vytvori novy uzel v linked listu
void DeleteLastNode(node_t *_head);                                                                                                    // vymaze posledni uzel v linked listu
int ItemCount(item_t items[]);                                                                                                         // spocita kolik predmetu hrac ma
int has_leading_blank(const char *str);                                                                                                // kontrola neplatneho jmena
int has_trailing_blank(const char *str);                                                                                               // kontrola neplatneho jmena
int PrintRandoms(int min, int max);                                                                                                    // vrati nahodne cislo v rozsahu
int Start(int *yMax, int *xMax);                                                                                                       // vytvori uvoni obraz
int Menu(int *yMax, int *xMax);                                                                                                        // vytvori menu
void EditCharacter(int *yMax, int *xMax, node_t *_head, unsigned int *points, item_t items[], unsigned int *level, int *u);            // vytvori menu postavy + upravy postavy
void PrintItem(item_t items[]);                                                                                                        // vypise vsechny predmety
void Fight(int *yMax, int *xMax, node_t *_head, unsigned int *points, item_t items[], unsigned int *level, int *u, item_t itemlist[]); // vytvori menu pro boj
void EnemyStat(int yMax, int xMax, node_t *enemy);                                                                                     // vypise nepratele
int MenuForThreeChoices(int *yMax, int *xMax, char choices[3][30]);                                                                    // vytvori menu pro 3 volby
void Attack(int *yMax, int *xMax, node_t *_head, int type);                                                                            // vytvori menu pro utok
void Safe(node_t *_head, unsigned int *points, item_t items[], unsigned int *level);                                                   // ulozi hru
void OpenItem(item_t items[]);                                                                                                         // otevreni souboru s predmety
int Load(node_t *_head, unsigned int *points, item_t items[], unsigned int *level);                                                    // nacteni ulozene hry
void Next(int *pyMax, int *pxMax);                                                                                                     // vytvori menu pro pokracovani
void DeleteLinkedList(node_t *_head);                                                                                                  // vymaze linked list
void Death(int *pyMax, int *pxMax);                                                                                                    // vytvori menu pro smrt
#endif