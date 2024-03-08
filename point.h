#include <stdbool.h>

typedef struct Point {
    int value;

    struct Point* next;
    int nextCount;
} tPoint;


int countPoints(tPoint* point);

tPoint* findParent(tPoint* tree, int value);

bool hasDirectChild(tPoint* point, int value);

tPoint* find(tPoint* tree, int value);

void addJoint(tPoint* point, int value);

void removePoint(tPoint* point, int value);