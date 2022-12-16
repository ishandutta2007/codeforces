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

const int N=100010,B=350;
const ll INF=0x3f3f3f3f3f3f3f3f;

int n,a[N],seq[N];
ll b[N];

struct Block{
    ll tagk,tagb;

    int q[B*5],ql,qr;

    ll calc(int x) {return a[x]*tagk+b[x]+tagb;}

    double calc(int x,int y){
        if(a[x]==a[y]) return b[x]<b[y]?INF:-INF;
        return 1.*(b[y]-b[x])/(a[y]-a[x]);
    }

    void build(int l,int r){
        for(int i=l;i<=r;i++) b[i]+=a[i]*tagk+tagb;
        tagk=tagb=0,ql=1,qr=0;
        for(int i=l;i<=r;i++){
            while(ql<qr&&calc(q[qr-1],q[qr])<calc(q[qr],seq[i])) qr--;
            q[++qr]=seq[i];
        }
    }

    pair<ll,int> query(){
        while(ql<qr&&calc(q[ql])<=calc(q[ql+1])) ql++;
        return {calc(q[ql]),q[ql]};
    }
}c[B];

int L[B],R[B],bl[N],bcnt;

void build(){
    int bsiz=sqrt(n);
    for(int l=1,r;l<=n;l=r+1){
        r=min(n,l+bsiz-1);
        L[++bcnt]=l,R[bcnt]=r;
        for(int j=l;j<=r;j++) bl[j]=bcnt,seq[j]=j,b[j]=a[j];
        sort(seq+l,seq+r+1,[&](const int &x,const int &y){return a[x]<a[y];});
        c[bcnt].build(l,r);
    }
}

void modify(int x){
    int id=bl[x];
    for(int i=1;i<id;i++) c[i].tagb+=a[x];
    for(int i=id+1;i<=bcnt;i++) c[i].tagk++;
    for(int i=L[id];i<x;i++) b[i]+=a[x];
    for(int i=x+1;i<=R[id];i++) b[i]+=a[i];
    b[x]=-INF,c[id].build(L[id],R[id]);
}

ll ans;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    build();
    while(true){
        pair<ll,int> tmp{0,0};
        for(int i=1;i<=bcnt;i++) tmp=max(tmp,c[i].query());
        if(tmp.fi<=0) break;
        ans+=tmp.fi,modify(tmp.se);
    }
    cout<<ans<<endl;
    return 0;
}