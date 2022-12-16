// LUOGU_RID: 96590450
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

const int N=1010;
const int fx[][2]={{-1,0},{0,1},{1,0},{0,-1}};

int n,m;
int s[N][N],ans[N][N];

struct Node{int x,y,v;}p[N*N];

inline int id(int x,int y,int d) {return (x-1)*m*4+(y-1)*4+d;}
struct Dsu{
    int f[N*N*4],cnt[N*N*4];
    i64 sum[N*N*4];
    void init(int n,int m){
        for(int i=0;i<n*m*4;i++)
            cnt[i]=sum[i]=1,f[i]=i;
    }
    int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x!=y) f[x]=y,cnt[y]+=cnt[x],sum[y]+=sum[x];
    }
}d;

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=rdi();

    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            p[++tot]={i,j,s[i][j]};
    sort(p+1,p+tot+1,[&](const Node &a,const Node &b){return a.v<b.v;});
    d.init(n,m);
    for(int i=1;i<=tot;i++){
        int x=p[i].x,y=p[i].y;i64 res=0;
        for(int k=0;k<4;k++){
            i64 sum=(i64)d.cnt[id(x,y,k)]*p[i].v;
            res+=sum-d.sum[id(x,y,k)],d.sum[id(x,y,k)]=sum;
        }
        ans[x][y]=(res&=1);
        
        for(int k=0;k<4;k++){
            int k1=(k+2+res)%4,tox=x+fx[k1][0],toy=y+fx[k1][1];
            if(tox<1||tox>n||toy<1||toy>m) continue;
            d.merge(id(x,y,k),id(tox,toy,(k1+2)%4));
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<ans[i][j];
        cout<<'\n';
    }
    return 0;
}