#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7,P=998244353,iv2=(P+1)/2;

int n,m,f[N];

string s[N];

vector<int>d[N],r[N];

int calc(int x)
{
    if(!x)
        return 0;
    return (1ll*f[x-1]*iv2%P+f[x]-f[x-1]+P)%P;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n+1;i++)
        d[i].resize(m+2),
        r[i].resize(m+2),
        s[i].resize(m+2);
    for(int i=1;i<=n;i++)
    {
        string t;
        cin>>t;
        for(int j=1;j<=m;j++)
            s[i][j]=t[j-1];
    }
    for(int i=0;i<=n;i++)
        s[i][0]=s[i][m+1]='*';
    for(int j=0;j<=m;j++)
        s[0][j]=s[n+1][j]='*';
    f[0]=0; 
    for(int i=1,j=iv2;i<=max(n,m);i++,j=1ll*j*iv2%P)
        f[i]=(f[i-1]+1ll*i/2*j%P)%P;
    int ans=0;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
        {
            d[i][j]=s[i][j]=='*'?0:d[i+1][j]+1;
            r[i][j]=s[i][j]=='*'?0:r[i][j+1]+1;
            ans=(ans+1ll*calc(d[i][j])*(s[i-1][j]=='*'?1:iv2)%P)%P;
            ans=(ans+1ll*calc(r[i][j])*(s[i][j-1]=='*'?1:iv2))%P;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='o')
                ans=1ll*ans*2%P;
    printf("%d\n",ans);
}