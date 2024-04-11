#include<stdio.h>
using namespace std;
long long ans;
int i,j,k,l,s,m,n;
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&j);
        ans=ans+1ll*(j-1)*i+1ll;
    }
    printf("%I64d\n",ans);
}