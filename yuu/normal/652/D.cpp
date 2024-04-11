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
#define taskname "D"
int n;
map <int, int> M;
class segment{
public:
    int l, r, id;
    void input(int id){
        read(l);
        read(r);
        M[l]=M[r]=0;
        this->id=id;
    }
    void fix(){
        l=M[l];
        r=M[r];
    }
} s[200001];
int ft[400001];
void update(int u){
    for(; u<=M.size(); u+=u&-u) ft[u]++;
}
int get(int u){
    int res=0;
    for(; u>0; u-=u&-u) res+=ft[u];
    return res;
}
int ans[200001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) s[i].input(i);
    int cnt=0;
    for(auto &t: M) t.second=++cnt;
    FOR(i, 1, n) s[i].fix();
    sort(s+1, s+n+1, [](segment A, segment B){
        return A.l>B.l;
    });
    FOR(i, 1, n){
        ans[s[i].id]=get(s[i].r);
        update(s[i].r);
    }
    FOR(i, 1, n) writeln(ans[i]);
}