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

const int N=300010;

int m,n,a[N];
i64 res[N];

struct Query{i64 x,k;int id,typ;}st[N];
int tp;

struct BIT{
    int sum[N],n;
    void init(int _n) {n=_n;fill(sum+1,sum+n+1,0);}
    int query_kth(int k){
        int cur=0,s=0;
        for(int x=(1<<__lg(n));x>=1;x>>=1)
            if(cur+x<=n&&s+sum[cur+x]<k) cur+=x,s+=sum[cur];
        return cur+1;
    }
    int query_sum(int x){
        int ret=0;
        for(;x;x-=(x&(-x))) ret+=sum[x];
        return ret;
    }
    void add(int x,int v){
        for(;x<=n;x+=(x&(-x))) sum[x]+=v;
    }
}t;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),st[++tp]={a[i],0,0,0};
    for(int i=1;i<=m;i++){
        int x=rdi(),k=rdi();
        if(x<a[1]) res[i]=x;
        else st[++tp]={x,k,i,1};
    }

    sort(st+1,st+tp+1,[&](Query a,Query b) {return a.x!=b.x?a.x>b.x:a.typ>b.typ;});
    t.init(n);
    for(int i=1;i<=n;i++) t.add(i,1);
    i64 ti=0,mi=1e15,tot=n;
    for(int i=1;i<=tp;i++){
        i64 d=(mi+tot-1-st[i].x)/tot;
        ti+=d,mi-=d*tot;
        if(st[i].typ) st[i].k=ti-st[i].k,st[i].x=t.query_kth(st[i].x-mi+1);
        else t.add(t.query_kth(st[i].x-mi+1),-1),--tot;
    }
 
    int qc=partition(st+1,st+tp+1,[&](Query a){return a.typ;})-st-1;
    sort(st+1,st+qc+1,[&](Query a,Query b) {return a.k<b.k;});
    t.init(n);
    for(int i=1;i<=n;i++) t.add(i,1);
    ti=0,mi=1e15,tot=n;
    for(int i=n,p=1;i>=1;i--){
        i64 d=(mi+tot-1-a[i])/tot;
        while(p<=qc&&st[p].k<=ti+d)
            res[st[p].id]=mi+t.query_sum(st[p].x)-1-(st[p].k-ti)*tot,++p;
        ti+=d,mi-=d*tot,t.add(t.query_kth(a[i]-mi+1),-1),--tot;
    }

    for(int i=1;i<=m;i++) cout<<res[i]<<'\n';
    return 0;
}