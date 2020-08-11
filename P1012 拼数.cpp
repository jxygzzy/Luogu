/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-10 10:12:13
 * @LastEditTime: 2020-08-10 10:21:53
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1012 拼数.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a[25];
int n;
bool cmp(string a, string b)
{
    return (a+b)>(b+a);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n,cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
}