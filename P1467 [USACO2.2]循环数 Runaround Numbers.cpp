/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-08-06 09:38:17
 * @LastEditTime: 2020-08-06 10:27:06
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1467 [USACO2.2]循环数 Runaround Numbers.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

bool check(string str)
{
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '0' || str.find(str[i], i + 1) != -1)
        {
            return false;
        }
    }
    int cnt = 0;
    int index = 0;
    int num = str[index] - '0';
    int len = str.size();
    cnt++;
    while (1)
    {
        index = (index + num) % len;
        if (index == 0 && cnt == len)
        {
            return true;
        }
        if (index == 0 && cnt != len)
            return false;
        cnt++;
        if (cnt > len)
        {
            return false;
        }
        num = str[index] - '0';
    }
}

int main()
{
    string m;
    cin >> m;
    int temp = stoi(m);
    temp++;
    m = to_string(temp);
    while (!check(m))
    {
        int temp = stoi(m);
        temp++;
        m = to_string(temp);
    }
    cout << m;
}
