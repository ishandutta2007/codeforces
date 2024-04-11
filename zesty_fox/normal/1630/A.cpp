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

const int N=100010;

int n,k,ma[N];

void swapp(int i,int j){
    swap(ma[ma[i]],ma[ma[j]]);
    swap(ma[i],ma[j]);
}

void solve(){
    n=rdi(),k=rdi();int len=__lg(n);
    if(n==4&&k==3) return (void)puts("-1");
    for(int i=0;i<n;i++) ma[i]=(n-1)^i;
    static int bit[N],cnt;cnt=0;
    for(int i=0;i<len;i++) 
        if(k>>i&1) bit[++cnt]=i;
    if(cnt&1) swapp(0,1<<bit[1]);
    for(int i=1+(cnt&1);i<=cnt;i+=2) swapp(1<<bit[i],1<<bit[i+1]);
    for(int i=0;i<n;i++) if(i<ma[i]) cout<<i<<' '<<ma[i]<<'\n';
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