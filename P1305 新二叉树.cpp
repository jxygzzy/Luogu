#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    cin>>n>>s;
    for(int i=2;i<=n;i++)
    {
        string now;
        cin>>now;
        int pos=s.find(now[0]);
        s.erase(pos,1);
        s.insert(pos,now);
    }
    for(int i=0;i<s.size();i++)
        if(s[i]!='*') cout<<s[i];
    return 0;
}