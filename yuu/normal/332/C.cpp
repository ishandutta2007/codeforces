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
#define taskname "C"
int n, p, k;
struct order{
    int a, b, i, j;
    bool operator <(order x){
        return (b<x.b)||(b==x.b&&a>x.a);
    }
} v[100001];
vector <order> q;
bool cmp (order a, order b){
    return (a.a>b.a)||(a.a==b.a&&a.j>b.j);
}
bool cmp2 (order a, order b){
    return a.b>b.b;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(p);
    read(k);
    FOR(i, 1, n){
        read(v[i].a);
        read(v[i].b);
        v[i].i=i;
    }
    sort(v+1, v+n+1);
    FOR(i, 1, n) v[i].j=i;
    sort(v+p-k+1, v+n+1, cmp);
    int pos=n;
    FOR(i, p-k+1, p){
        write(v[i].i);
        pos=min(pos, v[i].j);
        putchar(' ');
    }
    FOR(i, 1, n) if(v[i].j<pos){
        q.pb(v[i]);
    }
    sort(q.begin(), q.end(), cmp2);
    FFOR(i, 0, p-k) write(q[i].i), putchar(' ');
}