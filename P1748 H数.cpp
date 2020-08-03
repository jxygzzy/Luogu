/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-03 12:19:46
 * @LastEditTime: 2020-08-03 12:44:04
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1748 H数.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#include <set>
#define ll long long
#define maxn 10005
//穷举超时，set去重
using namespace std;

typedef set<ll>::iterator it;

set<ll> s;
int n;

int main()
{
    cin>>n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    s.insert(1);
    it front = s.begin();
    for (int i = 1; i < n; i++)
    {
        ll pre=*front;
        s.insert(pre*2);
        s.insert(pre*3);
        s.insert(pre*5);
        s.insert(pre*7);
        front++;
    }
    cout<<*front;
    return 0;
}
