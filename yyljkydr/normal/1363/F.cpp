#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int T,n;

char s[N],t[N];

int f[N][N],ps[N][26],pt[N][26];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        for(int i=0;i<26;i++)
            ps[n+1][i]=pt[n+1][i]=0;
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<26;j++)
                ps[i][j]=ps[i+1][j]+(s[i]-'a'==j),
                pt[i][j]=pt[i+1][j]+(t[i]-'a'==j);
        }
        bool ok=1;
        for(int i=0;i<26;i++)
            ok&=ps[1][i]==pt[1][i];
        if(!ok)
        {
            puts("-1");
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                f[i][j]=max({f[i-1][j],f[i][j-1]});
                bool ok=1;
                for(int k=0;k<26;k++)
                    ok&=ps[i][k]>=pt[j][k];
                if(s[i]==t[j]&&ok)
                    f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            }
        printf("%d\n",n-f[n][n]);
    }
}