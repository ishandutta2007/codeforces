#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int INF=0x3f3f3f3f;
#define rdi read<int>
#define rdl read<ll>
#define mp make_pair
#define pb push_back
#define fi first
#define sec second

const int N=500010;
struct Graph{
    vector<int> to[N<<1];
    void addedge(int x,int y){to[x].push_back(y);}
}g,g1;

int n,m,k,bel[N];
vector<int> c[N];

int no[N],col[N];
void dfs1(int x,int color,int typ){
    col[x]=color;
    for(auto y:g.to[x]){
        if(bel[y]!=bel[x]) continue;
        if(col[y]==col[x]) {no[typ]=1;return;}
        else if(col[y]) continue;
        dfs1(y,3-color,typ);
    }
}

int cnt,lt[N];
void dfs2(int x,int id){
    lt[x]=id;
    for(auto y:g.to[x]){
        if(lt[y]) continue;
        dfs2(y,id);
    }
}

int col1[N<<1];
bool dfs3(int x,int color){
    col1[x]=color;
    for(auto y:g1.to[x]){
        if(col1[y]==col1[x]) return false;
        else if(col1[y]) continue;
        else if(!dfs3(y,3-color)) return false;
    }
    return true;
}

ll ans,noc;
int pos;
pii e[N];
bool cmp(pii x,pii y){
    return bel[x.fi]==bel[y.fi]?bel[x.sec]<bel[y.sec]:bel[x.fi]<bel[y.fi];
}

int main(){
    n=rdi(),m=rdi(),k=rdi();
    for(int i=1;i<=n;i++) bel[i]=rdi(),c[bel[i]].push_back(i);
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        if(bel[x]!=bel[y]){
            if(bel[x]>bel[y]) swap(x,y);
            e[++pos]=mp(x,y);
        }
        else g.addedge(x,y),g.addedge(y,x);
    }
    for(int i=1;i<=k;i++){
        for(auto x:c[i]){
            if(!col[x]) dfs1(x,1,i);
            if(no[i]) {noc++;break;}
        }
    }
    for(int i=1;i<=n;i++){
        if(!lt[i]) dfs2(i,++cnt);
    }
    ans=(ll)(k-noc)*(k-noc-1)/2;
    sort(e+1,e+pos+1,cmp);
    for(int i=1,j=1;i<=pos;i=j){
        int fx=bel[e[i].fi],fy=bel[e[i].sec];
        while(j<=pos&&bel[e[j].fi]==fx&&bel[e[j].sec]==fy) j++;
        if(no[fx]||no[fy]) continue;
        int tot=n;set<int> s;
        for(int tmp=i;tmp<j;tmp++){
            int x=e[tmp].fi,y=e[tmp].sec;
            s.insert(lt[x]),s.insert(lt[y]);
            if(col[x]==col[y]){
                ++tot,g1.addedge(lt[x],tot),g1.addedge(tot,lt[x]),g1.addedge(tot,lt[y]),g1.addedge(lt[y],tot);
                s.insert(tot);
            }
            else g1.addedge(lt[x],lt[y]),g1.addedge(lt[y],lt[x]);
        }
        for(auto x:s) col1[x]=0;
        bool flg=1;
        for(auto x:s){
            if(!col1[x]){
                flg&=dfs3(x,1);
                if(!flg) break;
            }
        }
        if(!flg) ans--;
        for(auto x:s) g1.to[x].clear();
    }
    printf("%lld\n",ans);
    return 0;
}