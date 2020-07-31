/*** 
 * @Author: P19Y0UN9_居居
 * @Date: 2020-04-30 10:15:37
 * @LastEditTime: 2020-07-30 18:30:31
 * @LastEditors: P19Y0UN9_居居
 * @Description: 
 * @FilePath: \Luogu\test.cpp
 * @居居 <jxygzzy@163.com>
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
// long long int cnt[120]; //记录 各个字母实际值
// int first[120];			//记录曾经出现过在第一个位置的字母
int record[10];
int n;
char s[8];
struct Node
{
	int cnt;
	int flag; //1是可以在第一位，0是不可以
	int num;
} a[11];
bool cmp(struct Node a, struct Node b)
{
	return a.cnt > b.cnt;
}
int Pow(int a, int b)
{
	int ret = 1;
	for (int i = 1; i <= b; i++)
		ret *= a;
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= 10; i++)
		a[i].num = i;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		a[s[0]-'a'+1].flag=0;
		int len = strlen(s);
		for (int j = 0; s[j]; j++)
		{
			a[s[j]-'a'+1].cnt += Pow(10, len - j); //加“权”;
		}
	}
	//	for(int i='a';i<'z';i++)
	//		if(a[i].cnt)
	//			cout<<a[i].ch<<"      "<<a[i].cnt<<endl;
	for (int i = 0; i < 10; i++)
		record[i] = 1; //初始化，表示还没被用
	sort(a, a + 11, cmp);
	int sum = 0;

	for (int i = 0; a[i].cnt; i++)
	{
		for (int j = 0; j < 10; j++)
			if (record[j] && j == 0 && a[i].flag)
			{
				sum += a[i].cnt * j;
				record[j] = 0;
				//					cout<<a[i].ch<<" "<<j<<endl;
				break;
			}
			else if (record[j] && j != 0)
			{
				sum += a[i].cnt * j;
				record[j] = 0;
				//					cout<<a[i].ch<<" "<<j<<endl;
				break;
			}
	}
	cout << sum;
	return 0;
}