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
#define taskname "1093E"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int n, m;
int a[200001];
int b[200001];
int f[200001];
ordered_set ft[200001];
void insert(int u, int v){
    for(; u<=n; u+=u&-u) ft[u].insert(v);
}
void erase(int u, int v){
    for(; u<=n; u+=u&-u) ft[u].erase(v);
}
int get(int u, int low, int high){
    int res=0;
    for(; u>0; u-=u&-u) res+=ft[u].order_of_key(high+1)-ft[u].order_of_key(low);
    return res;
}
void add_element(int u, int w){
    if(w==1) insert(u, b[u]);
    else erase(u, b[u]);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    FOR(i, 1, n){
        read(a[i]);
        f[a[i]]=i;
    }
    FOR(i, 1, n){
        read(b[i]);
        b[i]=f[b[i]];
    }
    FOR(i, 1, n) add_element(i, 1);
    {
        int o, x0, y0, x1, y1;
        FOR(i, 1, m){
            read(o);
            read(x0);
            read(y0);
            if(o==1){
                read(x1);
                read(y1);
                writeln(get(y1, x0, y0)-get(x1-1, x0, y0));
            }
            else{
                add_element(x0, -1);
                add_element(y0, -1);
                swap(b[x0], b[y0]);
                add_element(x0, 1);
                add_element(y0, 1);
            }
        }
    }
}