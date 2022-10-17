#include<bits/stdc++.h>
using namespace std;

#define double long double

const double eps=1e-10;

int T;

double c,m,p,v;

double f(double i,double j,double k)
{
    double ret=1;
    double ni,nj,nk;
    if(i>eps)
    {
        double dlt=min(i,v);
        ni=i<v?0:i-v;
        if(j>eps)
            nj=j+dlt/2,nk=k+dlt/2;
        else
            nj=j,nk=k+dlt;
        ret+=f(ni,nj,nk)*i;
    }
    if(j>eps)
    {
        double dlt=min(j,v);
        nj=j<v?0:j-v;
        if(i>eps)
            ni=i+dlt/2,nk=k+dlt/2;
        else
            ni=i,nk=k+dlt;
        ret+=f(ni,nj,nk)*j;
    }
    return ret;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%Lf%Lf%Lf%Lf",&c,&m,&p,&v);
        printf("%.10Lf\n",f(c,m,p));
    }
}