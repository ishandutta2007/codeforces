#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
typedef double db;
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

const int N=20;

void or_FWT(u64 a[],int n,int typ=1){
    assert(typ==1||typ==-1);
    for(int len=2;len<=n;len<<=1){
        int mid=len/2;
        for(int i=0;i<n;i+=len)
            for(int j=0;j<mid;j++) a[i+j+mid]+=typ*a[i+j];
    }
}

void and_FWT(u64 a[],int n,int typ=1){
    assert(typ==1||typ==-1);
    for(int len=2;len<=n;len<<=1){
        int mid=len/2;
        for(int i=0;i<n;i+=len)
            for(int j=0;j<mid;j++) a[i+j]+=typ*a[i+j+mid];
    }
}


int n;
bool e[N][N];
u64 g[(1<<N)+1][N],f[N][(1<<N)+1];

void init(){
    for(int i=1;i<=n;i++) g[(1<<(i-1))][i]=1;
    for(int i=1;i<(1<<n);i++){
        if(!(i&(i-1))) continue;
        for(int j=1;j<=n;j++){
            if(!(i>>(j-1)&1)) continue;
            for(int k=1;k<=n;k++)
                if(e[k][j]) g[i][j]+=g[i^(1<<(j-1))][k];
        }
    }
    for(int i=1;i<(1<<n);i++)
        for(int j=1;j<=n;j++) f[__builtin_popcount(i)][i]+=g[i][j];
    for(int i=0;i<=n;i++) or_FWT(f[i],(1<<n));
}

u64 calc(int a[],int cnt){
    static u64 h[(1<<N)+1];
    fill_n(h,(1<<n),1);
    for(int i=0;i<cnt;i++)
        for(int j=0;j<(1<<n);j++) h[j]*=f[a[i]][j];
    u64 ret=0;
    for(int i=0;i<(1<<n);i++)
        ret+=(__builtin_parity(((1<<n)-1)^i)?-1:1)*h[i];
    return ret;
}

map<vi,u64> val;
int a[N];
void dfs(int x,int rest,int lst=1){
    if(!rest) {val[vi(a+1,a+x+1)]=calc(a+1,x);return;}
    for(int i=lst;i<=rest;i++) a[x+1]=i,dfs(x+1,rest-i,i);
}

u64 res[(1<<N)+1];
void solve(){
    dfs(0,n);
    for(int s=0;s<(1<<(n-1));s++){
        int len=0;vi b;
        for(int i=0;i<n-1;i++){
            if(!(s>>i&1)) b.pb(len+1),len=0;
            else ++len;
        }
        b.pb(len+1);sort(b.begin(),b.end());
        res[s]=val[b];
    }
    and_FWT(res,1<<(n-1),-1);
    for(int i=0;i<(1<<(n-1));i++) cout<<res[i]<<' ';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++){
        static char s[N];scanf("%s",s+1);
        for(int j=1;j<=n;j++) e[i][j]=s[j]-'0';
    }
    init();solve();
    return 0;
}