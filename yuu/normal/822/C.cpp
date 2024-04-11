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
#define l first
#define r second
int n, x;
struct voucher{
    int l, r;
    ll cost;
} p[200001];
const ll inf=1LL<<50;
ll mincost[200001];
bool cmp(voucher a, voucher b){
    return a.l<b.l;
}
struct stcmp{
    bool operator () (voucher a, voucher b){
        return a.r>b.r;
    }
};
priority_queue <voucher, vector <voucher>, stcmp> q;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(x);
    FOR(i, 1, x) mincost[i]=inf;
    FOR(i, 1, n){
        read(p[i].l);
        read(p[i].r);
        read(p[i].cost);
    }
    sort(p+1, p+n+1, cmp);
    ll ans=inf;
    FOR(i, 1, n){
        int sz;
        while(!q.empty()&&q.top().r<p[i].l){
            sz=q.top().r-q.top().l+1;
            mincost[sz]=min(mincost[sz], q.top().cost);
            q.pop();
        }
        if(p[i].r-p[i].l+1>=x) continue;
        ans=min(ans, mincost[x-(p[i].r-p[i].l+1)]+p[i].cost);
        q.push(p[i]);
    }
    if(ans==inf) puts("-1");
    else writeln(ans);
}