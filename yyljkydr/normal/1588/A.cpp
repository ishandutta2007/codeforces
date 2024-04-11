#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

int a[N],b[N],c[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<=201;i++)
            a[i]=b[i]=c[i]=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a[x+100]++;
        }
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            b[x+100]++;
        }
        int ok=1;
        for(int i=0;i<=201;i++)
        {
            if(a[i]+c[i]==b[i])
                continue;
            if(c[i]>b[i]||a[i]+c[i]<b[i])
            {
                ok=0;
                break;
            }
            c[i+1]+=a[i]+c[i]-b[i];
        }
        puts(ok?"YES":"NO");
    }
}