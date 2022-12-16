#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;

int n,q,nx[N];
struct Op{int op,x,y;}op[N];
i64 res[N],qcnt,a[N];

const int B=1310;

i64 sum[N],ad[N];
int tg[N],bl[N];
int tot,st[N],ed[N],c[B][B];
void process(int l,int r){
    for(int i=1;i<=n;i++) tg[i]=bl[i]=0;
    for(int i=l;i<=r;i++)
        if(op[i].op==3) tg[nx[op[i].x]]=tg[nx[op[i].y]]=1;
        else if(op[i].op==2) tg[op[i].x]=1;

    tot=0;
    for(int i=1;i<=n;i++){
        if(tg[i]){
            st[++tot]=i;int nw=i;
            do bl[nw]=tot,ed[tot]=nw,nw=nx[nw];
            while(!tg[nw]);
        }
    }
    /*
    for(int i=1;i<=n;i++){
        if(!bl[i]){
            st[++tot]=i;int nw=i;
            while(!bl[nw]) bl[nw]=tot,ed[tot]=nw,nw=nx[nw];
        }
    }
    */

    static int pos[B];int pcnt=0;
    for(int i=l;i<=r;i++)
        if(op[i].op==1) pos[++pcnt]=op[i].x-1,pos[++pcnt]=op[i].y;
    sort(pos+1,pos+pcnt+1);pcnt=unique(pos+1,pos+pcnt+1)-pos-1;
    for(int i=1,lst=0;i<=pcnt;i++){
        for(int j=1;j<=tot;j++) c[j][i]=c[j][i-1];
        for(int j=lst+1;j<=pos[i];j++) c[bl[j]][i]++;
        lst=pos[i];
    }

    auto getrk = [&](int x) {return lower_bound(pos+1,pos+pcnt+1,x)-pos;};

    for(int i=l;i<=r;i++){
        if(op[i].op==1){
            res[++qcnt]=sum[op[i].y]-sum[op[i].x-1];
            int l=getrk(op[i].x-1),r=getrk(op[i].y);
            for(int j=1;j<=tot;j++) res[qcnt]+=(c[j][r]-c[j][l])*ad[j];
        }
        else if(op[i].op==2){
            int x=bl[op[i].x],nw=st[x];
            do ad[bl[nw]]+=op[i].y,nw=nx[ed[bl[nw]]];
            while(bl[nw]!=x);
        }
        else if(op[i].op==3)
            swap(nx[op[i].x],nx[op[i].y]);
    }

    for(int i=1;i<=n;i++) a[i]+=ad[bl[i]],sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=tot;i++) ad[i]=0;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++) nx[i]=rdi();
    q=rdi();
    for(int i=1;i<=q;i++)
        op[i].op=rdi(),op[i].x=rdi(),op[i].y=rdi();
    
    int siz=sqrt(n)*1.3;
    for(int l=1,r;l<=q;l=r+1)
        r=min(q,l+siz-1),process(l,r);
    for(int i=1;i<=qcnt;i++) cout<<res[i]<<'\n';
    return 0;
}