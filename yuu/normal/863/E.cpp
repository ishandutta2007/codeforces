#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
int n, m;
int it[1200000*4+1];
int lz[1200000*4+1];
vector <int> v;
int l[200001];
int r[200001];
map <int, int> M;
inline void down(int i){
    it[2*i]+=lz[i];
    it[2*i+1]+=lz[i];
    lz[2*i]+=lz[i];
    lz[2*i+1]+=lz[i];
    lz[i]=0;
}
void update(int i, int l, int r, int u, int v){
    if(l>v||r<u) return;
    if(u<=l&&v>=r){
        it[i]++;
        lz[i]++;
    }
    else{
        down(i);
        int m=(l+r)/2;
        update(2*i, l, m, u, v);
        update(2*i+1, m+1, r, u, v);
        it[i]=min(it[2*i], it[2*i+1]);
    }
}
int get(int i, int l, int r, int u, int v){
    if(l>v||r<u) return 1e8;
    if(u<=l&&v>=r) return it[i];
    else{
        down(i);
        int m=(l+r)/2;
        return min(get(2*i, l, m, u, v), get(2*i+1, m+1, r, u, v));
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n){
        read(l[i]);
        read(r[i]);
        v.pb(l[i]);
        v.pb(r[i]);
        v.pb(l[i]+1);
        v.pb(l[i]-1);
        v.pb(r[i]+1);
        v.pb(r[i]-1);
    }
    sort(v.begin(), v.end());
    for(int x: v){
        if(M.find(x)==M.end()){
            m++;
            M[x]=m;
        }
    }
    FOR(i, 1, n){
        l[i]=M[l[i]];
        r[i]=M[r[i]];
        update(1, 1, m, l[i], r[i]);
    }
    FOR(i, 1, n){
        if(get(1, 1, m, l[i], r[i])>1){
            write(i);
            return 0;
        }
    }
    write(-1);
}