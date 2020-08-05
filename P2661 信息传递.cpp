/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-04 11:27:05
 * @LastEditTime: 2020-08-04 15:12:27
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P2661 信息传递.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#include <set>
#define maxn 200005
#define INF 0x3f3f3f3f

using namespace std;

int T[maxn];
int in[maxn];
int ans = INF;
int n;
int flag[maxn];
int vis[maxn];

void remove(int i)
{
    flag[i] = 1;
    in[T[i]]--;
    if (!in[T[i]] && !flag[T[i]])
        remove(T[i]);
}

void dfs(int i, int s, int len)
{
    if (i == s && len != 0)
    {
        ans = min(ans, len);
        return;
    }
    if (!vis[T[i]])
    {
        vis[T[i]] = 1;
        dfs(T[i], s, len + 1);
    }
}

int main()
{
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> T[i];
        in[T[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!in[i] && !flag[i])
        {
            remove(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!flag[i] && !vis[i])
        {
            dfs(i, i, 0);
        }
    }
    cout << ans;
    return 0;
}
