#include<iostream>
#include<cstdio>
using namespace std;
const double eps=1e-9;
int n,k,a[100001]={},max_a=0;
void init()
{   
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
    {   
        scanf("%d",&a[i]);
        if(a[i]>max_a)
            max_a=a[i];
    }
}
bool check(double bar)
{   
    double x=0;
    for(int i=1;i<=n;++i)
        if(a[i]>bar)
            x+=(a[i]-bar)*(100-k)/100;
        else
            x-=bar-a[i];
    return x>=0;
}
void work()
{   
    double l=0,r=max_a;
    while(l+eps<r)
    {   
        double mid=(l+r)/2;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%.9lf\n",l);
}
int main()
{   
    init();
    work();
    return 0;
}