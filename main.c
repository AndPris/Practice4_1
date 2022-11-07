#include <stdio.h>
#include <math.h>

int main() {
    float x1, x2, dx, e, x, radian, d, sinx, cosx;
    short n, check;

    while(1) {
        printf("\nEnter 1 to calculate sinus or 2 to calculate cosinus:");

        if(scanf("%d", &check) <= 0) {
            printf("Invalid data");
            return 0;
        };

        if(check==1 || check==2) break;
    }

    printf("Low border:");
    if (scanf("%f", &x1) <= 0) {
        printf("Invalid data");
        return 0;
    };

    printf("Top border:");
    if (scanf("%f", &x2) <= 0) {
        printf("Invalid data");
        return 0;
    };

    printf("Step:");
    if (scanf("%f", &dx) <= 0) {
        printf("Invalid data");
        return 0;
    };

    printf("Precision:");
    if (scanf("%f", &e) <= 0) {
        printf("Invalid data");
        return 0;
    };

    printf("\nX\t\tComputed value\t\tTable value\t\tDifference\n");
    x = x1;
    if(check==1) {
        while (x <= x2) {
            radian = x * M_PI / 180;

            d = sinx = radian;
            n = 1;
            while (fabs(d) >= e) {
                d *= (-radian * radian) / ((n + 1) * (n + 2));
                sinx += d;
                n += 2;
            }

            printf("%.2f\t\t%.3f\t\t\t%.3f\t\t\t%.3f\n", x, sinx, sin(radian), fabs(sinx - sin(radian)));
            x += dx;
        }
    } else {
        while (x <= x2) {
            radian = x * M_PI / 180;

            d = cosx = n = 1;
            while (fabs(d) >= e) {
                d *= (-radian * radian) / (2*n*(2*n - 1));
                cosx += d;
                n++;
            }

            printf("%.2f\t\t%.3f\t\t\t%.3f\t\t\t%.3f\n", x, cosx, cos(radian), fabs(cosx - cos(radian)));
            x += dx;
        }
    }
    return 0;
}
