/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-01 13:11:30
 * @LastEditTime: 2020-08-02 09:51:06
 * @LastEditors: P19Y0UN9_居居
 * @Description: dfs,删边（伪）
 * @FilePath: \Luogu\P5022 旅行.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <queue>
#include <cstring>
#define maxn 5005
using namespace std;
struct node
{
    int to, next;
} e[maxn * 2];
int head[maxn];
int cnt = 0;
bool vis[maxn] = {0};
int n, m;
int maxv;          //入环点分支较大的
int minv;          //入环点分支较小的
int u[maxn] = {0}; //标记为环点
int flag = 0, st, tag = 0;
//flag表示是否已经找到了环，tag表示当前find的点是否为环点,st是入环点


void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u) //m==n-1
{
    cout << u << ' ';
    vis[u] = 1;
    priority_queue<int, vector<int>, greater<int>> q; //最小堆
    for (int i = head[u]; i; i = e[i].next)
    {
        int p = e[i].to;
        if (vis[p])
            continue;
        q.push(p);
    }
    while (!q.empty())
    {
        dfs(q.top());
        q.pop();
    }
}

void find(int x, int pre) //找环，当前节点和父节点
{
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].next)
    {
        int p = e[i].to;
        if (p == pre)
            continue;
        if (!vis[p])
        {
            find(p, x);
            if (flag)
            {
                u[x] = tag;
                if (x == st)
                    tag = 0;
                return;
            }
        }
        else //找完一圈回到起点,说明有环
        {
            u[x] = 1;
            flag = 1;
            tag = 1;
            st = p;
            return;
        }
    }
    return;
}

int another[maxn];
void dfs100(int x)
{
    cout<<x<<" ";
    vis[x] = 1;
    priority_queue<int, vector<int>, greater<int> >q;
    for (int i = head[x]; i; i = e[i].next)
    {
        int p = e[i].to;
        if (vis[p])
            continue;
        q.push(p);
    }
    if (!u[x] || (x != st && u[x] && flag == 0)) //如果是非环点或者是非入环点且已经变为树
    {
        while (!q.empty())
        {
            dfs100(q.top());
            q.pop();
        }
        return;
    }
    else
    {
        if (x == st) //由此进入环中
        {
            while (!q.empty())
            {
                int p = q.top();
                q.pop();
                if (!u[p])
                    dfs100(p);
                if (u[p] && flag == 0)
                {
                    another[p] = q.top();
                    flag = 1;
                    dfs100(p);
                    continue;
                }
                if (u[p] && flag == 1) 
                {
                //如果进入环中后再一次回到st，并且开始跑另一个环点的时候，
                //说明之前已经掉过头了，这个时候就可以取消标记然后当成树来对待。
                    flag = 0;
                    if (!vis[p])
                        dfs100(p);
                }
            }
            return;
        }
        if (flag == 1) //如果是第1遍跑环，这个时候是可以回头的
        {
            while (!q.empty())
            {
                int p = q.top();
                q.pop();
                if (!u[p])
                    dfs100(p);
                else
                {
                    if (!q.empty())
                        another[p] = q.top();
                    else
                        another[p] = another[x];
                    if (p < another[p])
                        dfs100(p);
                    else
                        continue; //跳过环点
                }
            }
            return;
        }
    }
}

int main()
{
    cin >> n >> m;
    int t1, t2;
    for (int i = 1; i <= m; i++)
    {
        cin >> t1 >> t2;
        add(t1, t2);
        add(t2, t1);
    }
    if (m == n - 1)
    {
        dfs(1);
    }
    if (n == m)
    {
        find(1, 0);
        memset(vis, 0, sizeof(vis));
        flag=0;
        dfs100(1);
    }
    return 0;
}