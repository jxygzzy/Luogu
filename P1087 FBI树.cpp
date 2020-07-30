#include<bits/stdc++.h>
using namespace std;
string num;
int n;
int FastPow(int n){
    int ret=1;
    for(int i=0;i<n;i++)
        ret*=2;
    return ret;
}
void MakeTree(int x,int y){
    if(x<y)
    {
        MakeTree(x,(x+y)/2);
        MakeTree((x+y)/2+1,y);
    }
    int B=1,I=1;
    for(int i=0;i<=y-x;i++){
        if(num[i+x]=='1') B=0;
        else I=0;
    }
    if(B) cout<<'B';
    else if(I) cout<<'I';
    else cout<<'F';
}
int main(){
    cin>>n>>num;
    MakeTree(0,FastPow(n)-1);
    return 0;
}