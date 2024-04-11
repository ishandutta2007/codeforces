#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int p[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        if(a+b>n-2)
        {
            printf("-1\n");
            continue;
        }
        if(a==b-1)
        {
            for(int i=1;i<=b;i++)
                p[2*i-1]=i+b,p[2*i]=i;
            for(int i=2*b+1;i<=n;i++)
                p[i]=i;
        }
        else if(a==b)
        {
            for(int i=1;i<=a+1;i++)
                p[2*i-1]=i,p[2*i]=i+a+1;
            for(int i=2*a+3;i<=n;i++)
                p[i]=i;
        }
        else if(a==b+1)
        {
            for(int i=1;i<=a;i++)
                p[2*i-1]=n+1-i-a,p[2*i]=n+1-i;
            for(int i=2*a+1;i<=n;i++)
                p[i]=n+1-i;
        }
        else
        {
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n;i++)
            printf("%d%c",p[i]," \n"[i==n]);
    }
    return 0;
}