#include<bits/stdc++.h>
#define maxn 5050
using namespace std;
typedef long long LL;

int n;
LL x[maxn],y[maxn];

bool vis[maxn];

LL sq(LL x) {
    return x*x;
}

LL dis2(int i,int j)    {
    return sq(x[i]-x[j])+sq(y[i]-y[j]);
}

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lld%lld",x+i,y+i);
    
    int j=1;
    for (int t=1;t<=n;++t)   {
        vis[j]=1;
        printf("%d ",j);

        int k=j;
        for (int i=1;i<=n;++i)
            if (!vis[i]&&dis2(i,j)>=dis2(k,j))
                k=i;
        j=k;
    }
    return 0;
}