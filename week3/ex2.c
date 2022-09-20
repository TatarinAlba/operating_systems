#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    float x, y;
};

float distance(struct Point A, struct Point B) {
    return sqrt(pow((double) (B.x - A.x), 2.0) + pow((double) (B.y - A.y), 2.0));
}

float area(struct Point A, struct Point B, struct Point C) {
    return 1.0f/2.0f * fabs(A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y);
}

int main() {
    struct Point A, B, C;
    A.x = 2.5f;
    A.y = 6.0f;
    B.x = 1.0f;
    B.y = 2.2f;
    C.x = 10.0f;
    C.y = 6.0f;
    printf("Distance=%f\nArea=%f", distance(A, B), area(A, B, C));
    return 0;
}
