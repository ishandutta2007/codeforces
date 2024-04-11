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

const int N=200010,INF=0x3f3f3f3f;

struct Dsu{
    int f[N*6],cnt;
    void init(int n){cnt=n;iota(f+1,f+n+1,1);}
    int find(int x) {return x==f[x]?f[x]:f[x]=find(f[x]);}
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return;
        f[x]=y,cnt--;
    }
}d;

struct Seg{int l,r,id;};
Seg sl[2][N],sr[2][N];
int tot[2],n;

inline int id(int x,int c,int tp) {return tp*n+c*tot[0]+x;}

void clear(){
    tot[0]=tot[1]=0;
}

void solve(){
    n=rdi();d.init(4*n);
    for(int i=1;i<=n;i++){
        int c=rdi(),l=rdi(),r=rdi();
        ++tot[c],sl[c][tot[c]]=sr[c][tot[c]]={l,r,tot[c]};
    }
    auto cmp1 = [](Seg a,Seg b) {return a.l!=b.l?a.l<b.l:a.r<b.r;};
    auto cmp2 = [](Seg a,Seg b) {return a.r!=b.r?a.r<b.r:a.l<b.l;};

    for(int tp=0;tp<2;tp++)
        sort(sl[tp]+1,sl[tp]+tot[tp]+1,cmp1),sort(sr[tp]+1,sr[tp]+tot[tp]+1,cmp2);

    for(int tp=0;tp<2;tp++){
        for(int i=1;i<=tot[tp];i++){
            auto nw=sl[tp][i];
            int p1=lower_bound(sl[tp^1]+1,sl[tp^1]+tot[tp^1]+1,(Seg){nw.l,0,0},cmp1)-sl[tp^1];
            int p2=upper_bound(sl[tp^1]+1,sl[tp^1]+tot[tp^1]+1,(Seg){nw.r,INF,0},cmp1)-sl[tp^1]-1;
            if(p1<=p2){
                for(int j=d.find(id(p1,tp^1,0));j<id(p2,tp^1,0);j=d.find(j+1)) d.merge(j,j+1);
                d.merge(id(nw.id,tp,2),id(p1,tp^1,0));
            }

            p1=lower_bound(sr[tp^1]+1,sr[tp^1]+tot[tp^1]+1,(Seg){0,nw.l,0},cmp2)-sr[tp^1];
            p2=upper_bound(sr[tp^1]+1,sr[tp^1]+tot[tp^1]+1,(Seg){INF,nw.r,0},cmp2)-sr[tp^1]-1;
            if(p1<=p2){
                for(int j=d.find(id(p1,tp^1,1));j<id(p2,tp^1,1);j=d.find(j+1)) d.merge(j,j+1);
                d.merge(id(nw.id,tp,3),id(p1,tp^1,1));
            }
        }
    }
    for(int tp=0;tp<2;tp++)
        for(int i=1;i<=tot[tp];i++){
            d.merge(id(i,tp,2),id(i,tp,3));
            d.merge(id(i,tp,0),id(sl[tp][i].id,tp,2));
            d.merge(id(i,tp,1),id(sr[tp][i].id,tp,2));
        }
    cout<<d.cnt<<'\n';
    clear();
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}