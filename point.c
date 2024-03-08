#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_points(tPoint* point) {
    if (point == 0)
        return 0;
    
    int count = 1;
    for (int i = 0; i < point->nextCount; i++) {
        count += count_points(&point->next[i]);
    }
    return count;
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

void addJoint(tPoint* point, int value) {
    int newCount = point->nextCount + 1;
    tPoint* newNext = malloc(newCount * sizeof(tPoint));
    memcpy(newNext, point->next, point->nextCount * sizeof(tPoint));
    newNext[newCount - 1].value = value;
    newNext[newCount - 1].nextCount = 0;
    newNext[newCount - 1].next = malloc(0);

    free(point->next);
    point->next = newNext;
    point->nextCount = newCount;
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