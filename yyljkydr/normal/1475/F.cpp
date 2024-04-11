#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int n;

char s[N][N];

int a[N][N],b[N][N];

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=s[i][j]-'0';
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]^=s[i][j]-'0';
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                b[i][j]=a[i][j];
        for(int i=1;i<=n;i++)
            if(b[i][1]==1)
            {
                for(int j=1;j<=n;j++)
                    b[i][j]^=1;
            }
        for(int i=1;i<=n;i++)
            if(b[1][i]==1)
                for(int j=1;j<=n;j++)
                    b[j][i]^=1;
        int ok=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ok|=b[i][j];
        puts(ok?"NO":"YES");
    }
}