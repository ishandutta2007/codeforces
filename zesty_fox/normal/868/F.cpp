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

const int N=100010,K=25;
const ll INF=0x3f3f3f3f3f3f3f3f;

int n,k,a[N];
ll f[N][K];

int buc[N],pl=1,pr;
ll sum;
void add(int i) {sum+=buc[a[i]],++buc[a[i]];}
void del(int i) {--buc[a[i]],sum-=buc[a[i]];}

inline ll calc(int i,int j,int k){
    while(pl>j) add(--pl);
    while(pl<j) del(pl++);
    while(pr<i) add(++pr);
    while(pr>i) del(pr--);
    return f[j-1][k-1]+sum;
}

void solve(int k,int l,int r,int L,int R){
    if(l>r) return;
    if(L==R){
        for(int i=l;i<=r;i++) f[i][k]=calc(i,L,k);
        return;
    }
    int mid=(l+r)>>1,p=0;
    ll minx=INF;
    for(int i=L;i<=min(R,mid);i++){
        ll tmp=calc(mid,i,k);
        if(tmp<minx) minx=tmp,p=i;
    }
    f[mid][k]=minx;
    solve(k,l,mid-1,L,p);solve(k,mid+1,r,p,R);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=n;i++) f[i][0]=INF;
    for(int i=1;i<=k;i++) solve(i,1,n,1,n);
    cout<<f[n][k]<<endl;
    return 0;
}