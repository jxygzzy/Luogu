#include<bits/stdc++.h>
#define eps 1e-4
using  namespace std;
double x1,x2,x3,a,b,c,d;
double f(double x){return a*x*x*x+b*x*x+c*x+d;}
double df(double x){ return 3*a*x*x+2*b*x+c;}
double slove(double l,double r){
    double x=l,x0=(l+r)/2;
    while (abs(x-x0)>eps)
    {
        x=x0-f(x0)/df(x0);
        swap(x,x0);
    }
    return x;
}
int main()
{
    cin>>a>>b>>c>>d;
    double p=(-b-sqrt(b*b-3*a*c))/(3*a);
    double q=(-b+sqrt(b*b-3*a*c))/(3*a);
    x1=slove(-100,p),x2=slove(p,q),x3=slove(q,100);
    printf("%.2lf %.2lf %.2lf",x1,x2,x3);
    return 0;
}