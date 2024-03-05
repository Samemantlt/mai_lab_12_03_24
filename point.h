#pragma once

typedef struct Point {
    int value;

    struct Point* next;
    int nextCount;
} tPoint;


int count_points(tPoint* point);

tPoint read();