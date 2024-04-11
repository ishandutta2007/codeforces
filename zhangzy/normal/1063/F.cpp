#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC target("arch=corei7-avx")
#include<bits/stdc++.h>
using namespace std;

const int bas=31, mod=7000007;

int n, a[505000];
bitset<505000>f, g;
char s[505000];
bitset<mod+2>ok;

int main(){
    cin>>n>>s+1; reverse(s+1,s+n+1);
    for (int i=1;i<=n;++i) f[i]=1, s[i]-='a'-1;
    int ans=0;
    for (;ans<=1000;){
        
        g.reset(); ok.reset(); ok[0]= ans==0;
        for (int i=1;i<=n-ans;++i){
            if (ok[a[i]]||ok[a[i+1]]) g[i]=1;
            if (i>=ans&&f[i-ans+1]) ok[a[i-ans+1]]=1;
        }
        if (!g.count()) return printf("%d\n",ans), 0;
        
        f=g; ++ans;
        
        for (int i=1;i<=n;++i)
            a[i]=(s[i]+(long long)a[i+1]*bas)%mod;
    }
}