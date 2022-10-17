#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n,x,deg[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&x);
        fill(deg+1,deg+n+1,0);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            deg[u]++;deg[v]++;
        }
        if(deg[x]<=1)
        {
            puts("Ayush");
        }
        else
            puts(n&1?"Ashish":"Ayush");
    }
}