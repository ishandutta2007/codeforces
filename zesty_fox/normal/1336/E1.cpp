// LUOGU_RID: 96293096
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

const int M=55,MOD=998244353;

int n,m;

int rk;
i64 b[M];
void ins(i64 v){
    for(int i=0;i<m;i++)
        if(v>>i&1){
            if(!b[i]){
                b[i]=v,++rk;
                return;
            }
            else v^=b[i];
        }
}

void sort(){
    for(int i=0,c=0;i<m;i++){
        if(b[i]){
            for(int j=0;j<m;j++)
                if((b[j]>>i&1)^(b[j]>>c&1))
                    b[j]^=(1ll<<i)|(1ll<<c);
            swap(b[i],b[c]),++c;
        }
    }
    for(int i=rk-1;i>=0;i--)
        for(int j=i-1;j>=0;j--)
            if(b[j]>>i&1) b[j]^=b[i];
}


void dfs(i64 a[],int n,i64 res[],int x=0,i64 sum=0){
    if(x==n) {res[__builtin_popcountll(sum)]++;return;}
    dfs(a,n,res,x+1,sum),dfs(a,n,res,x+1,sum^a[x]);
}

void solve1(){
    static i64 sum[M];
    sort(),dfs(b,rk,sum);
    i64 mul=1;
    for(int i=1;i<=n-rk;i++) mul=mul*2%MOD;
    for(int i=0;i<=m;i++){
        i64 res=sum[i]*mul%MOD;
        cout<<res<<' ';
    }
}

void solve2(){
    sort();
    for(int i=rk;i<m;i++){
        b[i]|=(1ll<<i);
        for(int j=0;j<rk;j++)
            b[i]|=(b[j]>>i&1)<<j;
    }

    i64 mul=1;
    if(n>=m) for(int i=1;i<=n-m;i++) mul=mul*2%MOD;
    else for(int i=1;i<=m-n;i++) mul=mul*499122177%MOD;
    
    static i64 C[M][M];
    for(int i=0;i<=m;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }

    static i64 cnt[M];
    dfs(b+rk,m-rk,cnt);
    for(int i=0;i<=m;i++){
        i64 res=0;
        for(int j=0;j<=m;j++)
            for(int k=0;k<=min(i,j);k++)
                res+=cnt[j]*(k&1?-1:1)*C[j][k]%MOD*C[m-j][i-k]%MOD;
        res=(res%MOD+MOD)%MOD*mul%MOD;
        cout<<res<<' ';
    }
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) ins(rdi64());
    if(rk<=m/2) solve1();
    else solve2();
    return 0;
}