/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-07 11:03:13
 * @LastEditTime: 2020-08-07 11:36:15
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\CF3B Lorry.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <algorithm>
#include <iostream>
#define maxn 100005

using namespace std;

struct node
{
    int val, id;
} a[maxn], b[maxn];
bool cmp(node a, node b)
{
    return a.val > b.val;
}

int cnt_a, cnt_b;             //计数
int sum_a[maxn], sum_b[maxn]; //前缀和
int use_a, use_b;             //存最优方案id
int ans, n, v, t, p;

int main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> p;
        if (t == 1)
        {
            a[++cnt_a].val = p;
            a[cnt_a].id = i;
        }
        else
        {
            b[++cnt_b].val = p;
            b[cnt_b].id = i;
        }
    }
    sort(a + 1, a + 1 + cnt_a, cmp);
    sort(b + 1, b + 1 + cnt_b, cmp);
    if (cnt_b == 0)
    {
        for (int i = 1; i <= n && i <= v; i++)
        {
            ans += a[i].val;
        }
        cout << ans << endl;
        for (int i = 1; i <= n && i <= v; i++)
        {
            cout << a[i].id << ' ';
        }
        return 0;
    }
    if (cnt_a == 0)
    {
        for (int i = 1; i <= n && i * 2 <= v; i++)
        {
            ans += b[i].val;
        }
        cout << ans << endl;
        for (int i = 1; i <= n && i * 2 <= v; i++)
        {
            cout << b[i].id << ' ';
        }
        return 0;
    }
    for (int i = 1; i <= cnt_a; i++)
    {
        sum_a[i] = sum_a[i - 1] + a[i].val;
    }
    for (int i = 1; i <= cnt_b; i++)
    {
        sum_b[i] = sum_b[i - 1] + b[i].val;
    }
    for (int i = 0; i <= v && i <= cnt_a; i++)
    {
        if (sum_a[i] + sum_b[min((v - i) / 2, cnt_b) /*防止未装满*/] > ans)
        {
            ans = sum_a[i] + sum_b[min((v - i) / 2, cnt_b)];
            use_a = i;
            use_b = min((v - i) / 2, cnt_b);
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= use_a; i++)
    {
        cout << a[i].id << ' ';
    }
    for (int i = 1; i <= use_b; i++)
    {
        cout << b[i].id << ' ';
    }
    return 0;
}
