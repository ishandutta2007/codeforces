#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
#define taskname "E"
int n;
int s[300001];
int t[300001];
int a[300001];
int des[300001];
class op{
public:
    int i, j, d;
    op(int i, int j, int d){
        this->i=i;
        this->j=j;
        this->d=d;
    }
    void output(){
        write(i);
        putchar(' ');
        write(j);
        putchar(' ');
        writeln(d);
    }
};
vector <op> ans;
void bye(){
    puts("NO");
    exit(0);
}
void perfrom_move(int i, int j, int d){
    ans.pb(op(i, j, d));
    if(d*2>s[j]-s[i]) bye();
    s[i]+=d;
    s[j]-=d;
}
deque <int> rtl;
class cmp{
public:
    bool operator()(int a, int b){
        return s[a]>s[b];
    }
};
priority_queue <int, vector <int>, cmp> ltr;
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n) read(s[i]);
    FOR(i, 1, n) read(t[i]);
    sort(t+1, t+n+1);
    FOR(i, 1, n) a[i]=i;
    sort(a+1, a+n+1, [](int x, int y){
        return s[x]<s[y];
    });
    FOR(i, 1, n){
        des[a[i]]=t[i];
        if(t[i]>s[a[i]]) ltr.push(a[i]); else if(t[i]<s[a[i]]) rtl.pb(a[i]);
    }
    while(!ltr.empty()){
        int u=ltr.top();
        ltr.pop();
        if(s[u]==des[u]) continue;
        if(rtl.empty()) bye();
        int mov=min(des[u]-s[u], s[rtl.front()]-des[rtl.front()]);
        perfrom_move(u, rtl.front(), mov);
        if(s[u]!=des[u]) ltr.push(u);
        while((!rtl.empty())&&(s[rtl.front()]==des[rtl.front()])) rtl.pop_front();
    }
    if(!rtl.empty()) bye();
    puts("YES");
    writeln(ans.size());
    for(auto x: ans) x.output();
}