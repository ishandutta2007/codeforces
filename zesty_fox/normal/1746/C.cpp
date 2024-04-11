#include <bits/stdc++.h>

using namespace std;

using i64=long long;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=2e5+10;

int n,a[N],res[N];
pii seq[N];
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    int tot=0;
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1]) seq[++tot]={a[i]-a[i+1],i};
    sort(seq+1,seq+tot+1);
    for(int i=tot;i>=1;i--) res[n-(tot-i)]=seq[i].se+1;
    for(int i=1;i<=n;i++){
        if(!res[i]) res[i]=n;
        cout<<res[i]<<' ';
    }
    cout<<'\n';

    fill(res+1,res+n+1,0);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}