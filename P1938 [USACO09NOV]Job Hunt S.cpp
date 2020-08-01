/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-01 09:43:09
 * @LastEditTime: 2020-08-01 13:01:11
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1938 [USACO09NOV]Job Hunt S.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int to, next, w;
} e[1010];

int head[1010];
int dis[1010];
int inq[1010];
int sum[1010];
int d, p, c, f, s;
int cnt;
int ans;
priority_queue<int, vector<int>, greater<int> > q;

void spfa()
{
    ans = 0;
    dis[s] = d;
    q.push(s);
    inq[s] = 1;
    sum[s]++;
    while (!q.empty())
    {
        int x = q.top();
        q.pop();
        inq[x] = 0;
        sum[x]++;
        if (sum[x] > c)
        {
            cout << -1 << endl;
            return;
        }
        for (int i = head[x]; i; i = e[i].next)
        {
            int v = e[i].to;
            int w = e[i].w;
            if (dis[v] < dis[x] + w)
            {
                dis[v] = dis[x] + w;
                if (!inq[v])
                {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=c;i++){
        ans=max(ans,dis[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    cin >> d >> p >> c >> f >> s;
    for (int i = 1; i <= p; i++)
    {
        int u, v;
        cin >> u >> v;
        e[++cnt].to = v;
        e[cnt].next = head[u];
        e[cnt].w = d;
        head[u] = cnt;
    }
    for (int i = 1; i <= f; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[++cnt].to = v;
        e[cnt].next = head[u];
        e[cnt].w = d - w;
        head[u]=cnt;
    }
    spfa();
    return 0;
}