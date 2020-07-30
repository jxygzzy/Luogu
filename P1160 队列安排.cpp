/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-27 09:50:47
 * @LastEditTime: 2020-07-27 11:14:03
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1160 队列安排.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int index;
    int l, r;
} a[100005];

bool cmp(node a, node b)
{
    return a.l < b.l;
}

int n, m;
int k, p;

int main()
{
    cin >> n;
    a[1] = {1, 0, 0};
    int first=1;
    for (int i = 2; i <= n; i++)
    {
        a[i].index = i;
        cin >> k >> p;
        if (p == 0)
        {
            a[a[k].l].r = i;
            a[i].l = a[k].l;
            a[i].r = k;
            a[k].l = i;
            
            if(k==first) first=i;
        }
        else
        {
            a[i].r = a[k].r;
            a[a[k].r].l = i;
            a[i].l = k;
            a[k].r = i;
        }
    }
    cin >> m;
    while (m--)
    {
        int x;
        cin >> x;
        if (a[x].index != 0)
        {
            a[a[x].l].r = a[x].r;
            a[a[x].r].l = a[x].l;
            a[x].index = 0;
            n--;
        }
    }
    int i=1,x=first;
    while(i<=n){
        cout<<a[x].index<<" ";
        x=a[x].r;
        i++;
    }
    
}