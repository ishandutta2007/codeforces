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
#define taskname "F"
ll it[4000001];
ll lz[4000001];
int n;
int a[1000001];
int last[1000001];
void update(int i, int l, int r, int u, int v){
    if(l>v||r<u) return;
    if(u<=l&&v>=r){
        it[i]+=r-l+1;
        lz[i]++;
    }
    else{
        int m=(l+r)/2;
        lz[2*i]+=lz[i];
        it[2*i]+=lz[i]*(m-l+1);
        lz[2*i+1]+=lz[i];
        it[2*i+1]+=lz[i]*(r-m);
        lz[i]=0;
        update(2*i, l, m, u, v);
        update(2*i+1, m+1, r, u, v);
        it[i]=it[2*i]+it[2*i+1];
    }
}
ll get(int i, int l, int r, int u, int v){
    if(l>v||r<u) return 0;
    if(u<=l&&v>=r) return it[i];
    else{
        int m=(l+r)/2;
        lz[2*i]+=lz[i];
        it[2*i]+=lz[i]*(m-l+1);
        lz[2*i+1]+=lz[i];
        it[2*i+1]+=lz[i]*(r-m);
        lz[i]=0;
        return (get(2*i, l, m, u, v)+get(2*i+1, m+1, r, u, v));
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n) read(a[i]);
    ll res=0;
    FOR(i, 1, n){
        update(1, 1, n, last[a[i]]+1, i);
        last[a[i]]=i;
        res+=get(1, 1, n, 1, i);
    }
    res=res*2-n;
    cout<<setprecision(10)<<fixed<<((ld(res))/(((ll)(n))*n));
}