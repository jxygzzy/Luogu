/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-04-30 10:15:37
 * @LastEditTime: 2020-08-03 11:14:16
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\test.cpp
 * @居居 <jxygzzy@163.com>
 */
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long n,bz,s=0,mid,leftt,longest,trees[1000008];
int main()
{
	freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%lld%lld",&n,&bz); 
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&trees[i]);
        longest=max(longest,trees[i]);//找到最长木材 
    }
    while(leftt<=longest)
    {
        mid=(leftt+longest)/2; //从中间点开始作为伐木机高度
        s=0; 
        for(int i=1;i<=n;i++) 
			if(trees[i]>mid) //树的高度大于伐木机高度 
				s+=trees[i]-mid; //高的部分累加 
        if(s<bz) //木材不足 
			longest=mid-1;//在左边搜 减小高度增加木材 
		else 
			leftt=mid+1;//在右边搜 增加高度减小木材 
    }
    cout<<leftt-1; 
    return 0;
}