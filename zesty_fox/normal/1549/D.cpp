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

const int N=200010;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n;
ll a[N];
ll gcd(ll x,ll y){
    if(!y) swap(x,y);
    return !x?y:gcd(y%x,x);
}

ll gc[N][21],lg2[N];
void init(){
    for(int i=2;i<=N-10;i++) lg2[i]=lg2[i>>1]+1;
}

void init_ST(){
    for(int i=1;i<=n;i++) gc[i][0]=a[i];
    for(int i=1;i<=lg2[n];i++){
        for(int j=1;j<=n-(1<<i)+1;j++){
            gc[j][i]=gcd(gc[j][i-1],gc[j+(1<<(i-1))][i-1]);
        }
    }
}

ll query(int l,int r){
    int k=lg2[r-l+1];
    return gcd(gc[l][k],gc[r-(1<<k)+1][k]);
}

int ans;
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdll();
    for(int i=n;i>=1;i--) a[i]=abs(a[i]-a[i-1]);
    init_ST();ans=0;
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<r){
            int mid=(l+r+1)>>1;
            ll tmp=query(i+1,mid);
            if(tmp!=1) l=mid;
            else r=mid-1;
        }
        ans=max(ans,l-i+1);
    }
    printf("%d\n",ans);
}

int T;
int main(){
    init();
    T=rdi();
    while(T--) solve();
    return 0;
}