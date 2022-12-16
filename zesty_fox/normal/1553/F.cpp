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

const int N=300010;

int n,a[N],maxn;
ll sum[N],res[N];

struct Fenwick{
    ll sum[N];
    void add(int x,ll val){
        for(;x<=maxn;x+=(x&(-x))) sum[x]+=val;
    }
    ll query(int x){
        ll ret=0;
        for(;x;x-=(x&(-x))) ret+=sum[x];
        return ret;
    }
}t1,t2;

int main(){
    n=rdi();
    for(int i=1;i<=n;i++){
        a[i]=rdi();
        maxn=max(maxn,a[i]);
        sum[i]=sum[i-1]+a[i];
    }

    for(int k=1;k<=n;k++){
        res[k]=res[k-1];
        
        res[k]+=sum[k-1];
        for(int i=a[k];i<=maxn;i+=a[k]) res[k]-=(ll)a[k]*(k-1-t1.query(i-1));
        
        res[k]+=(ll)a[k]*(k-1)-t2.query(a[k]);

        t1.add(a[k],1);
        for(int i=a[k];i<=maxn;i+=a[k]) t2.add(i,a[k]);
    }
    for(int k=1;k<=n;k++) printf("%lld ",res[k]);
    return 0;
}