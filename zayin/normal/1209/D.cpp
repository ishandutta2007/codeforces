#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,m;

int fa[maxn];

int find(int i) {
    return !fa[i]?i:fa[i]=find(fa[i]);
}

int main()  {
    scanf("%d%d",&n,&m);
    int cnt=0;
    for (int i=1;i<=m;++i)  {
        int u,v;
        scanf("%d%d",&u,&v);
        int fu=find(u),fv=find(v);
        if (fu==fv) 
            ++cnt;
        else    {
            fa[fu]=fv;
        }
    }
    printf("%d\n",cnt);
    return 0;
}