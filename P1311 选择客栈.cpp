/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-25 13:08:35
 * @LastEditTime: 2020-07-25 13:57:23
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * 丽江河边有 nn 家很有特色的客栈，客栈按照其位置顺序从 1 到 n 编号。
 * 每家客栈都按照某一种色调进行装饰（总共 k 种，用整数 0∼k−1 表示），且每家客栈都设有一家咖啡店，
 * 每家咖啡店均有各自的最低消费。
 * 两位游客一起去丽江旅游，他们喜欢相同的色调，又想尝试两个不同的客栈，因此决定分别住在色调相同的两家客栈中。
 * 晚上，他们打算选择一家咖啡店喝咖啡，要求咖啡店位于两人住的两家客栈之间（包括他们住的客栈），且咖啡店的最低消费不超过 p 。
 * 他们想知道总共有多少种选择住宿的方案，保证晚上可以找到一家最低消费不超过 p 元的咖啡店小聚。
 * @FilePath: \Luogu\P1311 选择客栈.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <algorithm>
#define maxn 200000

using namespace std;

int color, price;
int last[maxn];
int cnt[maxn];
int sum[maxn];
int ans = 0;
int now;

int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> color >> price;
        if (price <= p)
            now = i;
        if (now >= last[color])
            sum[color] = cnt[color];
        last[color]=i;
        ans+=sum[color];
        cnt[color]++;
    }
    cout << ans;
}
