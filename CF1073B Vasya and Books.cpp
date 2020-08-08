/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-07 11:52:47
 * @LastEditTime: 2020-08-07 12:37:33
 * @LastEditors: P19Y0UN9_居居
 * @Description:        
 * @FilePath: \Luogu\CF1073B Vasya and Books.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <stack>
#define maxn 200005

using namespace std;

int a[maxn];
int vis[maxn];
stack<int> s;
int cnt;
int n, b;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        s.push(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        cin >> b;
        if (!vis[b])
        {
            // cnt++;
            while (s.top() != b)
            {
                cnt++;
                vis[s.top()] = 1;
                s.pop();
            }
            cnt++;
            vis[b] = 1;
            s.pop();
            cout << cnt << " ";
        }
        else
        {
            cout << 0 << ' ';
        }
    }
    return 0;
}
