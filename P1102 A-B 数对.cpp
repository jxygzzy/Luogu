/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-28 10:00:48
 * @LastEditTime: 2020-07-28 10:33:50
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1102 A-B 数对.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long a[200005];
long long n;
int c;
long long ans = 0;
map<long long, int> m;

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if(m[a[i]-c]!=0)
            ans+=m[a[i]-c];
    }
    cout<<ans;
}