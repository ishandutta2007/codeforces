#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
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
#define taskname "A"
int n, m;
struct query{
    int t, l, r, v;
} q[5001];
ll add[5001];
ll a[5001];
ll b[5001];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    FOR(i, 1, m){
        read(q[i].t);
        read(q[i].l);
        read(q[i].r);
        read(q[i].v);
    }
    FOR(i, 1, n) a[i]=1000000000;
    FOR(i, 1, m){
        if(q[i].t==1) FOR(j, q[i].l, q[i].r) add[j]+=q[i].v;
        else FOR(j, q[i].l, q[i].r) a[j]=min(a[j], q[i].v-add[j]);
    }
    FOR(i, 1, n){
        if(abs(a[i])>1000000000){
            puts("NO");
            return 0;
        }
        b[i]=a[i];
    }
    FOR(i, 1, m){
        if(q[i].t==1) FOR(j, q[i].l, q[i].r) b[j]+=q[i].v;
        else{
            bool eq=0;
            FOR(j, q[i].l, q[i].r) if(b[j]==q[i].v) eq=1;
            else if (b[j]>q[i].v){
                puts("NO");
                return 0;
            }
            if(!eq){
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    FOR(i, 1, n){
        write(a[i]);
        putchar(' ');
    }
}