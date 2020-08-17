#include <iostream>
#include <algorithm>
#define maxtime 100000

using namespace std;

int m, n;
struct node
{
    int id, time;
} a[25][25];
int tool[25][maxtime];
int cnt[25];
int last[25];
int all[25 * 25];
int ans;

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> all[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j].id;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j].time;
        }
    }
    for (int i = 1; i <= n * m; i++)
    {
        int u = all[i];
        cnt[u]++;
        int id = a[u][cnt[u]].id;
        int time = a[u][cnt[u]].time;
        int s = 0;
        for (int j = last[u] + 1;; j++)
        {
            if (tool[id][j] == 0)
            {
                s++;
            }
            else
            {
                s = 0;
            }
            if (s == time)
            {
                for (int k = j - time + 1; k <= j; k++)
                {
                    tool[id][k] = 1;
                }
                if (j > ans)
                    ans = j;
                last[u] = j;
                break;
            }
        }
    }
    cout << ans;
}