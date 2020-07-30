#include<bits/stdc++.h>
using namespace std;
int n,m;
int l,r,a[100005],mid,ans;
bool check(int maxx){
	int cnt=1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>maxx) return false;
		if(sum+a[i]>maxx){
			cnt++;
			sum=a[i];
		}else sum+=a[i];
	}
	if(cnt>m) return false;
	else return true;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		l=min(l,a[i]);
		r+=a[i];
	}
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}