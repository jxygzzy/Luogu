/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-24 10:19:46
 * @LastEditTime: 2020-07-24 10:42:06
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 有N个单词和字符串T，按字典序输出以字符串T为前缀的所有单词。
 * 对于100%的数据，满足1≤N≤100000且所有字符均为小写字母;
 * 
 * @FilePath: \Luogu\P1628 合并序列.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define maxn 100001

using namespace std;

int n;
priority_queue<string, vector<string>, greater<string> > q;
string T;

int main()
{
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string word;
        cin >> word;
        q.push(word);
    }
    cin >> T;
    while (!q.empty())
    {
        string temp = q.top();
        q.pop();
        if (temp.find(T) == 0)
        {
            cout << temp << endl;
        }
    }
}
