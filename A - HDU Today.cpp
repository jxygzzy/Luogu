#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#define INF 100000000
using namespace std;
int a[160][160], dis[160], vis[160], n, num, ans;
map<string, int> m;
int re()
{
    ans = 0;
    num = 0;
    m.erase(m.begin(), m.end());
    for (int i = 0; i < 160; i++)
    {
        dis[i] = INF;
        for (int j = 0; j < 160; j++)
            a[i][j] = i == j ? 0 : INF;
    }
    memset(vis, 0, sizeof(vis));
    cin >> n;
    if (n != -1)
        return 1;
    return 0;
}
void in()
{
    string u, v;
    int w;
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v >> w;
        m[u] = m[u] ? m[u] : ++num;
        m[v] = m[v] ? m[v] : ++num;
        a[m[u]][m[v]] = w;
        a[m[v]][m[u]] = w;
    }
}
int main()
{
    while (re())
    {
        string b, e;
        cin >> b >> e;
        m[b] = ++num;
        if (!m[e])
            m[e] = ++num;
        in();
        dis[1] = 0;
        for (int i = 1; i <= num; i++)
        {
            int minn = INF, index = 0;
            for (int j = 1; j <= num; j++)
            {
                if (dis[j] <= minn && !vis[j])
                {
                    minn = dis[j];
                    index = j;
                }
            }
            vis[index] = 1;
            for (int j = 1; j <= num; j++)
                dis[j] = min(dis[j], dis[index] + a[index][j]);
        }
        ans = dis[m[e]] == INF ? -1 : dis[m[e]];
        cout << ans << endl;
    }
    return 0;
}
