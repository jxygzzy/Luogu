/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-31 10:25:27
 * @LastEditTime: 2020-07-31 13:58:34
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1032 字串变换.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

string f;            //初始值
string l;            //目标值
string a[10], b[10]; //转换规则
int cnt;             //规则数
struct node
{
    string ch;
    int step;
};

map<string, int> m;
queue<node> q;

int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin >> f >> l;
    while (cin >> a[++cnt] >> b[cnt])
        ;
    node s;
    s.ch = f;
    s.step = 0;
    q.push(s);
    while (!q.empty() && q.front().ch != l && q.front().step <= 10)
    {
        string temp;
        node u = q.front();
        q.pop();
        if (m.find(u.ch) != m.end())
            continue;
        m[u.ch] = 1;
        for (int i = 1; i <= cnt; i++)
        {
            int pos = u.ch.find(a[i], 0);
            while (1)
            {
                if (pos == string::npos)
                {
                    break;
                }
                node v;
                temp = u.ch;
                v.ch = temp.replace(pos, a[i].size(), b[i]);
                v.step = u.step + 1;
                q.push(v);
                pos = u.ch.find(a[i], pos + 1);
            }
        }
    }
    if (q.empty() || q.front().step > 10)
    {
        cout << "NO ANSWER!";
    }
    else
    {
        cout << q.front().step;
    }
    return 0;
}