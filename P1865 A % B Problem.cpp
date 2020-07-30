#include<bits/stdc++.h>
#define maxm 1000005

using namespace std;
bool visited[maxm];
int primes[maxm],f=0;

int main()
{
	memset(visited,true,sizeof(visited));
	visited[1]=false;
	int n,m;
	cin>>n>>m;
	for (int i=2;i<maxm;i++)
		if (visited[i]){
			primes[f++]=i;
			for(int j=i+i;j<=maxm;j+=i) visited[j]=false;
		}
	while(n--){
		int l,r;
		cin>>l>>r;
		int ans=0;
		if(l>=1&&l<=r&&r<=m){
			for(int i=l;i<=r;i++)
				if(visited[i]) ans++;
			cout<<ans<<'\n';
		}else cout<<"Crossing the line"<<'\n';
	}
	return 0;
}