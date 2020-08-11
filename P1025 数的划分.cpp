/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-11 14:40:40
 * @LastEditTime: 2020-08-11 14:51:10
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1025 数的划分.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, ans;

void dfs(int mod, int sum, int step)
{
    if (step == k)
    {
        if (sum == n)
            ans++;
        return;
    }
    for (int i = mod; sum + i * (k - step) <= n; i++)
    {
        dfs(i, sum + i, step + 1);
    }
}

int main()
{
    cin >> n >> k;
    dfs(1, 0, 0);
    cout << ans;
}