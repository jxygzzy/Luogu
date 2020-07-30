#include<bits/stdc++.h>
using namespace std;
int Set[1005];
struct code{
    int x,y,z;
}codes[100005];
bool cmp(code a,code b)
{
    return a.z<b.z;
}
int Find(int x){
    return (Set[x]==x) ? x : (Set[x] = Find(Set[x]));
}
void Init(int cnt) { // 初始化并查集，cnt 是元素个数
    for (int i=1; i<=cnt; i++)
        Set[i]=i;
}
int main()
{
    int n,m;
    cin>>n>>m;
    Init(n);
    for(int i=1;i<=m;i++)
        cin>>codes[i].x>>codes[i].y>>codes[i].z;
    sort(codes+1,codes+m+1,cmp);
    int num=0,maxtime=0;
    for(int i=1;i<=m;i++)
    {
        int u=Find(codes[i].x);
        int v=Find(codes[i].y);
        if(u!=v){
            Set[u]=v;
            num++;
            maxtime=max(maxtime,codes[i].z);
        }
        if(num>=n-1){
            cout<<maxtime<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}