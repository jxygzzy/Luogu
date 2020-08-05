/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-05 14:06:05
 * @LastEditTime: 2020-08-05 14:14:44
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P3873 [TJOI2010]天气预报.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#define MOD 4147
using namespace std;

int a[110];
int w[10000005];
int sum;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = n; i >= 1; i--)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n + 1; i <= m; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum+=a[j]*w[i-j];
        }
        w[i]=sum%MOD;
    }
    cout<<w[m];
}