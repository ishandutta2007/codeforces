#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010,MOD=998244353;

int n,x[N],y[N],s[N];
ll g[N],sum[N],ans;

int main(){
    n=rdi();
    for(int i=1;i<=n;i++){
        x[i]=rdi(),y[i]=rdi(),s[i]=rdi();
        int pre=lower_bound(x+1,x+i,y[i])-x;
        g[i]=(x[i]-y[i]+sum[i-1]+MOD-sum[pre-1])%MOD;
        sum[i]=(sum[i-1]+g[i])%MOD;
        ans=(ans+s[i]*g[i])%MOD;
    }
    ans=(ans+x[n]+1)%MOD;
    cout<<ans<<endl;
    return 0;
}