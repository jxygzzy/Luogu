#include<bits/stdc++.h>
#define INF 999999
using namespace std;
double d1,c,d2,p;
double max_s,ans,res;
int n;
struct node{
    double s,mon;
}Now[10];
int Solve(int now){
    int flag=INF;
    double d=Now[now].s;
    for(int i=now+1;i<=n&&Now[i].s-d<=max_s;i++){
        if(Now[i].mon<Now[now].mon){
            ans+=((Now[i].s-d-res)/d2)*Now[now].mon;
            res=0;return i;
        }
        if(flag==INF||Now[i].mon<Now[flag].mon) flag=i;
    }
    if(d1-Now[now].s<=max_s){
        ans+=((d1-Now[now].s-res)/d2*Now[now].mon);
        return INF;
    }
    if(flag==INF) {
        cout<<"No Solution\n";
        return -1;
    }else{
        ans+=c*Now[now].mon;
        res+=max_s-(Now[flag].s-d);
        return flag;
    }
}
bool cmp(node a,node b){
    return a.s<b.s;
}
int main()
{
    cin>>d1>>c>>d2>>p>>n;
    Now[0].s=0;
    Now[0].mon=p;
    for(int i=1;i<=n;i++)
        cin>>Now[i].s>>Now[i].mon;
    sort(Now,Now+n,cmp);
    max_s=c*d2;
    int temp,i=0;
    do{
        temp=Solve(i);
        i=temp;
        if(temp==-1) return 0;
    }while(temp!=INF);
    printf("%.2lf", ans);
    return 0;
}
