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
typedef long long ll;
typedef long double ld;
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
#define taskname "E"
#define left _left
#define right _right
#define plus _plus
#define minus _minus
int p, m;
string e;
int eq[10001];
int left[10001];
int right[10001];
ll vmin[10001][101], vmax[10001][101];
bool done[10001][101];
int v[10001];
int n;
namespace plus{
    void cal(int n, int k){
        if(done[n][k]) return;
        done[n][k]=1;
        vmin[n][k]=1e9;
        vmax[n][k]=-1e9;
        if(eq[n]==2){
            if(k==0) vmin[n][k]=vmax[n][k]=v[n];
            return;
        }
        FOR(i, 0, k){
            cal(left[n], i);
            cal(right[n], i);
        }
        if(eq[n]==1){///+
            FOR(i, 0, k){
                vmin[n][k]=min(vmin[n][k], vmin[left[n]][i]+vmin[right[n]][k-i]);
                vmax[n][k]=max(vmax[n][k], vmax[left[n]][i]+vmax[right[n]][k-i]);
            }
        }
        else if(eq[n]==-1){///-
            FOR(i, 0, k){
                vmin[n][k]=min(vmin[n][k], vmin[left[n]][i]-vmax[right[n]][k-i]);
                vmax[n][k]=max(vmax[n][k], vmax[left[n]][i]-vmin[right[n]][k-i]);
            }
        }
        else{
            FFOR(i, 0, k){///+
                vmin[n][k]=min(vmin[n][k], vmin[left[n]][i]+vmin[right[n]][k-1-i]);
                vmax[n][k]=max(vmax[n][k], vmax[left[n]][i]+vmax[right[n]][k-1-i]);
            }
            FOR(i, 0, k){///-
                vmin[n][k]=min(vmin[n][k], vmin[left[n]][i]-vmax[right[n]][k-i]);
                vmax[n][k]=max(vmax[n][k], vmax[left[n]][i]-vmin[right[n]][k-i]);
            }
        }
    }
    void solve(){
        cal(n, p);
    }
}
namespace minus{
    void cal(int n, int k){
        if(done[n][k]) return;
        done[n][k]=1;
        vmin[n][k]=1e9;
        vmax[n][k]=-1e9;
        if(eq[n]==2){
            if(k==0) vmin[n][k]=vmax[n][k]=v[n];
            return;
        }
        FOR(i, 0, k){
            cal(left[n], i);
            cal(right[n], i);
        }
        if(eq[n]==1){///+
            FOR(i, 0, k){
                vmin[n][k]=min(vmin[n][k], vmin[left[n]][i]+vmin[right[n]][k-i]);
                vmax[n][k]=max(vmax[n][k], vmax[left[n]][i]+vmax[right[n]][k-i]);
            }
        }
        else if(eq[n]==-1){///-
            FOR(i, 0, k){
                vmin[n][k]=min(vmin[n][k], vmin[left[n]][i]-vmax[right[n]][k-i]);
                vmax[n][k]=max(vmax[n][k], vmax[left[n]][i]-vmin[right[n]][k-i]);
            }
        }
        else{
            FFOR(i, 0, k){///-
                vmin[n][k]=min(vmin[n][k], vmin[left[n]][i]-vmax[right[n]][k-1-i]);
                vmax[n][k]=max(vmax[n][k], vmax[left[n]][i]-vmin[right[n]][k-1-i]);
            }
            FOR(i, 0, k){///+
                vmin[n][k]=min(vmin[n][k], vmin[left[n]][i]+vmin[right[n]][k-i]);
                vmax[n][k]=max(vmax[n][k], vmax[left[n]][i]+vmax[right[n]][k-i]);
            }
        }
    }
    void solve(){
        cal(n, m);
    }
}
struct token{
    int value;
    token(char c){
        if(c=='-') value=-1;
        else if(c=='+') value=1;
        else if(c=='?') value=0;
        else if(c=='(') value=3;
    }
};
vector <token> tk;
vector <int> s;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>e>>p>>m;
    for(char c: e){
        if(isdigit(c)){
            n++;
            eq[n]=2;
            v[n]=c-48;
            s.pb(n);
        }
        else if(c==')'){
            while(tk.back().value!=3){
                n++;
                right[n]=s.back();
                s.pop_back();
                left[n]=s.back();
                s.pop_back();
                eq[n]=tk.back().value;
                s.pb(n);
                tk.pop_back();
            }
            tk.pop_back();
        }
        else tk.pb(token(c));
    }
    if(p<=m) plus::solve();
    else minus::solve();
    writeln(vmax[n][min(p, m)]);
}