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
int h1, a1, c1;
int h2, a2;
bool done[10001][101];
pair <int, int> trace[10001][101];
queue <pair <int, int> > q;
vector <bool> ans;
void solve(pair <int, int> p){
    while(trace[p.first][p.second].first>=0){
        if(trace[p.first][p.second].second==p.second) ans.pb(0);
        else ans.pb(1);
        p=trace[p.first][p.second];
    }
    reverse(ans.begin(), ans.end());
    writeln(ans.size());
    for(bool t: ans) puts(t?"STRIKE":"HEAL");
    exit(0);
}
void bfs(){
    q.push(mp(h1, h2));
    pair <int, int> p=q.front();
    done[p.first][p.second]=1;
    trace[p.first][p.second]=mp(-1, -1);
    while(!q.empty()){
        p=q.front();
        q.pop();
        ///heal
        pair <int, int> np=p;
        np.first+=c1;
        np.first=min(np.first, 10000);
        np.first-=a2;
        np.first=max(np.first, 0);
        if(np.first!=0){
            if(!done[np.first][np.second]){
                done[np.first][np.second]=1;
                q.push(np);
                trace[np.first][np.second]=p;
            }
        }
        ///strike
        np=p;
        np.first-=a2;
        np.second-=a1;
        np.first=max(np.first, 0);
        np.second=max(np.second, 0);
        if(np.second!=0){
            if(np.first!=0){
                if(!done[np.first][np.second]){
                    done[np.first][np.second]=1;
                    q.push(np);
                    trace[np.first][np.second]=p;
                }
            }
        }
        else{
            if(!done[np.first][np.second]){
                done[np.first][np.second]=1;
                q.push(np);
                trace[np.first][np.second]=p;
            }
            solve(np);
        }
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(h1);
    read(a1);
    read(c1);
    read(h2);
    read(a2);
    bfs();
}