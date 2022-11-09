#include <stdio.h>
#include <math.h>

int main() {
    float x1, x2, dx, x, radian, d, sinx, cosx;
    short n, e, check;
    char ch, cond;

    do {
        cond = 0;
        printf("\nEnter 1 to calculate sinus or 2 to calculate cosinus:\n");
        scanf("%d%c", &check, &ch);
        if(ch != '\n') {
            printf("Invalid data");
            fflush(stdin);
            cond = 1;
            continue;
        }

        if(check != 1 && check != 2) {
            printf("Number out of range");
            fflush(stdin);
            cond = 1;
            ch = ' ';
        }
    } while(cond);
    ch = ' ';

    do {
        cond = 0;
        printf("Low border:\n");
        scanf("%f%c", &x1, &ch);
        if(ch != '\n') {
            printf("Invalid data\n");
            fflush(stdin);
            cond = 1;
        }
    } while(cond);
    ch = ' ';

    do {
        cond = 0;
        printf("Top border:\n");
        scanf("%f%c", &x2, &ch);
        if(ch != '\n') {
            printf("Invalid data\n");
            fflush(stdin);
            cond = 1;
            continue;
        }

        if(x1 >= x2) {
            printf("Low border is higher then top one or equals to it\n");
            fflush(stdin);
            cond = 1;
            ch = ' ';
        }

    } while(cond);
    ch = ' ';

    do {
        cond = 0;
        printf("Step:\n");
        scanf("%f%c", &dx, &ch);
        if(ch != '\n') {
            printf("Invalid data\n");
            fflush(stdin);
            cond = 1;
            continue;
        }

        if(dx <= 0) {
            printf("Step must be higher then 0\n");
            fflush(stdin);
            cond = 1;
            ch = ' ';
        }

    } while(cond);
    ch = ' ';

    do {
        cond = 0;
        printf("Precision:\n");
        scanf("%hd%c", &e, &ch);
        if(ch != '\n') {
            printf("Invalid data\n");
            fflush(stdin);
            cond = 1;
            continue;
        }

        if(e < 0) {
            printf("Precision must be higher then 0\n");
            fflush(stdin);
            cond = 1;
            ch = ' ';
        }

    } while(cond);

    printf("\nX\t\tComputed value\t\tTable value\t\tDifference\n");
    x = x1;
    if(check==1) {
        while (x <= x2) {
            radian = x * M_PI / 180;

            d = sinx = radian;
            n = 1;
            while (fabs(d) >= 1/pow(10, e)) {
                d *= (-radian * radian) / ((n + 1) * (n + 2));
                sinx += d;
                n += 2;
            }

            printf("%.2f\t\t%.*f\t\t\t%.*f\t\t\t%.*f\n", x, e, sinx, e, sin(radian), e, fabs(sinx - sin(radian)));
            x += dx;
        }
    } else {
        while (x <= x2) {
            radian = x * M_PI / 180;

            d = cosx = n = 1;
            while (fabs(d) >= 1/pow(10, e)) {
                d *= (-radian * radian) / (2*n*(2*n - 1));
                cosx += d;
                n++;
            }

            printf("%.2f\t\t%.*f\t\t\t%.*f\t\t\t%.*f\n", x, e, cosx, e, cos(radian), e, fabs(cosx - cos(radian)));
            x += dx;
        }
    }
    return 0;
}
