/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-07 10:24:33
 * @LastEditTime: 2020-08-07 10:34:41
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\CF1029B Creating the Contest.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 200005

using namespace std;

int a[maxn];
int n, ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int sum = 1;
    for (int i = n; i >= 1; i--)
    {
        if (a[i - 1] * 2 >= a[i])
        {
            sum++;
        }
        else
        {
            ans = max(ans, sum);
            sum = 1;
        }
    }
    cout << max(ans,sum);
}
