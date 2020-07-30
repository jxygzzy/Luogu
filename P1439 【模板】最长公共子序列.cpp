#include<bits/stdc++.h>
using namespace std;
#define maxx 100001
int p1[maxx],p2[maxx];
int f[maxx],Map[maxx];
int n;
int LCS(){
    int len=0;
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=len,mid;
        if(Map[p2[i]]>f[len])f[++len]=Map[p2[i]];
        else 
        {
        while(l<r)
        {   
            mid=(l+r)/2;
            if(f[mid]>Map[p2[i]])r=mid;
            else l=mid+1; 
        }
        f[l]=min(Map[p2[i]],f[l]);
        }
    }
    return len;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p1[i];
        Map[p1[i]]=i;
    }
    for(int i=1;i<=n;i++)
        cin>>p2[i];
    int ans=LCS();
    cout<<ans;
    return 0;
}
