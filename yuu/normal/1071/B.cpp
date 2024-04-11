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
int n;
int k;
char c[2001][2001];
deque <pair <int, int> > q;
int f[2001][2001];
bool done[2001][2001];
void bfs(){
    pair <int, int> p=mp(1, 1);
    FOR(i, 1, n) FOR(j, 1, n) f[i][j]=1e9;
    f[1][1]=(c[1][1]!='a');
    q.pb(p);
    while(!q.empty()){
        p=q.front();
        q.pop_front();
        if(done[p.first][p.second]) continue;
        done[p.first][p.second]=1;
        if(p.first!=n){
            if(c[p.first+1][p.second]=='a'){
                f[p.first+1][p.second]=min(f[p.first+1][p.second], f[p.first][p.second]);
                q.push_front(mp(p.first+1, p.second));
            }
            else{
                f[p.first+1][p.second]=min(f[p.first+1][p.second], f[p.first][p.second]+1);
                q.push_back(mp(p.first+1, p.second));
            }
        }
        if(p.second!=n){
            if(c[p.first][p.second+1]=='a'){
                f[p.first][p.second+1]=min(f[p.first][p.second+1], f[p.first][p.second]);
                q.push_front(mp(p.first, p.second+1));
            }
            else{
                f[p.first][p.second+1]=min(f[p.first][p.second+1], f[p.first][p.second]+1);
                q.push_back(mp(p.first, p.second+1));
            }
        }
    }
}
vector <pair <int, int> > good;
vector <pair <int, int> > temp;
int best=0;
bool used[2001][2001];
void make(){
    while(true){
        char minc='z'+1;
        temp.clear();
        for(pair <int, int> p: good){
            if(p.first<n) minc=min(minc, c[p.first+1][p.second]);
            if(p.second<n) minc=min(minc, c[p.first][p.second+1]);
        }
        if(minc=='z'+1) return;///done
        putchar(minc);
        for(pair <int, int> p: good){
            if(p.first<n) if(minc==c[p.first+1][p.second]){
                if(!used[p.first+1][p.second]){
                    used[p.first+1][p.second]=1;
                    temp.pb(mp(p.first+1, p.second));
                }
            }
            if(p.second<n) if(minc==c[p.first][p.second+1]){
                if(!used[p.first][p.second+1]){
                    used[p.first][p.second+1]=1;
                    temp.pb(mp(p.first, p.second+1));
                }
            }
        }
        good=temp;
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(k);
    FOR(i, 1, n) FOR(j, 1, n) while(!isalpha(c[i][j]=getchar()));
    if(k){
        bfs();
        FOR(i, 1, n) FOR(j, 1, n) if(f[i][j]<=k){
            if(i+j>best){
                best=i+j;
                good.clear();
            }
            if(i+j==best) good.pb(mp(i, j));
        }
        FFOR(i, 1, best) putchar('a');
    }
    else{
        putchar(c[1][1]);
        good.pb(mp(1, 1));
    }
    make();
}