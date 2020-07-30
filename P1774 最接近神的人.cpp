/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-07-30 09:34:02
 * @LastEditTime: 2020-07-30 10:34:33
 * @LastEditors: P19Y0UN9_居居
 * @Description: 归并排序，分治，递归实现
 * @FilePath: \Luogu\P1774 最接近神的人.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#define maxn 500005
using namespace std;

int a[maxn];
long long n, ans;
int temp[maxn];

void merge(long long l, long long r, long long mid)
{
    long long i = l;       // 初始化i, 左边有序序列的初始索引
    long long j = mid + 1; //初始化j, 右边有序序列的初始索引
    long long t = l;       // 指向temp数组的当前索引

    //(一)
    //先把左右两边(有序)的数据按照规则填充到temp数组
    //直到左右两边的有序序列，有一边处理完毕为止
    while (i <= mid && j <= r)
    { //继续
        //如果左边的有序序列的当前元素，小于等于右边有序序列的当前元素
        //即将左边的当前元素，填充到temp数组
        //然后 t++, i++
        if (a[i] <= a[j])
        {
            temp[t] = a[i];
            t++;
            i++;
        }
        else
        { //反之,将右边有序序列的当前元素，填充到temp数组
            temp[t] = a[j];
            t++;
            j++;
            ans += (j - t);
        }
    }

    //(二)
    //把有剩余数据的一边的数据依次全部填充到temp
    while (i <= mid)
    { //左边的有序序列还有剩余的元素，就全部填充到temp
        temp[t] = a[i];
        t++;
        i++;
    }
    while (j <= r)
    { //右边的有序序列还有剩余的元素，就全部填充到temp
        temp[t] = a[j];
        t++;
        j++;
    }
    long long tempLeft = l;
    t=l;
    while (tempLeft <= r)
    {
        a[tempLeft] = temp[t];
        t++;
        tempLeft++;
    }
}

void merge_sort(long long l, long long r)
{ //先分后合
    if (l == r)
        return;
    if (l < r)
    {
        long long mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, r, mid);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    cout << ans;
}