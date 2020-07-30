#include<bits/stdc++.h>

using namespace std;

int n,r,m=0;
int num[5005][5005];

int main()
{
	cin>>n>>r;
	for(int i=0;i<n;i++){
		int x,y,v;
		cin>>x>>y>>v;
		num[x+1][y+1]=v;
	}
	for(int x=1;x<=5001;x++)
		for (int y=1;y<=5001;y++)
			num[x][y]+=num[x-1][y]+num[x][y-1]-num[x-1][y-1];
	for (int x=0;x<=5001-r;x++)
		for (int y=0;y<=5001-r;y++)
			if (m<num[x+r][y+r]-num[x][y+r]-num[x+r][y]+num[x][y])
				m=num[x+r][y+r]-num[x][y+r]-num[x+r][y]+num[x][y];
	cout<<m;
	return 0;
}