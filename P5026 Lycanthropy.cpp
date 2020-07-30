#include<bits/stdc++.h>
using namespace std;
int n,m;
int v,x;
int aa[3000000],bb[3000000];
int main(){
	cin>>n>>m;
	int *a=aa+1000000;
	int *b=bb+1000000;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>x;
		a[x-3*v+1]++;
        a[x-2*v+1]-=2;
        a[x+1]+=2;
        a[x+2*v+1]-=2;
        a[x+3*v+1]++;
	}
	for(int i=-30000;i<=m+30000;i++) a[i]+=a[i-1],b[i]+=b[i-1]+a[i];
	for(int i=1;i<=m;++i) cout<<b[i]<<' ';
	return 0;
}