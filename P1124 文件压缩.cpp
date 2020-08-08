/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-08 12:53:52
 * @LastEditTime: 2020-08-08 14:27:39
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1124 文件压缩.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, p, i, cnt = 1;
char s1[10005], s[10005], temp[10005];

int main()
{
    cin >> n >> s1 >> p;
    if (n == 1)
    {
        cout << s1;
        return 0;
    }
    strcpy(temp, s1);
    sort(temp, temp + n);
    char c = s1[p - 1];
    for (i = 0; i < n; i++)
    {
        if (temp[i] == c)
            break;
    }
    s[0] = s1[i];
    c = s1[i];
    temp[i] = ' ';
    for (int i = n - 1; i >= 0; i--)
    {
        if (temp[i] == c)
        {
            c = s1[i];
            s[cnt++] = c;
            temp[i] = ' ';
            i = n;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout<<s[i];
    }
    return 0;
}
