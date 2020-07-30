#include<bits/stdc++.h>
using namespace std;
void first(string second,string third){
    if(second.size()>0){
        char ch=third[third.size()-1];
        cout<<ch;
        int pos=second.find(ch);
        first(second.substr(0,pos),third.substr(0,pos));
        first(second.substr(pos+1),third.substr(pos,second.size()-pos-1));
    }
    return;
}
int main(){
    string second,third;
    cin>>second>>third;
    first(second,third);
    return 0;
}