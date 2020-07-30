/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-27 10:46:39
 * @LastEditTime: 2020-07-27 12:02:34
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\P1714 切蛋糕.cpp
 * @居居 <jxygzzy@163.com>
 */

#include <iostream>
#include <algorithm>
#define maxn 500000

using namespace std;

int n, m, t;
int preSum[maxn + 5];
int index[maxn + 5];
int l = 1, r = 1;
int MaxSum = 0;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        preSum[i] = preSum[i - 1] + t; //前缀和
    }
    index[l] = 1;
    for (int i = 1; i <= n; i++)
    {
        while (index[l] < i - m) //不在范围（i-m，i）内，排除在左边
            l++;
        MaxSum = max(MaxSum, preSum[i] - preSum[index[l]]); //减去范围（i-m，i）内最小的值
        while (r >= l && preSum[i] < preSum[index[r]])      //排除比值sum[i]大的
            r--;
        r++;
        index[r] = i; //将下标添加进去
    }
    cout << MaxSum;
}