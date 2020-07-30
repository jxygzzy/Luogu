/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-23 13:42:31
 * @LastEditTime: 2020-07-23 15:00:51
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 某城市有一个火车站，铁轨铺设如图。有n节车厢从A方向驶入车站，按进站的顺序编号为1～n。
 * 你的任务是判断是否能让他们按照某种特定的顺序进入B方向的铁轨并驶出车站。例如，出栈顺序（5 4 1 2 3）是不可能的，但（5 4 3 2 1）是可能的。 
 * 为了重组车厢，你可以借助中转站C。这是一个可以停放任意多节车厢的车站，但由于末端封顶，驶入C的车厢必须按照相反的顺序驶出C。对于每节车厢，
 * 一旦从A移入C，就不能返回A了;一旦从C移入B，就不能返回C了。也就是说，在任意时刻，只有两种选择：A到C和C到B。
 * 
 * 对于每一组数据，第一行是一个整数 N 。接下来若干行数据，每行 N 个数，代表 1 ~ N 车厢的出栈顺序，最后一组数据只有一个整数 0 。
 * 对于每一组数据，在最后输出空行。
 * 最后一组数据的 N=0 ，不输出。
 * n<=1000
 * @FilePath: \Luogu\UVA514 铁轨 Rails.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n;
    int judge[1010];
    cin >> n;
    while (n != 0)
    {
        while (1)
        {
            int flag = 1;
            stack<int> s;
            cin >> judge[1];
            if (judge[1] == 0)
                break;
            for (int j = 2; j <= n; j++)
            {
                cin >> judge[j];
            }
            int A, B;
            A = B = 1;
            while (B <= n)
            {
                if (A == judge[B])
                {
                    A++;
                    B++;
                }
                else if (!s.empty() && s.top() == judge[B])
                {
                    s.pop();
                    B++;
                }
                else if (A <= n)
                    s.push(A++);
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cin >> n;

        cout << "\n";
    }
}
