#include<stdio.h>
#include<cmath>
using namespace std;
double a,d,v,t,last;
int n,i;
int main() {
    scanf("%d%lf%lf",&n,&a,&d);
    last=0;
    for (i=1;i<=n;i++) {
        scanf("%lf%lf",&t,&v);
        double tt=(v*1.)/(a*1.)+t;
        double s=v*1.*v*1./(2.*a*1.);
        if (s<=d) tt+=((d-s)/v*1.);
        else tt=sqrt((2.*d/(a*1.)))+t;
        if (tt<last) tt=last;
        printf("%lf\n",tt);
        last=tt;
    }
}