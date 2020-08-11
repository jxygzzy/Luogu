/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-10 09:27:11
 * @LastEditTime: 2020-08-10 09:47:25
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P5886 Hello, 2020!.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <vector>
#define maxn 100005

using namespace std;

int n, m, p;
int a[maxn*10];
int ans;
int k;

int main()
{
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        int aik;
        for (int j = 0; j < k; j++)
        {
            cin >> aik;
            a[aik]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (a[i] == p)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    for (int i = 1; i <= m; i++)
    {
        if (a[i] == p)
        {
            cout << a[i] <<" ";
        }
    }
    return 0;
}
