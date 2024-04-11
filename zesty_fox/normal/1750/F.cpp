// LUOGU_RID: 93636577
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=5010;

int n,MOD;
i64 f[N],g[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),MOD=rdi();
    g[1]=g[2]=1;
    for(int i=3;i<=n;i++) g[i]=g[i-1]*2%MOD;
    f[3]=f[4]=1;
    for(int i=5;i<=n;i++){
        i64 sum=0;
        for(int j=2;j<=i;j+=2) sum+=f[i-j]*g[j/2]%MOD;
        sum%=MOD;
        g[i]=(g[i]+MOD-sum)%MOD;

        if(i&1) f[i]=g[(i-1)/2];
        f[i]+=f[i-1];
        for(int j=4;j<=i;j+=3) f[i]+=f[i-j]*g[(j-1)/3]%MOD;
        f[i]%=MOD;
    }
    cout<<g[n]<<endl;
    return 0;
}