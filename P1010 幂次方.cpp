#include<bits/stdc++.h>
using namespace std;
int x;
int FastPow(int n){
    int ret=1;
    for(int i=0;i<n;i++)
        ret*=2;
    return ret;
}
void slove(int n){
    if(n==0) return;
    int temp;
    for(int i=0;i<=15;i++){//n<=2e14
        temp=i;
        if(FastPow(i)>n){
            temp--;
            break;
        }
    }
    if(temp==0) cout<<"2(0)";
    if(temp==1) cout<<"2";
    if(temp>1){
        cout<<"2(";
        slove(temp);
        cout<<")";
    }
    if(n!=FastPow(temp)){
        cout<<"+";
        slove(n-FastPow(temp));
    }
}
int main()
{
    cin>>x;
    slove(x);
    return 0;
}