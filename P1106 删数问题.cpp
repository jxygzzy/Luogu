#include<bits/stdc++.h>
using namespace std;
string num;
int k;
int main()
{
	int cnt=0;
	int i=0;
	cin>>num>>k;
	if(num[0]=='1'&&num[1]=='0'&&k==1)
 	{
	   cout<<'0';
	   return 0;
 	}
	while(cnt!=k){
		if(num[i]>num[i+1])
		{
			for(int j=i;j<num.size();j++)
				num[j]=num[j+1];
			i--;
			cnt++;
		}
		else i++;
	}
	int flag=0;
	for(i=0;i<num.size();i++)
	{
		if(num[i]!='0') flag=1,cout<<num[i];
		if(num[i]=='0'&&flag==1) cout<<num[i];
	}
}