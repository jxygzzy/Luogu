#include <stdio.h>

using namespace std;

int n, m, i, k, t, a[1005];
int main()
{
    for (i = 1; i <= 8; i++)
    {
        scanf("%x", &a[i]);
        getchar();
        if (a[i] == 0)
        {
            if (m == 0)
                n = i;
            m++;
        }
        else
        {
            if (m > t)
            {
                t = m;
                k = n;
            }
            m = 0;
        }
    }
    if (m > t)
    {
        t = m;
        k = n;
    }
    if (t == 8)
        printf("::");
    else
    {
        for (i = 1; i <= 8; i++)
        {
            if (i == k)
            {
                int y = 1;
                while (y < t)
                    i++, y++;
                printf(":");
                if (i == 8)
                    printf(":");
            }
            else
            {
                if (i != 1)
                    printf(":");
                printf("%x", a[i]);
            }
        }
    }
}