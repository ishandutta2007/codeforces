#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,f[N],a[N],b[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            b[i]=b[i-1]^a[i];
        f[0]=0;
        map<int,int>mn;
        mn[0]=0;
        for(int i=1;i<=n;i++)
        {
            f[i]=f[i-1]+1;
            if(mn.count(b[i]))
                f[i]=min(f[i],i+mn[b[i]]-1);
            if(mn.count(b[i]))
            {
                mn[b[i]]=min(mn[b[i]],f[i]-i);
            }
            else
                mn[b[i]]=f[i]-i;
        }
        printf("%d\n",f[n]);
    }
}