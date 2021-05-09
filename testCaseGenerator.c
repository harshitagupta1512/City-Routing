#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a, b, c, d, e;
    int x;
    int n;
    srand(time(0));
    printf("enter number of edges:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        a = rand() % 1000 + 1;
        b = rand() % 4 + 1;
        c = rand() % 291 + 10;
        d = rand() % 10 + 1;
        e = rand() % 91 + 10;
        x = 0.4 * a + 0.6 * (0.4 * c + 1 / (b * 6.00) + 1 / (e * 0.4));
        printf("%3d %3d %3d %3d %3d ---> weight=%d\n", a, b, c, d, e, x);
    }
}
