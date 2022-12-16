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

const int N=200010;

int n,m,a[N],l[N];
i64 ans;
void solve(){
    n=rdi(),m=rdi();
    for(int i=0;i<m;i++) a[i]=rdi()-1;
    sort(a,a+m);
    for(int i=0;i<m;i++) l[i]=(a[(i+1)%m]+n-a[i]-1)%n;
    sort(l,l+m);ans=0;
    int ti=0;
    for(int i=m-1;i>=0;i--){
        if(l[i]-ti*2-1>1) ans+=l[i]-ti*2-1,ti+=2;
        else if(l[i]<=2*ti) continue;
        else ans++,ti++;
    }
    cout<<n-ans<<'\n';
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