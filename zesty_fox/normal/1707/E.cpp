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

const int N=1e5+10,L=19;

int n,q,a[N];

pii f[L][L][N];
pii operator + (pii a,pii b){
    return {min(a.fi,b.fi),max(a.se,b.se)};
}

inline int lg2(int x){
    return !x?-1:__lg(x);
}

pii _query(int k,int l,int r){
    int p=lg2(r-l);
    return f[k][p][l]+f[k][p][r-(1<<p)];
}

void init(){
    for(int i=1;i<n;i++)
        f[0][0][i]=(pii){a[i],a[i]}+(pii){a[i+1],a[i+1]};
    for(int j=1;j<=lg2(n);j++)
        for(int i=1;i<=n-(1<<j);i++)
            f[0][j][i]=f[0][j-1][i]+f[0][j-1][i+(1<<(j-1))];
    for(int k=1;k<L;k++)
        for(int j=0;j<=lg2(n);j++)
            for(int i=1;i<=n-(1<<j);i++){
                auto cur=f[k-1][j][i];
                if(cur.fi==cur.se)
                    continue;
                f[k][j][i]=_query(k-1,cur.fi,cur.se);
            }
}

int query(int l,int r){
    if(l==1&&r==n)
        return 0;
    int sum=1;
    for(int i=L-1;i>=0;i--){
        if(l==r){
            sum=2*n+1;
            break;
        }
        auto nxt=_query(i,l,r);
        if(nxt.fi!=1||nxt.se!=n)
            tie(l,r)=nxt,sum+=(1<<i);
    }
    if(sum>2*n)
        return -1;
    else 
        return sum;
}

int main(){
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++)
        a[i]=rdi();
    init();
    while(q--){
        int l=rdi(),r=rdi();
        cout<<query(l,r)<<'\n';
    }
    return 0;
}