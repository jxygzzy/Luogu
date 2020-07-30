/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-27 13:43:06
 * @LastEditTime: 2020-07-27 15:16:09
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P5788 【模板】单调栈.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <stdio.h>
#include <stack>
#include <algorithm>

int a[3000005];

int f[3000005];
std::stack<int> s;
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            f[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", f[i]);
}