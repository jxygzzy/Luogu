#include<bits/stdc++.h>
using namespace std;
struct node{
	int w,s;
}a[500005];
bool cmp(node a,node b){
	return a.w+a.s<b.w+b.s;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].w>>a[i].s;
	sort(a,a+n,cmp);
	int all=0,ans=-1e9;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,all-a[i].s);
		all+=a[i].w;
	}
	cout<<ans;
	return 0;
}