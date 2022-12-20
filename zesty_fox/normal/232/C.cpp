#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=110,FIB=84;
const ll INF=0x3f3f3f3f3f3f3f3f;
int T,n;
ll fib[N];
void init(){
    fib[0]=1,fib[1]=2;
    for(int i=2;i<=FIB;i++) fib[i]=fib[i-1]+fib[i-2];
}

inline pair<ll,ll> pre(int n,ll x,ll edge=INF){
    if(n==0) return mp(0,0);
    if(n==1) return mp(x-1,2-x);
    if(x<=fib[n-1]){
        auto p=pre(n-1,x,2);
        return mp(p.fi,min(p.fi+edge,min(p.fi,p.se)+1+(n-1)/2));
    }
    else{
        auto p=pre(n-2,x-fib[n-1],edge+1);
        return mp(min(p.fi+1,p.se+edge),p.se);
    }
}

inline ll solve(ll n,ll a,ll b,ll edge=INF){
    if(a>b) swap(a,b);
    if(n<=1) return b-a;
    if(b<=fib[n-1]) return solve(n-1,a,b,2);
    else if(a<=fib[n-1]&&b>=fib[n-1]+1){
        auto resa=pre(n-1,a,2),resb=pre(n-2,b-fib[n-1],edge+1);
        return min(min(resa.fi+1,resa.se+1)+resb.fi,resa.fi+resb.se+edge);
    }
    else return solve(n-2,a-fib[n-1],b-fib[n-1],edge+1);
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    T=rdi(),n=rdi();
    n=min(n,FIB);init();
    for(int i=1;i<=T;i++){
        //fprintf(stderr,"\rProcess: %6.2lf%%",100.0*i/T);
        ll a=rdll(),b=rdll();
        printf("%lld\n",solve(n,a,b));
    }
    return 0;
}