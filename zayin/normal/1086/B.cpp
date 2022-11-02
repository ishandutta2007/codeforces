#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,s;
int d[maxn];

int main()
{
    scanf("%d%d",&n,&s);
    for (int k=1;k<n;++k)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ++d[u],++d[v];
    }

    if (n==2)
        printf("%d",s);
    else
    {
        int cnt=0;
        for (int i=1;i<=n;++i)
            cnt+=d[i]==1;
        printf("%.9lf\n",2.0*s/cnt);
    }
    return 0;
}