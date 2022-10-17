#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T,n,q;

char s[N];

int a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);
        int f=1;
        for(int i=1;i<=n;i++)
        {
            a[i]=a[i-1]+f*(s[i]=='+'?1:-1);
            f*=-1;
        }
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int len=r-l+1;
            if(len&1)
                puts("1");
            else
                puts((a[r]-a[l-1])?"2":"0");
        }
    }
}