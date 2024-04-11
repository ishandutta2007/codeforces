#include<bits/stdc++.h>
#define maxn 505
using namespace std;

int n,m;
int a[maxn][maxn];

int cnt(int i,int j)    {
    int ans=0;
    for (int dx=-1;dx<=1;++dx)
        for (int dy=-1;dy<=1;++dy)  {
            int c=bool(dx)+bool(dy);
            if (c!=1) continue;

            int x=i+dx,y=j+dy;
            if (x<=0||x>n||y<=0||y>m) continue;
            ++ans;
        }
    return ans;
}

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                scanf("%d",&a[i][j]);
        bool flag=1;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                flag&=(a[i][j]<=cnt(i,j));
        if (!flag)
            puts("NO");
        else   {
            puts("YES");
            for (int i=1;i<=n;++i)  {
                for (int j=1;j<=m;++j)
                    printf("%d ",cnt(i,j));
                puts("");
            }
        }
    }
    return 0;
}