#include<bits/stdc++.h>
using namespace std;

const int N=57;

int T;

int n,m,r,c;

char s[N][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&r,&c);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        bool ok=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s[i][j]=='B')
                    ok=1;
        if(!ok)
        {
            puts("-1");
            continue;
        }
        int cr=0,cc=0;
        for(int j=1;j<=m;j++)
            cr+=s[r][j]=='B';
        for(int i=1;i<=n;i++)
            cc+=s[i][c]=='B';
        if(s[r][c]=='B')
            puts("0");
        else if(!cr&&!cc)
            puts("2");
        else
            puts("1");
    }
}