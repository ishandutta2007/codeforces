#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
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
#define taskname "B"
int n, m;
int r, c;
int x, y;
char a[2002][2002];
bool good[2002][2002];
pair <int, int> f[2002][2002];
int done[2002][2002];
deque <pair <int, int>> q;
int cx[]={0, 0, 1, -1};
int cy[]={-1, 1, 0, 0};
void make(){
    FOR(i, 1, n) FOR(j, 1, m){
        done[i][j]=0;
        f[i][j]=mp(x+1, y+1);
    }
    q.clear();
    q.pb(mp(r, c));
    f[r][c]=mp(0, 0);
    pair <int, int> p;
    while(!q.empty()){
        p=q.front();
        q.pop_front();
        if(done[p.first][p.second]) continue;
        done[p.first][p.second]=1;
        if(f[p.first][p.second].first>x) break;
        if(f[p.first][p.second].second<=y) good[p.first][p.second]=1;
        FFOR(k, 0, 4){
            int ii=p.first+cx[k];
            int jj=p.second+cy[k];
            if(a[ii][jj]!='.') continue;
            if(done[ii][jj]) continue;
            if(k==0){
                f[ii][jj]=min(f[ii][jj], mp(f[p.first][p.second].first+1, f[p.first][p.second].second));
                q.pb(mp(ii, jj));
            }
            else if(k==1){
                f[ii][jj]=min(f[ii][jj], mp(f[p.first][p.second].first, f[p.first][p.second].second+1));
                q.push_front(mp(ii, jj));
            }
            else{
                f[ii][jj]=min(f[ii][jj], mp(f[p.first][p.second].first, f[p.first][p.second].second));
                q.push_front(mp(ii, jj));
            }
        }
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(r);
    read(c);
    read(x);
    read(y);
    FOR(i, 1, n) FOR(j, 1, m){
        while(a[i][j]=getchar()){
            if(a[i][j]=='*') break;
            if(a[i][j]=='.') break;
        }
    }
    make();
    swap(x, y);
    swap(cy[0], cy[1]);
    make();
    int ans=0;
    FOR(i, 1, n) FOR(j, 1, m) ans+=good[i][j];
    writeln(ans);
}