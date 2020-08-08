/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-08 18:13:06
 * @LastEditTime: 2020-08-08 20:52:56
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P5603 小C与桌游.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#define maxn 500005

using namespace std;

int n, m;
int in1[maxn], in2[maxn];
struct node
{
    int to, next;
} e[maxn];
int head[maxn];
int cnt;
int ans, mx = 0;
int vis[maxn];
priority_queue<int, vector<int>, greater<int> > s1;
priority_queue<int> s2;
stack<int> st;

void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void topsort1()
{
    for (int i = 1; i <= cnt; i++)
    {
        if (!in1[i])
        {
            s1.push(i);
        }
    }
    while (!s1.empty())
    {
        int x = s1.top();
        if (x > mx)
        {
            ans++;
            mx = x;
        }
        s1.pop();
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            in1[y]--;
            if (!in1[y])
            {
                s1.push(y);
            }
        }
    }
}

void topsort2()
{
    mx = 0;
    ans = 0;
    for (int i = 1; i <= n; i++)
        if (!in2[i])
            s2.push(i);
    while (s2.size())
    {
        queue<int> s3;
        while (s2.size() && s2.top() > mx)
        {
            s3.push(s2.top());
            s2.pop();
        }
        if (!s2.size())
        {
            ans++;
            mx = s3.front(); //因为是从大到小插入，q3的队头一定是最大的
            while (s3.size())
            {
                int x = s3.front();
                s3.pop();
                for (int i = head[x]; i; i = e[i].next)
                {
                    int y = e[i].to;
                    if (--in2[y] == 0)
                        s2.push(y);
                }
            }
        }
        else
            while (s2.size())
            {
                int x = s2.top();
                s2.pop();
                for (int i = head[x]; i; i = e[i].next)
                {
                    int y = e[i].to;
                    if (--in2[y] == 0)
                        s3.push(y);
                }
            }
        while (s3.size())
        {
            s2.push(s3.front());
            s3.pop();
        } //放回去
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v);
        in1[v]++;
        in2[v]++;
    }
    topsort1();
    cout << ans << endl;
    topsort2();
    cout << ans << endl;
    return 0;
}