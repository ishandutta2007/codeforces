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

const int N=50010,MOD=1e9+7;
const int M=N*32,L=30;

int a[N],n;
i64 m;

int sum[N][L+2];

// calculate \sum_{i=l}^r {val \xor a_i}
i64 query_xor(int l,int r,int val){
    if(l>r) return 0;
    i64 ret=0;
    for(int i=0;i<=L;i++){
        int cnt=sum[r][i]-sum[l-1][i];
        ret+=((i64)(val>>i&1?(r-l+1-cnt):cnt))<<i;
    }
    return ret;
}

struct Trie{
    int ch[M][2],siz[M],tot;
    Trie(){
        memset(ch,0,sizeof(ch));
        memset(siz,0,sizeof(siz));
        tot=1;
    }
    void insert(int val){
        int nw=1;
        for(int i=L;i>=0;i--){
            siz[nw]++;
            int cur=val>>i&1;
            if(!ch[nw][cur]) ch[nw][cur]=++tot;
            nw=ch[nw][cur];
        }
        siz[nw]++;
    }
    // count x xor val >= lim.
    int query_c(int nw,int val,int lim,int dep=L){
        if(!nw) return 0;
        if(dep<0) return siz[nw];
        if(lim>>dep&1) return query_c(ch[nw][(val>>dep&1)^1],val,lim,dep-1);
        else return siz[ch[nw][(val>>dep&1)^1]]+query_c(ch[nw][val>>dep&1],val,lim,dep-1);
    }
    i64 query_sum(int nw,int val,int lim,int dep=L,int rk=0){
        if(!nw) return 0;
        if(dep<0) return query_xor(rk+1,rk+siz[nw],val);
        if(lim>>dep&1){
            if(!(val>>dep&1)) rk+=siz[ch[nw][0]];
            return query_sum(ch[nw][(val>>dep&1)^1],val,lim,dep-1,rk);
        }
        else{
            if(val>>dep&1) return query_xor(rk+1,rk+siz[ch[nw][0]],val)+query_sum(ch[nw][1],val,lim,dep-1,rk+siz[ch[nw][0]]);
            else return query_sum(ch[nw][0],val,lim,dep-1,rk)+query_xor(rk+siz[ch[nw][0]]+1,rk+siz[nw],val);
        }
    }
}t;

void init(){
    n=rdi(),m=rdi64();
    for(int i=1;i<=n;i++) a[i]=rdi();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        t.insert(a[i]);
        for(int j=0;j<=L;j++)
            sum[i][j]=sum[i-1][j]+(a[i]>>j&1);
    }
}

i64 count(int lim){
    i64 ret=0;
    for(int i=1;i<=n;i++) ret+=t.query_c(1,a[i],lim);
    return ret;
}

i64 query_sum(int lim){
    i64 ret=0;
    for(int i=1;i<=n;i++) ret+=t.query_sum(1,a[i],lim);
    return ret;
}

void solve(){
    m*=2;
    int l=0,r=INT_MAX;
    while(l<r){
        int mid=l+(r-l)/2;
        if(count(mid)>=m) l=mid+1;
        else r=mid;
    }
    i64 ans=(query_sum(l)+(i64)(l-1)*(m-count(l)))/2;
    ans%=MOD;cout<<ans<<endl;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init();solve();
    return 0;
}