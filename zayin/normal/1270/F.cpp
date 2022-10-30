#include<bits/stdc++.h>
#define maxn 200050
#define maxm 505
using namespace std;
typedef long long LL;

int n,m;
char s[maxn];

int cnt[maxn];
int sum[maxn*maxm];

int L[maxn],R[maxn];

int main()  {
    scanf("%s",s+1),n=strlen(s+1);
    m=sqrt(n)+5;
    for (int i=1;i<=n;++i)
        cnt[i]=cnt[i-1]+(s[i]=='1');
    
    for (int i=0,j=0;i<=n;i=j)  {
        while (j<=n&&cnt[i]==cnt[j]) ++j;
        L[cnt[i]]=i,R[cnt[i]]=j;
    }

    LL ans=0;
    for (int k=1;k<=m;++k)  {
        for (int i=0;i<=n;++i)  
            ans+=(sum[k*cnt[i]-i+n]++);
        for (int i=0;i<=n;++i)
            --sum[k*cnt[i]-i+n];
    }

    for (int i=0;i<=n;++i)  {
        for (int c=1;c<=m;++c)  {
            int l=max(i+m*c+1,L[cnt[i]+c]),r=R[cnt[i]+c];
            if (l>=r) continue;
            auto calc=[&](int n,int r,int m)    {
                r%=m;
                return (m-r+n)/m;
            };
            ans+=calc(r-1,i,c)-calc(l-1,i,c);
        }
    }

    printf("%lld\n",ans);
    return 0;
}