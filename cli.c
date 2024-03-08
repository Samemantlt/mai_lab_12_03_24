#include "cli.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printMenu(){
    printf("\n[MENU]:\n");
    printf("0 - Run program (count points)\n");
    printf("1 - Print tree\n");
    printf("2 - Add joint\n");
    printf("3 - Remove joint\n");
    printf("Enter command index: ");
}

void printTree(tPoint* point, int offset) {
    for (int i = 0; i < offset; i++)
        printf(" ");
    
    printf("%i\n", point->value);
    for (int i = 0; i < point->nextCount; i++)
        printTree(&point->next[i], offset  + 1);
}

void removePointMenu(tPoint* point) {
    printf("[REMOVE]:\n");
    printf("Enter point to delete: ");
    int toDelte;
    scanf("%i", &toDelte);
    removePoint(point, toDelte);
}

void printTreeMenu(tPoint* point) {
    printf("[TREE]:\n");
    printTree(point, 0);
}

void addJointMenu(tPoint* point) {
    printf("[ADD]:\n");
    printf("Enter parent and new child (eg. 0 1): ");
    int start, end;
    scanf("%i %i", &start, &end);

    tPoint* existing = find(point, end);
    if (existing != NULL)
    {
        printf("Point %i already exists", end);
        return;
    }

    tPoint* from = find(point, start);
    if (from == NULL){
        printf("Point %i not found", start);
        return;
    }

    addJoint(from, end);
}

tPoint showCli(){
    tPoint point;
    point.value = 0;
    point.next = malloc(0);
    point.nextCount = 0;
    
    while (true) {
        printMenu();
        int selection;
        scanf("%i", &selection);

        switch (selection) {
            case 0:
                return point;
            case 1:
                printTreeMenu(&point);
                break;
            case 2:
                addJointMenu(&point);
                break;
            case 3:
                removePointMenu(&point);
                break;
        }
    }
}