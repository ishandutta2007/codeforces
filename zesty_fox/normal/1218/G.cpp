// LUOGU_RID: 96831180
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

const int N=2e5+10;

int n,m,typ[N];
char s[N];

struct Edge{int to,nxt,fl,w;}e[N];
int head[N],tot=1,deg[N];

void add_e(int x,int y){
    e[++tot]={y,head[x],0,0};
    head[x]=tot,++deg[x];
}

bool odd_lp;
int col[N];
void dfs(int x,int c=1){
    col[x]=c;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(!col[y]) e[i].fl=e[i^1].fl=1,dfs(y,3-c);
        else if(col[y]==col[x]) odd_lp=true;
    }
}

namespace S1{
    int sum[N];
    void dfs1(int x,int fa){
        for(int i=head[x];i;i=e[i].nxt){
            if(!e[i].fl) continue;
            int y=e[i].to;
            if(y!=fa) dfs1(y,x),sum[x]+=e[i].w;
        }
        for(int i=head[x];i;i=e[i].nxt){
            if(e[i].fl&&e[i].to==fa){
                e[i].w=e[i^1].w=(col[x]+3-sum[x]%3)%3;
                sum[x]=col[x];break;
            }
        }
    }
    void solve(){
        int rt=find(col+1,col+n+1,1)-col;
        dfs1(rt,0);
        if(deg[rt]>1&&sum[rt]%3==2){
            int i1=head[rt],i2=e[i1].nxt;
            e[i1].w++,e[i1^1].w++,e[i2].w++,e[i2^1].w++;
        }
    }
}

namespace S2{
    int rt,u,sum[N],tofa[N];
    void dfs1(int x,int fa){
        for(int i=head[x];i;i=e[i].nxt){
            if(!e[i].fl) continue;
            int y=e[i].to;
            if(y!=fa) dfs1(y,x),sum[x]+=e[i].w;
        }
        for(int i=head[x];i;i=e[i].nxt){
            if(e[i].fl&&e[i].to==fa){
                e[i].w=e[i^1].w=(typ[x]+3-sum[x]%3)%3;
                sum[x]=typ[x],tofa[x]=i;
                break;
            }
        }
    }

    void adjust(){
        if(sum[rt]%3==typ[rt]%3) return;
        vi cyc;int x=u;
        while(x!=rt) cyc.pb(tofa[x]),x=e[tofa[x]].to;
        for(int i=head[rt];i;i=e[i].nxt)
            if(!e[i].fl&&e[i].to==u) {cyc.insert(cyc.begin(),i);break;}
        int val=(sum[rt]+1)%3==typ[rt]%3?2:1;
        for(auto id:cyc) e[id].w+=val,e[id^1].w+=val,val=3-val;
    }

    void solve(){
        for(int x=1;x<=n;x++){
            bool fl=0;
            for(int i=head[x];i;i=e[i].nxt)
                if(col[e[i].to]==col[x]){
                    fl=1,rt=x,u=e[i].to;
                    break;
                }
            if(fl) break;
        }
        dfs1(rt,0),adjust();
    }
}

void output(){
    for(int i=2;i<=tot;i+=2){
        int x=e[i^1].to,y=e[i].to,w=(e[i].w+2)%3+1;
        cout<<x-1<<' '<<y-1<<' '<<w<<'\n';
    }
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi(),m=rdi();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) typ[i]=s[i]-'X'+1;
    for(int i=1;i<=m;i++){
        int x=rdi()+1,y=rdi()+1;
        add_e(x,y),add_e(y,x);
    }
    dfs(1);
    if(odd_lp) S2::solve();
    else S1::solve();
    output();
    return 0;
}