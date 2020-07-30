/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-30 10:43:07
 * @LastEditTime: 2020-07-30 14:17:37
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\CF1009B Minimum Ternary String.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str, ans;
long long cnt, pos;

void mysort()
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            cnt++;
            continue;
        }
        ans += str[i];
    }
    pos=ans.size();
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == '2')
        {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        ans.insert(ans.begin() + pos, '1');
    }
}

int main()
{
    cin >> str;
    mysort();
    cout << ans;
}
