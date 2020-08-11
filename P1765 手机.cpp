/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-10 09:49:00
 * @LastEditTime: 2020-08-10 10:08:18
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1765 手机.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<char, int> keybord;
string in;
int ans;

void init()
{
    int count = 0;
    for (count = 0; count < 18; count++)
    {
        keybord['a' + count] = (count % 3) + 1;
    }
    keybord['a' + count] = 4;
    for (; count < 25; count++)
    {
        keybord['a' + count + 1] = (count % 3) + 1;
    }
    keybord['a' + count] = 4;
    keybord[' '] = 1;
}

int main()
{
    getline(cin, in, '\n');
    init();
    for (int i = 0; i < in.size(); i++)
    {
        ans += keybord[in[i]];
    }
    cout << ans;
}