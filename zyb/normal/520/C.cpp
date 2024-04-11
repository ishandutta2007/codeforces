#include<stdio.h>
#define P 1000000007
using namespace std;
inline long long quick(int o,int p)
{
    long long oo=o*1ll,pp=p*1ll,ans=1;
    while (pp)
    {
        if (pp&1)
        ans=(ans*oo)%P;
        pp/=2;oo=(oo*oo)%P;
    }
    return ans;
}
int i,j,k,l,s,m,n,f[100005];
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        char c=getchar();
        while (c!='A'&&c!='C'&&c!='G'&&c!='T')
        c=getchar();
        if (c=='A')
        f[1]++;
        if (c=='C')
        f[2]++;
        if (c=='G')
        f[3]++;
        if (c=='T')
        f[4]++;
    }
    int mm=0,tt=0;
    for (i=1;i<=4;i++)
    {
        if (f[i]>mm)
        {
            mm=f[i];
            tt=1;
        }
        else
        if (f[i]==mm)
        tt++;
    }
    printf("%I64d\n",quick(tt,n));
}