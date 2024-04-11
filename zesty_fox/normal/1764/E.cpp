// LUOGU_RID: 96111251
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

const int N=1e5+10;

int n,k;
pii p[N];

void solve(){
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) p[i].fi=rdi(),p[i].se=rdi();
    if(p[1].fi>=k) {puts("YES");return;}
    if(p[1].fi+p[1].se<k) {puts("NO");return;}
    
    sort(p+2,p+n+1,[&](pii a,pii b){return a.fi+a.se>b.fi+b.se;});
    int pos=2,nw=k-p[1].se,cnt=0;
    while(true){
        while(pos<=n&&p[pos].fi+p[pos].se>=nw) ++pos,++cnt;
        if(!cnt) {puts("NO");return;}
        else if(cnt>1||p[pos-1].fi>=nw) {puts("YES");return;}
        else nw-=p[pos-1].se,--cnt;
    }
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}