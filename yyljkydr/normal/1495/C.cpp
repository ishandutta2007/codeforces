#include<bits/stdc++.h>
using namespace std;

const int N=5e2+1e1+7;

int T,n,m;

char s[N][N],ans[N][N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            ans[i][m+1]=0;
        for(int i=1;i<=n;i+=3)
            for(int j=1;j<=m;j++)
                ans[i][j]='X';
        for(int i=2;i<=n;i+=3)for(int j=1;j<=m;j++)
            ans[i][j]=s[i][j];
        for(int i=3;i<=n;i+=3)for(int j=1;j<=m;j++)
            ans[i][j]=s[i][j];
        for(int i=1;i<=n;i+=3)
        {
            if(i+3<=n)
            {
                bool fd=0;
                for(int j=1;j<=m;j++)
                    if(ans[i+1][j]=='X'||ans[i+2][j]=='X')
                    {
                        fd=1;
                        ans[i+1][j]='X';
                        ans[i+2][j]='X';
                        break;
                    }
                if(!fd)
                    ans[i+1][m]=ans[i+2][m]='X';
            }
            else
            {
                if(i+2<=n)
                    for(int j=1;j<=m;j++)
                        if(ans[i+2][j]=='X')
                            ans[i+1][j]='X';
            }
        }
        for(int i=1;i<=n;i++)
            puts(ans[i]+1);
    }
}