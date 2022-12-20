#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

namespace IO {
    inline char nc(){
        static char buf[500001],*p1=buf,*p2=buf;
        return p1==p2&&(p2=(p1=buf)+fread(buf,1,500000,stdin),p1==p2)?EOF:*p1++;
    }
    char out[500001],*pout=out,*eout=out+500000;
    template<typename T> inline T read(){
        char ch=nc(); T sum=0; bool f=false;
        for(;ch<'0'||ch>'9';ch=nc()) if(ch=='-') f=1;
        while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
        return f ? -sum : sum;
    }
}

#define rdi IO::read<int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=1e5+10,M=3e5+10;

int n,m;

struct Edge{int to,nxt;bool flg;}e[M*2];
int head[N],tot=1,deg[N];
void addedge(int x,int y){
    e[++tot]={y,head[x],0};
    head[x]=tot;
}

int vis[N],f[N],ans,dep[N];
void dfs(int x,int in){
    vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        if(i==(in^1)) continue;
        int y=e[i].to;
        if(!vis[y]) dep[y]=dep[x]+1,f[y]=x,dfs(y,i);
        else if(dep[y]<dep[x]){
            int x1=x,cnt=(deg[y]>2);
            while(x1!=y)
                cnt+=(deg[x1]>2),x1=f[x1];
            if(cnt<=1) ans++;
        }
    }
}

int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        addedge(x,y),addedge(y,x);
        deg[x]++,deg[y]++;
    }
    for(int i=1;i<=n;i++) ans+=(deg[i]&1);
    ans/=2;
    dfs(1,-1);
    cout<<ans<<' '<<m<<endl;
    return 0;
}