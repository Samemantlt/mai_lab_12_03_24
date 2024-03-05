#include "point.h"
#include <stdio.h>
#include <stdlib.h>

int count_points(tPoint* point) {
    if (point == 0)
        return 0;
    
    int count = 1;
    for (int i = 0; i < point->nextCount; i++) {
        count += count_points(&point->next[i]);
    }
    return count;
}

typedef struct {
    int start;
    int end;
} tJoint;

/*
tPoint createFrom(int index, tJoint* joints, int jointsCount) {
    int nextCount = 0;
    for (int i = 0; i < jointsCount; i++) {
        if (joints[i].start == index)
            nextCount++;
    }

    tPoint point;
    point.value = index;
    point.nextCount = nextCount;
    if (nextCount == 0){
        point.next = NULL;
        return point;
    }
    point.next = malloc(sizeof(tPoint) * nextCount);
    
    int nextIndex = 0;
    for (int i = 0; i < jointsCount; i++) {
        if (joints[i].start == index)
            point.next[nextIndex++] = createFrom(joints[i].end, joints, jointsCount);
    }

    return point;
}

tPoint read() {
    FILE* file = fopen("123.txt", "r");

    int jointsCount;
    fscanf(file,"%i", &jointsCount);

    tJoint* joints = malloc(sizeof(tJoint) * jointsCount);

    for (int i = 0; i < jointsCount; i++) {
        int start, end;
        fscanf(file,"%i %i", &start, &end);

        joints[i].start = start;
        joints[i].end = end;
    }

    return createFrom(0, joints, jointsCount);
}
*/