#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "E"
int n, m, k, q;
int prex[2222];
int prey[2222];
int nextx[2222];
int nexty[2222];
int a[2222][2222];
ll w[2222][2222];
ll cw[75][75];
ll f[75][75];
int dx, dy;
int cx, cy;
struct e{
    int x, y;
    ll w;
    e(int x, int y, ll w){
        this->x=x;
        this->y=y;
        this->w=w;
    }
};
struct garlan{
    vector <e> z;
    bool old;
    bool now;
    void init(){
        FOR(i, 1, cx){
            FOR(j, 1, cy){
                if(cw[i][j]){
                    z.pb(e(i, j, cw[i][j]));
                    f[i][j]+=cw[i][j];
                    cw[i][j]=0;
                }
            }
        }
        old=now=1;
    }
    void update(){
        if(old==now) return;
        if(old==0){
            for(int i=0; i<z.size(); i++)
                f[z[i].x][z[i].y]+=z[i].w;
        }
        else{
            for(int i=0; i<z.size(); i++)
                f[z[i].x][z[i].y]-=z[i].w;
        }
        old=now;
    }
} g[2222];
ll countrect(int x1, int y1, int x2, int y2){
    if(x1>x2||y1>y2) return 0;
    ll res=0;
    FOR(i, x1, x2)
        FOR(j, y1, y2)
            if(g[a[i][j]].now)
                res+=w[i][j];
    return res;
}
ll query(int x1, int y1, int x2, int y2){
    FOR(i, 1, k)
        g[i].update();
    ll res=0;
    DFOR(i, prex[x2]-1, nextx[x1]){
        DFOR(j, prey[y2]-1, nexty[y1]){
            res+=f[i][j];
        }
    }
    if(prex[x2]>nextx[x1]&&prey[y2]>nexty[y1]){
        res+=countrect(x1, y1, x2, (nexty[y1]-1)*dy);
        res+=countrect(x1, (prey[y2]-1)*dy+1, x2, y2);
        res+=countrect(x1, (nexty[y1]-1)*dy+1, (nextx[x1]-1)*dx, (prey[y2]-1)*dy);
        res+=countrect((prex[x2]-1)*dx+1, (nexty[y1]-1)*dy+1, x2, (prey[y2]-1)*dy);
    }
    else res=countrect(x1, y1, x2, y2);
    return res;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(m);
    dx=round(sqrt(double(n)));
    dy=round(sqrt(double(m)));
    FOR(i, 1, n){
        prex[i]=prex[i-1]+(((i-1)%dx)==0);
        if((i-1%dx)==0)
            nextx[i]=prex[i];
        else nextx[i]=prex[i]+1;
    }
    FOR(i, 1, m){
        prey[i]=prey[i-1]+(((i-1)%dy)==0);
        if((i-1%dy)==0)
            nexty[i]=prey[i];
        else nexty[i]=prey[i]+1;
    }
    cx=prex[n];
    cy=prey[m];
    read(k);
    FOR(i, 1, k){
        int x, y, c;
        read(c);
        FOR(j, 1, c){
            read(x);
            read(y);
            a[x][y]=i;
            read(w[x][y]);
            cw[prex[x]][prey[y]]+=w[x][y];
        }
        g[i].init();
    }
    read(q);
    char c, cc;
    int u, x1, y1, x2, y2;
    FOR(i, 1, q){
        while(!isalpha(c=getchar()));
        while(isalpha(cc=getchar()));
        if(c=='S'){
            read(u);
            g[u].now=1-g[u].now;
        }
        else{
            read(x1);
            read(y1);
            read(x2);
            read(y2);
            writeln(query(x1, y1, x2, y2));
        }
    }
}