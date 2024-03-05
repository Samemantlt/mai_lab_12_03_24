#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printMenu(){
    printf("\n\nMenu:\n");
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

tPoint* find(tPoint* tree, int value) {
    if (tree->value == value)
        return tree;
    
    for (int i = 0; i < tree->nextCount; i++)
    {
        tPoint* point = find(&tree->next[i], value);
        if (point != NULL)
            return point;
    }

    return NULL;
}

void addJoint(tPoint* point, int value) {
    int newCount = point->nextCount + 1;
    tPoint* newNext = malloc(newCount * sizeof(tPoint));
    memcpy(newNext, point->next, point->nextCount);
    newNext[newCount - 1].value = value;
    newNext[newCount - 1].nextCount = 0;
    newNext[newCount - 1].next = malloc(0);

    free(point->next);
    point->next = newNext;
    point->nextCount = newCount;
}

bool hasDirectChild(tPoint* point, int value) {
    for (int i = 0; i < point->nextCount; i++)
        if (point->next[i].value == value)
            return true;
    
    return false;
}

tPoint* findParent(tPoint* tree, int value) {
    if (hasDirectChild(tree, value))
        return tree;
    
    for (int i = 0; i < tree->nextCount; i++)
    {
        tPoint* point = findParent(&tree->next[i], value);
        if (point != NULL)
            return point;
    }

    return NULL;
}

void removePoint(tPoint* point, int value) {
    tPoint* parent = findParent(point, value);
    if (parent == NULL)
    {
        printf("Point not found %i", value);
        return;
    }

    int newCount = parent->nextCount - 1;
    tPoint* newNext = malloc(sizeof(tPoint) * newCount);

    int newIndex = 0;
    for (int i = 0; i < parent->nextCount; i++) {
        if (parent->next[i].value != value)
            newNext[newIndex++] = parent->next[i];
    }

    free(parent->next);
    parent->next = newNext;
    parent->nextCount = newCount;
}

tPoint read(){
    tPoint point;
    point.value = 0;
    point.next = malloc(0);
    point.nextCount = 0;
    
    while (true) {
        printMenu();
        printf("executed");
        int selection;
        scanf("%i", &selection);

        switch (selection) {
            case 0:
                return point;
            case 1:
                printTree(&point, 0);
                break;
            case 2:
                int start, end;
                scanf("%i %i", &start, &end);

                tPoint* from = find(&point, start);
                if (from == NULL){
                    printf("Point %i not found", start);
                    break;
                }

                addJoint(from, end);
                break;
            case 3:
                int toDelte;
                scanf("%i", &toDelte);
                tPoint* parent = findParent(&point, toDelte);

                break;
        }
    }
}