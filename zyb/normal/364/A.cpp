#include<stdio.h>
#include<cstring>
using namespace std;
char c[100005];
int i,j,k,l,s,m,n,a;
long long ans;
long long b[100005],f[4005*9];
int main()
{
    scanf("%d",&a);
    scanf("%s",c);
    int l=strlen(c);
    for (i=0;i<l;i++)
    b[i+1]=int(c[i])-48;
    long long uu=0,pp=0;
    for (i=1;i<=l;i++)
    {
        s=0;
        for (j=i;j<=l;j++)
        {
            s+=b[j];
            if (s==0)
            uu++;
            else pp++;
            f[s]++;
        }
    }
    if (a==0)
    {
        ans=uu*pp*2ll+1ll*uu*uu;
        printf("%I64d\n",ans);
        return 0;
    }
    for (i=1;i*i<=a;i++)
    {
        if (a/i<=4000*9)
        if (!(a%i))
        {
            if (i*i!=a)
            ans=ans+2ll*(f[i]*f[a/i]);
            else
            ans=ans+1ll*(f[i]*(f[i]));
        }
    }
    printf("%I64d\n",ans);
}