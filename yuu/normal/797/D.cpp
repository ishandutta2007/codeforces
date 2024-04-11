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
#define left Nikola
#define right Tesla
int n;
int v[100001];
int left[100001];
int right[100001];
int parent[100001];
map <int, int> M;
map <int, bool> good;
int root;
int ans=0;
void dfs(int u, int low, int high){
    if((v[u]>=low)&&(v[u]<=high)) good[v[u]]=1;
    if(left[u]!=-1) dfs(left[u], low, min(v[u]-1, high));
    if(right[u]!=-1) dfs(right[u], max(low, v[u]+1), high);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n){
        read(v[i]);
        M[v[i]]++;
        read(left[i]);
        read(right[i]);
        if(left[i]!=-1) parent[left[i]]=i;
        if(right[i]!=-1) parent[right[i]]=i;
    }
    FOR(i, 1, n) if(!parent[i]) root=i;
    dfs(root, -2e9, 2e9);
    for(auto t: M){
        if(!good[t.first]) ans+=t.second;
    }
    writeln(ans);
}