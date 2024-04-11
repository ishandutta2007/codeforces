#include<cstdio>
#include<cmath>
double n,m,a,p,s,t,ans,pi=acos(-1.);
int main()
{
    scanf("%lf%lf%lf",&n,&m,&a); if (n>m) t=n,n=m,m=t;
    if (a==90) ans=n*n;
    else{
        ans=n*m,n/=2,m/=2,a>90?a=180-a:a,a*=pi/180,p=(pi-a)/2;
        s=n-m/tan(p),ans-=s*s*tan(a),t=m-n/tan(p),ans-=t*t*tan(a);
        if (s<0) ans=(n/tan(p)+n/tan(a))*n*4;
        }
    printf("%.9lf\n",ans); return 0;
}