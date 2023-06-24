

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
};

#define train_count sizeof(train)/sizeof(train[0])

float rand_float() {
    return (float) rand() / (float) RAND_MAX;
}

float cost(float w) {
    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i) {
        float x = train[i][0];
        float y = x*w;
        float d = train[i][1];
        result += d*d;
        printf("actual %f, expected: %f\n", y, train[i][1]);
    }

    return result;
}

int main() {
    // y = x*w

    srand(69);
    float w = rand_float()*1000.0f;

    float eps = 1e-3;
    printf("%f\n", cost(w));
    printf("%f\n", cost(w - eps));

    return 0;
}
