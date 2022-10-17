#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "vector"
#include "chrono"
#include "random"
#include "map"
using namespace std;
#define ll long long
#define MAXN 500006
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int n , m;
vector<int> G[MAXN];
const int P = 1000000007 , Q = 501217111;
int bp , bq;
int pp[MAXN] , pq[MAXN];
long long c[MAXN];
long long s[MAXN];
map<pair<int,int>,int> M;
int cn = 0;
long long gcd( long long a , long long b ) {
    return !b ? a : gcd( b , a % b );
}
void solve( ) {
    scanf("%d%d",&n,&m);
    M.clear();
    for( int i = 1 ; i <= n ; ++ i ) scanf("%lld",&c[i]) , s[i] = 0 , G[i].clear();
    cn = 0;
    for( int i = 1 , u , v ; i <= m ; ++ i ) {
        scanf("%d%d",&u,&v);
        G[v].push_back( u );
    }
    for( int i = 1 ; i <= n ; ++ i ) {
        int retp = 0 , retq = 0;
        if( !G[i].size() ) continue;
        for( int v : G[i] ) {
            ( retp += pp[v] ) %= P;
            ( retq += pq[v] ) %= Q;
        }
        pair<int,int> fk = make_pair( retp , retq );
        if( !M[fk] ) M[fk] = ++ cn;
        s[M[fk]] += c[i];
    }
    long long res = s[1];
    for( int i = 2 ; i <= cn ; ++ i ) res = gcd( res , s[i] );
    printf("%lld\n",res);
}

int main() {
    bp = Rnd() % 10007 + 1 , bq = Rnd() % 100007 + 1;
    pp[0] = pq[0] = 1;
    for( int i = 1 ; i < MAXN ; ++ i ) pp[i] = 1ll * pp[i - 1] * bp % P , pq[i] = 1ll * pq[i - 1] * bq % Q;
    int T;cin >> T;
    while( T-- ) {
        solve();
    }
}