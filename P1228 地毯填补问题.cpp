#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll x,y,l;
int k;
void solve(ll x,ll y,ll a,ll b,ll l){//x,y表示这次要填的方格位置; a,b表示这次要填方格的左上角的位置; l表示这次要填方格大小
    if(l==1) return ;
    if(x-a<=l/2-1 && y-b<=l/2-1)
    {
        printf("%lld %lld 1\n",a+l/2,b+l/2);
        solve(x,y,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else if(x-a<=l/2-1 && y-b>l/2-1)
    {
        printf("%lld %lld 2\n",a+l/2,b+l/2-1);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(x,y,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else if(x-a>l/2-1 && y-b<=l/2-1)
    {
        printf("%lld %lld 3\n",a+l/2-1,b+l/2);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(x,y,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else
    {
        printf("%lld %lld 4\n",a+l/2-1,b+l/2-1);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(x,y,a+l/2,b+l/2,l/2);
    }
}
int main()
{
    cin>>k>>x>>y;
    l=pow(2,k);
    solve(x,y,1,1,l);
    return 0;
}