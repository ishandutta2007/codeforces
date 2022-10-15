#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define uu unsigned
#define scanf(x...) assert(~scanf(x))
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=2e5+3;
VI g[mxn];int n,m,S;
int de[mxn],fa[mxn],be[mxn];

void dfs(int x){
    for(int y:g[x])if(!de[y])de[y]=de[x]+1,fa[y]=x,be[y]=de[y]==2?y:be[x],dfs(y);
}

int main(){
    cin>>n>>m>>S;for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),g[x].push_back(y);
    de[S]=1,dfs(S);
    static int e[mxn];
    for(int y:g[S])if(de[y]!=2){
        puts("Possible");
        printf("2\n%d %d\n",S,y);int m=0;for(int i=y;i;i=fa[i])e[++m]=i;printf("%d\n",m);for(int i=m;i;--i)printf("%d ",e[i]);puts("");
        return 0;
    }
    for(int x=1;x<=n;++x)if(de[x]>1){
        for(int y:g[x])if(de[y]>1&&be[y]!=be[x]){
            puts("Possible");
            m=1,e[1]=y;for(int i=x;i;i=fa[i])e[++m]=i;printf("%d\n",m);for(int i=m;i;--i)printf("%d ",e[i]);puts("");
            m=0;for(int i=y;i;i=fa[i])e[++m]=i;printf("%d\n",m);for(int i=m;i;--i)printf("%d ",e[i]);puts("");
            return 0;
        }
    }
    puts("Impossible");
    return 0;
}