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

const int N=100010;
const ll INF=0x3f3f3f3f3f3f3f3f;

int v[N],p[N],pcnt,phi[N];
ll sumphi[N];

void init(int lim){
    v[1]=1,phi[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,p[++pcnt]=i,phi[i]=i-1;}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>lim/i) break;
            v[p[j]*i]=p[j],phi[p[j]*i]=(i%p[j]?phi[i]*(p[j]-1):phi[i]*p[j]);
        }
    }
    for(int i=1;i<=lim;i++) sumphi[i]=sumphi[i-1]+phi[i];
}

ll calc(int l,int r){
    ll ret=0;
    for(int i=l,j;i<=r;i=j+1){
        j=min(r,r/(r/i));
        ret+=sumphi[r/i]*(j-i+1);
    }
    return ret-(r-l+1);
}

ll f[N][20];
void dp(int l,int r,int opl,int opr,int j){
    if(l>r) return;
    if(opl==opr){
        for(int i=l;i<=r;i++)
            f[i][j]=f[opl-1][j-1]+calc(opl,i);
        return;
    }
    int mid=(l+r)>>1,fr;
    ll minx=INF;
    for(int i=opl;i<=min(opr,mid);i++){
        ll tmp=f[i-1][j-1]+calc(i,mid);
        if(tmp<minx) minx=tmp,fr=i;
    }
    f[mid][j]=minx;
    dp(l,mid-1,opl,fr,j);
    dp(mid+1,r,fr,opr,j);
}

void prework(int lim){
    memset(f,0x3f,sizeof(f));f[0][0]=0;
    init(lim);
    for(int j=1;j<=16;j++) dp(j,lim,j,lim,j);
}

int T;
int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    T=rdi();prework(N-10);
    while(T--){
        int n=rdi(),k=rdi();
        printf("%lld\n",(k<=16?f[n][k]:0)+n);
    }
    return 0;
}