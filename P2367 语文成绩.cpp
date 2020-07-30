#include<bits/stdc++.h>
#define maxn 5000005
using namespace std;
int n,p;
int a[maxn],b[maxn];
int x,y,z,i;
int main(){
	scanf("%d %d",&n,&p);
	for( i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]-a[i-1];
	}
	int minn=maxn;
	while(p--){
		scanf("%d %d %d",&x,&y,&z);
		b[x]+=z;
		b[y+1]-=z;
	}
	for( i=1;i<=n;i++)
		{
			a[i]=b[i]+a[i-1];
			if(minn>a[i]) minn=a[i];
		}
	printf("%d",minn);
	return 0;
}