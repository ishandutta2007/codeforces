#include<bits/stdc++.h>
using namespace std;

const int N=23,M=2e4+1e3+7,P=998244353;

int n;

int cnt[N][26],pw[M];

char s[M];

int f[1<<N];

int mn[26];

int main()
{
    pw[0]=1;
    for(int i=1;i<M;i++)
        pw[i]=pw[i-1]*2%P;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int m=strlen(s);
        for(int j=0;j<m;j++)
            cnt[i][s[j]-'a']++;
    }
    for(int S=1;S<(1<<n);S++)
    {
        for(int j=0;j<26;j++)
            mn[j]=1e9;
        int flag=P-1;
        for(int i=0;i<n;i++)
            if(S&(1<<i))
            {
                flag=P-flag;
                for(int j=0;j<26;j++)
                    mn[j]=min(mn[j],cnt[i][j]);
            }
        f[S]=flag;
        for(int i=0;i<26;i++)
            f[S]=1ll*f[S]*(mn[i]+1)%P;
    }
    for(int i=0;i<n;i++)
        for(int S=0;S<(1<<n);S++)
            if(S&(1<<i))
                f[S]=(f[S]+f[S^(1<<i)])%P;
    long long ans=0;
    for(int S=0;S<(1<<n);S++)
    {
        int b=0,a=0;
        for(int i=0;i<n;i++)
            if(S&(1<<i))
                b++,a+=i+1;
        ans^=1ll*a*b*f[S];
    }
    printf("%lld\n",ans);
}