#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1010;

int h,v;

pair<vi,vi> part(const vi &v){
    int sum=0,siz=v.size();
    static bitset<N*N> bs[N];bs[0][0]=1;
    for(int i=1;i<=siz;i++){
        int x=v[i-1];
        bs[i]=bs[i-1]|(bs[i-1]<<x),sum+=x;
    }
    if((sum&1)||!bs[siz][sum/2]) return {};
    vi a,b;int nw=sum/2;
    for(int i=siz;i>=1;i--){
        int x=v[i-1];
        if(nw>=x&&bs[i-1][nw-x]) nw-=x,a.pb(x);
        else b.pb(x);
    }
    return {a,b};
}

void solve(){
    vi l1,l2;
    h=rdi();for(int i=1;i<=h;i++) l1.pb(rdi());
    v=rdi();for(int i=1;i<=v;i++) l2.pb(rdi());
    if(h!=v) {puts("No");return;}
    vi h1,h2,v1,v2;
    tie(h1,h2)=part(l1),tie(v1,v2)=part(l2);
    if(h1.empty()||v1.empty()) {puts("No");return;}
    bool fl=0;
    if(h1.size()<v1.size()) swap(h1,v1),swap(h2,v2),fl=1;
    int x=0,y=0;
    auto out = [&](){
        if(fl) cout<<y<<' '<<x<<'\n';
        else cout<<x<<' '<<y<<'\n';
    };
    sort(h1.begin(),h1.end());
    sort(h2.begin(),h2.end());
    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end());

    puts("Yes");
    for(int i=0;i<v1.size();i++) y+=v1[i],out(),x+=h1[i],out();
    for(int i=0;i<h1.size()-v1.size();i++) y-=v2[i],out(),x+=h1[i+v1.size()],out();
    for(int i=0;i<h2.size();i++) y-=v2[i+h1.size()-v1.size()],out(),x-=h2[i],out();
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