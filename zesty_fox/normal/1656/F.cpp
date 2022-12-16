#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=2e5+10;
const i64 INFl=LONG_LONG_MAX;

int n;
i64 a[N];

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    sort(a+1,a+n+1);
    i64 k=0,b=0,res=-INFl;
    for(int i=1;i<n;i++) k+=a[i]+a[n],b+=a[i]*a[n];
    if(k<0) {puts("INF");return;}
    res=max(res,(-a[n-1])*k+b);
    for(int i=n-1;i>=2;i--){
        k-=a[i]+a[n],b-=a[i]*a[n];
        k+=a[i]+a[1],b+=a[i]*a[1];
        if(k>0) res=max(res,(-a[i-1])*k+b);
        else if(i>2) res=max(res,(-a[i-2])*k+b);
    }
    if(k>0) {puts("INF");return;}
    else res=max(res,-a[2]*k+b);
    cout<<res<<'\n';
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