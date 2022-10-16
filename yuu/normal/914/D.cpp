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
#define taskname "D"
int n;
int a[500001];
int it[2000001];
void build(int i, int l, int r){
    if(l==r) it[i]=a[l];
    else{
        int m=(l+r)/2;
        build(2*i, l, m);
        build(2*i+1, m+1, r);
        it[i]=__gcd(it[2*i], it[2*i+1]);
    }
}
void update(int i, int l, int r, int u, int a){
    if(l==r) it[i]=a;
    else{
        int m=(l+r)/2;
        if(m>=u) update(2*i, l, m, u, a);
        else update(2*i+1, m+1, r, u, a);
        it[i]=__gcd(it[2*i], it[2*i+1]);
    }
}
int check(int i, int l, int r, int u, int v, int x){
    if(l>v||r<u) return 0;
    if(u<=l&&v>=r){
        if(it[i]%x==0) return 0;
        if(l==r) return l;
        if((it[2*i]%x)&&(it[2*i+1]%x))return -1;
        int m=(l+r)/2;
        if(it[2*i]%x) return check(2*i, l, m, u, v, x);
        return check(2*i+1, m+1, r, u, v, x);
    }
    else{
        int m=(l+r)/2;
        int res=check(2*i, l, m, u, v, x);
        if(res) return res;
        return check(2*i+1, m+1, r, u, v, x);
    }
}
int get(int i, int l, int r, int u, int v){
    if(l>v||r<u) return 0;
    if(u<=l&&v>=r) return it[i];
    else{
        int m=(l+r)/2;
        return __gcd(get(2*i, l, m, u, v), get(2*i+1, m+1, r, u, v));
    }
}
int q;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    FOR(i, 1, n) read(a[i]);
    build(1, 1, n);
    read(q);
    {
        int o, l, r, x, i, y, gl, gr;
        FOR(qq, 1, q){
            read(o);
            if(o==1){
                read(l);
                read(r);
                read(x);
                int res=check(1, 1, n, l, r, x);
                if(res==-1) puts("NO");
                else if(res==0) puts("YES");
                else{
                    if(res==l) gl=1;
                    else gl=get(1, 1, n, l, res-1)%x==0;
                    if(res==r) gr=1;
                    else gr=get(1, 1, n, res+1, r)%x==0;
                    if(gl&&gr) puts("YES");
                    else puts("NO");
                }
            }
            else{
                read(i);
                read(y);
                update(1, 1, n, i, y);
            }
        }
    }
}