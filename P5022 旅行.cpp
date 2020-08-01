/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-01 13:11:30
 * @LastEditTime: 2020-08-01 20:43:11
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
int cnt;
bool vis[maxn];
int n, m;
int maxv;    //入环点分支较大的
int minv;    //入环点分支较小的
int u[maxn]; //标记为环点
int flag, st, tag;
//flag表示是否已经找到了环，tag表示当前find的点是否为环点,st是入环点
int dflag; //表示环分支的方向

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
    priority_queue<int, vector<int>, greater<int> > q;//最小堆
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

void dfs100(int x) //n==m
{
    cout << x << " ";
    vis[x] = 1;
    priority_queue<int, vector<int>, greater<int> > q;//最小堆
    for (int i = head[x]; i; i = e[i].next)
    {
        int p = e[i].to;
        if (!vis[p])
        {
            q.push(p);
        }
    }
    if (!u[x] && x != st) //普通的点
    {

        while (!q.empty())
        {

            dfs100(q.top());
            q.pop();
        }
    }
    if (u[x] && x == st) //入环点
    {
        //找出入环点分支一大一小，删边时用到
        while (!u[q.top()])
        {
            q.pop();
        }
        minv = q.top();
        q.pop();
        while (!u[q.top()])
        {
            q.pop();
        }
        maxv = q.top(); //入环点分支且为环点就两个
        q.pop();
        dflag = 0;
        dfs100(minv);
        dflag = 1;
        dfs100(maxv);
    }
    if (u[x] && x != st && !dflag) //环点中较小的一边
    {
        if (x > maxv) //删边（伪）
        {
            return;
        }
        while (!q.empty())
        {
            dfs100(q.top());
            q.pop();
        }
    }
    if (u[x] && x != st && dflag) //环点中较大的一边
    {
        while (!q.empty())
        {
            dfs100(q.top());
            q.pop();
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
        dfs100(1);
    }
    return 0;
}