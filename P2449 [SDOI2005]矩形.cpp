#include <iostream>
#include <algorithm>
#define maxn 7005

using namespace std;

int f[maxn], n, ans;

struct node
{
    int x1, x2, y1, y2;
} e[maxn];

int find(int x)
{
    if (x == f[x])
        return x;
    else
        return f[x] = find(f[x]);
}

bool check(node a, node b)
{
    if ((a.y1 < b.x1 || b.y2 < a.x1) || (a.y2 < b.x2 || b.y2 < a.x2))
        return 0;
    if ((a.x1 == b.y1 || a.y2 == b.x1) && (a.x2 == b.y2 || a.y2 == b.x2))
        return 0;
    return 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> e[i].x1 >> e[i].y1 >> e[i].x2 >> e[i].y2;
        f[i] = i;
        for (int j = 1; j < i; j++)
        {
            if (check(e[i], e[j]))
            {
                int u = find(i);
                int v = find(j);
                if (u == v)
                    continue;
                f[u] = v;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == i)
        {
            ans++;
        }
    }
    cout << ans;
}