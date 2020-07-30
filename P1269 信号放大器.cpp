/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-30 15:25:14
 * @LastEditTime: 2020-07-30 16:07:36
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1269 信号放大器.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define maxn 20005

using namespace std;

int n, k, p, ans;
struct node
{
    int to, next, w;
} e[maxn * 2];
int head[maxn], dis[maxn], dep[maxn]; 
//dis表示到父节点的衰减量（距离），dep表示子树中衰减最多的（距离最远的）
int cnt;

void dfs(int x, int f)
{//自底向上的贪心
    for (int i = head[x]; i; i = e[i].next)
    {
        if (e[i].to != f)
        {
            dis[e[i].to] = e[i].w;
            dfs(e[i].to, x);
            dep[x] = max(dep[e[i].to] + e[i].w, dep[x]);//更新最远子树距离
        }
    }
    if (dis[x] + dep[x] > p)
    {//只有当到父节点的距离与最远子节点的距离之和大于服务器强度时放置增强器
        ans++;
        dep[x] = 0;
    }
}

int main()
{
    cin >> n;
    int maxd = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        int v, w;
        for (int j = 1; j <= k; j++)
        {
            cin >> v >> w;
            e[++cnt].to = v;
            e[cnt].next = head[i];
            e[cnt].w = w;
            head[i] = cnt;
            maxd = max(maxd, w);
        }
    }
    cin >> p;
    if (maxd >= p)
    {
        cout << "No solution.";
        return 0;
    }
    dfs(1, 1);
    cout << ans;
}