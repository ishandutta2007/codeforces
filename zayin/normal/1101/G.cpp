#include<bits/stdc++.h>
#define maxb 60
#define maxn 200050
using namespace std;
typedef long long LL;

int n;

LL a[maxn];
int num[maxb];

int main()
{
    int ans=0;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lld",a+i),a[i]^=a[i-1];
    
    if (!a[n])
        return puts("-1"),0;
    for (int i=n;i;--i)
    {

        LL t=a[i];
        for (int b=maxb-1;~b;--b)
        {
            if (!(t>>b&1))  continue;
            if (num[b])
                t^=num[b];
            else
            {
                ++ans;
                num[b]=t;
                break;
            }
        }
    }
    printf("%d\n",ans);
    
    return 0;
}