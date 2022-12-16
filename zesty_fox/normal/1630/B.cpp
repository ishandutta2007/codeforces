#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;

int n,k,a[N],cnt[N],L,R;
vector<pii> res;

void clear(){
    for(int i=1;i<=n;i++) cnt[i]=0;
    res.clear();
}

void solve(){
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),cnt[a[i]]++;
    
    int sum=0;
    for(int i=1;i<=n;i++) sum-=cnt[i];

    L=0,R=n+1;
    for(int l=1,r=1;l<=n;l++){
        while(r<=n&&sum<k) sum+=2*cnt[r++];
        if(sum>=k&&R-L>r-l-1) L=l,R=r-1;
        sum-=2*cnt[l];
    }
    sum=0;int last=0;
    for(int i=1;i<=n;i++){
        sum+=(L<=a[i]&&a[i]<=R)?1:-1;
        if(sum>=1) res.pb({last+1,i}),last=i,sum=0;
    }
    
    while(res.size()>k) res.pop_back();
    res.back().se=n;
    cout<<L<<' '<<R<<'\n';
    for(auto tmp:res) cout<<tmp.fi<<' '<<tmp.se<<'\n';
    clear();
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