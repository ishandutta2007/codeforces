#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int c[2][2];

int T,n,m;

char s[N][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(c,0,sizeof(c));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s[i][j]=='R')
                    c[0][(i+j)&1]++;
                else if(s[i][j]=='W')
                    c[1][(i+j)&1]++;
        int ok=1;
        if(c[0][0]&&c[0][1])
            ok=0;
        if(c[1][0]&&c[1][1])
            ok=0;
        if(c[0][0]&&c[1][0])
            ok=0;
        if(c[0][1]&&c[1][1])
            ok=0;
        puts(ok?"YES":"NO");
        if(ok)
        {
            int k=c[0][1]||(!c[1][1]&&!c[0][0]);
            for(int i=1;i<=n;i++,puts(""))
                for(int j=1;j<=m;j++)
                    if(((i+j)&1)==k)
                        putchar('R');
                    else
                        putchar('W');
        }
    }
}