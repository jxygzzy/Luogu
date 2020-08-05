/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-04 10:07:06
 * @LastEditTime: 2020-08-04 11:04:01
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1922 女仆咖啡厅桌游吧.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define maxn 100005

using namespace std;

struct node
{
    int to, next;
} e[maxn * 2];
int head[maxn];
int cnt;
int n;
int vis[maxn];
void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int dfs(int x)
{
    vis[x] = 1;
    int empty = 1;//最初假设都没建
    int ans = 0;
    for (int i = head[x]; i; i = e[i].next)
    {
        if (!vis[e[i].to])
        {
            int next = dfs(e[i].to);
            if (next)
            {
                ans += next;
            }
            else//叶节点，一定是空
            {
                empty++;
            }
        }
    }
    ans+=empty/2;//对半分
    return ans;
}

int main()
{
    cin >> n;
    int u, v;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    int ans = dfs(1);
    cout << ans;
}
