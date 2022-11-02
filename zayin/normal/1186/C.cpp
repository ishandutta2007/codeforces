#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

int n,m;
char s[maxn],t[maxn];

int f[maxn];

int main()  {
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1),m=strlen(t+1);

    int cnt=0;
    for (int i=1;i<m;++i)
        if (t[i]!=t[i+1])
            cnt^=1;
    for (int i=1;i<=m;++i)
        f[1]^=(s[i]!=t[i]);
    for (int i=1;i<=n-m;++i)
        f[i+1]=f[i]^cnt^(s[i+m]!=t[m])^(s[i]!=t[1]);
    int ans=0;
    for (int i=1;i<=n-m+1;++i)
        // cout<<i<<":"<<f[i]<<endl,
        ans+=!f[i];
    cout<<ans<<endl;
    return 0;
}