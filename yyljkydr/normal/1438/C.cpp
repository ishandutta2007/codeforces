#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int T;

int n,m,a[N][N];

set<int>val;

map<int,vector<int> >px,py;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        val.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]),a[i][j]+=(a[i][j]&1)!=((i+j)&1);
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%d ",a[i][j]);
    }
}