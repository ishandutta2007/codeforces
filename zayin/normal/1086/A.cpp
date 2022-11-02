#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n=3;
int pos[maxn];
int x[maxn],y[maxn];

bool cmp(int i,int j)
{
    return x[i]<x[j];
}

int main()
{
    for (int i=0;i<n;++i)
        scanf("%d%d",&x[i],&y[i]),pos[i]=i;
    sort(pos,pos+n,cmp);
    int tx=0,ty=0,uy=-maxn,dy=maxn;
    for (int i=0;i<n;++i)
    {
        uy=max(uy,y[i]);
        dy=min(dy,y[i]);
        for (int j=i;j<n;++j)
            tx=max(tx,abs(x[i]-x[j])),ty=max(ty,abs(y[i]-y[j]));
    }
    int ans=tx+ty+1;
    printf("%d\n",ans);
    for (int j=dy;j<=uy;++j)
        printf("%d %d\n",x[pos[1]],j);
    for (int j=x[pos[0]];j<x[pos[1]];++j)
        printf("%d %d\n",j,y[pos[0]]);
    for (int j=x[pos[2]];j>x[pos[1]];--j)
        printf("%d %d\n",j,y[pos[2]]);
    return 0;
}