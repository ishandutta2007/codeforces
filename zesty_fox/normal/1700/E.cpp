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

const int fx[][2]={{0,1},{0,-1},{1,0},{-1,0},{0,0}};
const int INF=0x3f3f3f3f;

vector<vi> v,vis;
int n,m;

vector<pii> p;

bool check(int x,int y){
    if(v[x][y]==1) return true;
    for(int k=0;k<4;k++){
        int x1=x+fx[k][0],y1=y+fx[k][1];
        if(v[x1][y1]<v[x][y]) return true;
    }
    return false;
}

bool swap(pii p1,pii p2){
#define ret(val) return swap(v[p1.fi][p1.se],v[p2.fi][p2.se]),val
    swap(v[p1.fi][p1.se],v[p2.fi][p2.se]);
    for(auto tmp:p) if(!check(tmp.fi,tmp.se)) ret(false);
    for(auto p:{p1,p2}){
        for(int i=0;i<5;i++){
            int x1=p.fi+fx[i][0],y1=p.se+fx[i][1];
            if(x1<1||x1>n||y1<1||y1>m) continue;
            if(!check(x1,y1)) ret(false);
        }
    }
    ret(true);
#undef ret
}

vector<pii> res;

inline int id(int x,int y) {return (x-1)*m+y;}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();v.resize(n+2,vi(m+2,INF));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) v[i][j]=rdi();
    for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++)
            if(!check(x,y)) p.pb({x,y});
    if(p.empty()) return puts("0"),0;
    else if(p.size()>=4) return puts("2"),0;
    for(int i=0;i<p.size();i++){
        int x=p[i].fi,y=p[i].se;
        for(int j=0;j<5;j++){
            int x1=x+fx[j][0],y1=y+fx[j][1];
            if(x1<1||x1>n||y1<1||y1>m) continue;
            for(int tox=1;tox<=n;tox++){
                for(int toy=1;toy<=m;toy++){
                    if(tox==x1&&toy==y1) continue;
                    if(swap({x1,y1},{tox,toy})){
                        int id1=id(x1,y1),id2=id(tox,toy);
                        res.pb({min(id1,id2),max(id1,id2)});
                    }
                }
            }
        }
    }
    if(res.empty()) return puts("2"),0;
    else{
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        cout<<"1 "<<res.size()<<'\n';
    }
    return 0;
}