#include <stdio.h>
#include <math.h>

int main() {
    float x1, x2, dx, e, x, radian, d, sinx, cosx;
    short n;
    printf("Low border:");
    if(scanf("%f", &x1) <= 0) {
        printf("Invalid data");
        return 0;
    };
    printf("Top border:");
    if(scanf("%f", &x2) <= 0) {
        printf("Invalid data");
        return 0;
    };
    printf("Step:");
    if(scanf("%f", &dx) <= 0) {
        printf("Invalid data");
        return 0;
    };
    printf("Precision:");
    if(scanf("%f", &e) <= 0) {
        printf("Invalid data");
        return 0;
    };

    printf("X\t\tComputed value\t\tTable value\t\tDifference\n");
    x = x1;
    while(x <= x2) {
        radian = x*M_PI/180;

        d = sinx = radian;
        n = 1;
        while(fabs(d) >= e) {
            d *= (-radian*radian) / ((n+1)*(n+2));
            sinx += d;
            n += 2;
        }

        printf("%.2f\t\t%.3f\t\t\t%.3f\t\t\t%.3f\n", x, sinx, sin(radian), fabs(sinx-sin(radian)));
        x += dx;
    }
    return 0;
}
