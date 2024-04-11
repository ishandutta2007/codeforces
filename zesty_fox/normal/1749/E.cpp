#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=4e5+10,INF=0x3f3f3f3f;

int n,m;

int id(int x,int y){
    return (x-1)*m+y;
}

pii rid(int x){
    return {(x-1)/m+1,(x-1)%m+1};
}

char a[N];

bool check(int x,int y){
    static const int fx1[][2]={{0,1},{0,-1},{1,0},{-1,0}};
    for(auto [dx1,dy1]:fx1){
        int x2=x+dx1,y2=y+dy1;
        if(x2>=1&&x2<=n&&y2>=1&&y2<=m&&a[id(x2,y2)]=='#') return false;
    }
    return true;
}

int dis[N],pr[N];
void bfs(){
    static const int fx[][2]={{1,-1},{1,1},{-1,-1},{-1,1}};
    static int dis[N];
    const int S=n*m+1;
    fill(dis,dis+S+1,INF);
    deque<int> q({S});dis[S]=0;
    while(!q.empty()){
        int nw=q.front();q.pop_front();
        if(nw==S){
            for(int i=1;i<=n;i++){
                if(!check(i,1)) continue;
                int w=a[id(i,1)]=='.',nw1=id(i,1);
                pr[nw1]=S,dis[nw1]=w;
                if(!w) q.push_front(nw1);
                else q.push_back(nw1);
            }
        }
        else if(rid(nw).se==m){
            puts("YES");
            while(nw!=S)
                a[nw]='#',nw=pr[nw];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)
                    putchar(a[id(i,j)]);
                putchar('\n');
            }
            return;
        }
        else{
            auto [x,y]=rid(nw);
            for(auto [dx,dy]:fx){
                int x1=x+dx,y1=y+dy,nw1=id(x1,y1);
                if(x1<1||x1>n||y1<1||y1>m||dis[nw1]<INF||!check(x1,y1)) continue;
                int w=(a[id(x1,y1)]=='.');
                if(dis[nw1]>dis[nw]+w){
                    dis[nw1]=dis[nw]+w,pr[nw1]=nw;
                    if(!w) q.push_front(nw1);
                    else q.push_back(nw1);
                }
            }
        }
    }
    puts("NO");
}

void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) scanf("%s",a+(i-1)*m+1);
    bfs();
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}