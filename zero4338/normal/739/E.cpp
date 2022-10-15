#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=2e3+5;
const double eps=1e-10;
int n,a,b;
double p[maxn],u[maxn];
double f[maxn];int numa[maxn],numb[maxn];
void check(double x,double y)
{
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];numa[i]=numa[i-1];numb[i]=numb[i-1];
        if(f[i]<f[i-1]+p[i]-x){f[i]=f[i-1]+p[i]-x;numa[i]=numa[i-1]+1;numb[i]=numb[i-1];}
        if(f[i]<f[i-1]+u[i]-y){f[i]=f[i-1]+u[i]-y;numa[i]=numa[i-1];numb[i]=numb[i-1]+1;}
        if(f[i]<f[i-1]+p[i]+u[i]-x-y-p[i]*u[i]){f[i]=f[i-1]+p[i]+u[i]-x-y-p[i]*u[i];numa[i]=numa[i-1]+1;numb[i]=numb[i-1]+1;}
    }
}
int main()
{
    n=read();a=read();b=read();
    for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
    for(int i=1;i<=n;i++)scanf("%lf",&u[i]);
    double al=0,ar=1,amid,bl=0,br=2,bmid;   
    while(ar-al>eps)
    {
        amid=(al+ar)/2;
        bl=0,br=1;
        while(br-bl>eps)
        {
            bmid=(bl+br)/2;
            check(amid,bmid);
            if(numb[n]>b)bl=bmid;
            else br=bmid;
        }
        check(amid,br);
        if(numa[n]>a)al=amid;
        else ar=amid;
    }
    bl=0,br=1;
    while(br-bl>eps)
    {
        bmid=(bl+br)/2;
        check(ar,bmid);
        if(numb[n]>b)bl=bmid;
        else br=bmid;
    }
    check(ar,br);
    printf("%lf",f[n]+a*amid+b*bmid);
    return 0;
}