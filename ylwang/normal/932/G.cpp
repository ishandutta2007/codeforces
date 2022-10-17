#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

template<typename _T>
void read( _T &x )
{
    x = 0; char s = getchar();int f = 1;
    while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + s - '0', s = getchar(); }
    x *= f;
}

template<typename _T>
void write( _T x )
{
    if( x < 0 ) { putchar( '-' ), x = -x; }
    if( 9 < x ) { write( x / 10 ); }
    putchar( x % 10 + '0' );
}

int g[MAXN], f[MAXN], slink[MAXN], dif[MAXN];
int ch[MAXN][26], fa[MAXN], len[MAXN];
char Snat[MAXN], S[MAXN];
int N, lst, siz;

int main()
{
    scanf( "%s", Snat + 1 ); N = strlen( Snat + 1 );
    for( int i = 1 ; i <= N >> 1 ; i ++ ) S[( i << 1 ) - 1] = Snat[i];
    for( int i = ( N >> 1 ) + 1 ; i <= N ; i ++ ) S[( N - i + 1 ) << 1] = Snat[i];
    int x, p, cur;
    f[0] = 1;
    fa[0] = ++ siz, len[1] = -1;
    for( int i = 1 ; i <= N ; i ++ )
    {
        x = S[i] - 'a';
        while( S[i] ^ S[i - len[lst] - 1] ) lst = fa[lst];
        if( ! ch[lst][x] )
        {
            cur = ++ siz, p = fa[lst]; len[cur] = len[lst] + 2;
            while( S[i] ^ S[i - len[p] - 1] ) p = fa[p];
            fa[cur] = ch[p][x], ch[lst][x] = cur;
            dif[cur] = len[cur] - len[fa[cur]], slink[cur] = ( dif[cur] == dif[fa[cur]] ) ? slink[fa[cur]] : fa[cur];
        }
        lst = ch[lst][x];
        for( p = lst ; p ; p = slink[p] )
        {
            g[p] = f[i - len[slink[p]] - dif[p]];
            if( slink[p] ^ fa[p] ) g[p] = ( g[p] + g[fa[p]] ) % mod;
            if( ! ( i & 1 ) ) f[i] = ( f[i] + g[p] ) % mod;
        }
    }
    write( f[N] ), putchar( '\n' );
    return 0;
}