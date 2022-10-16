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
#define taskname "D"
int n;
int k;
int f[35001];
int a[35001];
int b[35001];
int last[35001];
int it[35002*4];
int lazy[35002*4];
void update(int i, int l, int r, int u, int v, int x){
    if(u>r||v<l) return;
    if(u<=l&&v>=r){
        it[i]+=x;
        lazy[i]+=x;
    }
    else{
        int m=(l+r)/2;
        it[2*i]+=lazy[i];
        lazy[2*i]+=lazy[i];
        it[2*i+1]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        lazy[i]=0;
        update(2*i, l, m, u, v, x);
        update(2*i+1, m+1, r, u, v, x);
        it[i]=max(it[2*i], it[2*i+1]);
    }
}
int get(int i, int l, int r, int u, int v){
    if(u>r||v<l) return 0;
    if(u<=l&&v>=r) return it[i];
    else{
        int m=(l+r)/2;
        it[2*i]+=lazy[i];
        lazy[2*i]+=lazy[i];
        it[2*i+1]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        lazy[i]=0;
        return max(get(2*i, l, m, u, v), get(2*i+1, m+1,r, u, v));
    }
}
void init(int i, int l, int r){
    lazy[i]=0;
    if(l==r) it[i]=f[l];
    else{
        int m=(l+r)/2;
        init(2*i, l, m);
        init(2*i+1, m+1, r);
        it[i]=max(it[2*i], it[2*i+1]);
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(k);
    FOR(i, 1, n){
        read(a[i]);
        b[i]=last[a[i]];
        last[a[i]]=i;
    }
    FOR(cnt, 1, k){
        init(1, 0, n);
        FOR(i, 1, n){
            update(1, 0, n, 0, i-1, 1);
            if(b[i]) update(1, 0, n, 0, b[i]-1, -1);
            f[i]=get(1, 0, n, 0, i-1);
        }
    }
    writeln(f[n]);
}