#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,p,q;
	cin>>n;
	for(int i=4;i<=n;i+=2){
		for(int q=2;q<i;q++){
			p=i-q;
			int flag1=1,flag2=1;
			for(int j=2;j<q;j++){
				if(q%j==0){
					flag1=0;
					break;
				}
			}
			if(flag1==0) continue;
			for(int k=2;k<p;k++){
				if(p%k==0){
					flag2=0;
					break;
				}
			}
			if(flag1&&flag2){
				printf("%d=%d+%d\n",i,q,p);
				break;
			}	
		}		
	}
	return 0;
}