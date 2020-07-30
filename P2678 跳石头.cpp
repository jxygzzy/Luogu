#include<bits/stdc++.h>
using namespace std;
int l,n,m;
int lt,rt;
int stone[50005];
int ans;

int main()
{
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>stone[i];
	lt=0;rt=l;
	while(lt<=rt)
	{
		int mid=(lt+rt)/2;
		int now=0,cot=0;
		for(int i=1;i<=n;i++)
			if(stone[i]-stone[now]<mid) cot++;
			else now=i;
		if(cot<=m){
			ans=mid;
			lt=mid+1;
		}else rt=mid-1;
	}
	cout<<ans;
	return 0;
}