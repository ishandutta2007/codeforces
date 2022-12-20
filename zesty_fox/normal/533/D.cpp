#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
#define rdl read<ll>

const int N=100010;
int n,pos[N],d[N];

int st[N],tp,f[N],g[N],ans=1e18;
void pre(){
    st[tp=0]=0;
    for(int i=1;i<=n;i++){
        while(tp&&pos[i]-pos[f[st[tp]]]>2*d[st[tp]]) tp--;
        f[i]=st[tp];
        while(tp&&2*d[st[tp]]+pos[f[st[tp]]]<=2*d[i]+pos[f[i]]) tp--;
        st[++tp]=i;
    }
    st[tp=0]=n+1;
    for(int i=n;i>=1;i--){
        while(tp&&pos[g[st[tp]]]-pos[i]>2*d[st[tp]]) tp--;
        g[i]=st[tp];
        while(tp&&pos[g[st[tp]]]-2*d[st[tp]]>=pos[g[i]]-2*d[i]) tp--;
        st[++tp]=i;
    }
}

void sol1(){
    for(int i=1;i<=n;i++){
        if(pos[g[i]]-pos[f[i]]<=2*d[i]) puts("0"),exit(0);
        ans=min(ans,pos[g[i]]-pos[f[i]]);
    }
}

int raw[N],cnt;
struct TreeArray{
#define lowbit(x) (x&(-x))
    int c[N];
    TreeArray(){memset(c,-1,sizeof(c));}
    void update(int x,int val){
        for(;x;x-=lowbit(x)) c[x]=max(c[x],val);
    }
    int query(int x){
        int res=-1; 
        for(;x<=cnt;x+=lowbit(x)) res=max(c[x],res);
        return res;
    }
#undef lowbit
}t;

void sol2(){
    for(int i=1;i<=n;i++){
        if(pos[i]-pos[f[i]]<2*d[i]) raw[++cnt]=d[i]*2+pos[f[i]];
    }
    sort(raw+1,raw+cnt+1);cnt=unique(raw+1,raw+cnt+1)-raw-1;
    ans=pos[n+1];
    for(int i=1;i<=n;i++){
        if(pos[g[i]]-pos[i]<2*d[i]){
            int p=lower_bound(raw+1,raw+cnt+1,pos[g[i]]-2*d[i])-raw;
            int res=t.query(p);
            if(res!=-1) ans=min(ans,pos[i]-res);
        }
        if(pos[i]-pos[f[i]]<2*d[i]){
            int p=lower_bound(raw+1,raw+cnt+1,2*d[i]+pos[f[i]])-raw;
            t.update(p,pos[i]);
        }
    }
}

void sol3(){
    for(int i=1;i<=n;i++){
        if(!f[i]&&pos[g[i]]-pos[i]<2*d[i]) ans=min(ans,pos[i]);
        if(g[i]==n+1&&pos[i]-pos[f[i]]<2*d[i]) ans=min(ans,pos[n+1]-pos[i]);
    }
}

signed main(){
    n=rdi();
    for(int i=0;i<=n+1;i++) pos[i]=rdl();
    for(int i=1;i<=n;i++) d[i]=rdl();
    pre();sol1();sol2();sol3();
    printf("%.4lf\n",ans/2.0);
    return 0;
}