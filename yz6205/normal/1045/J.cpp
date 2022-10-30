#include<bits/stdc++.h> 
#define rg 
#define fp( i , x , y ) for( rg int i=(x); i<=(y); ++i ) 
#define fq( i , x , y ) for( rg int i=(y); i>=(x); --i )  
#define ls lson[k] 
#define rs rson[k] 
using namespace std ; 
const int N = 1e5+10 , M = 5e6 , L = 205 ;  
int kmp[L] ; 
int n , pi[N] , a[N] ;  
vector <int> v[N] , edge[N] ; 
int in_li[N] , in_tr[N] , top[N] , pre[N] , son[N] , sz[N] , dep[N] , tot1 ; 
struct sam { 
  int tr[N*3][27] , fail[N*3] , len[N*3] , tot , tot2 ; 
  int rt[N*3] , s[M] , lson[M] , rson[M] ; 
  vector <int> vf[N*3] ; int val[N*3] ;  
  void prep( ) { tot = pi[1] = 1 ; tot2 = 0 ; }  
  void ins( int ax , int las , int x ) { 
    int u = ++tot , p = las ;  
    len[u] = len[las] + 1 ; 
    for( ; p && !tr[p][x] ; p = fail[p] ) tr[p][x] = u ; 
    if( !p ) fail[u] = 1 ; 
    else { 
      int q = tr[p][x] ;  
      if( len[q] == len[p] + 1 ) fail[u] = q ; 
	  else { 
	    int cq = ++tot ; 
	    fail[cq] = fail[q] ; len[cq] = len[p] + 1 ; 
	    fail[u] = fail[q] = cq ; 
	    memcpy( tr[cq] , tr[q] , sizeof(tr[cq]) ) ; 
	    for( ; p && tr[p][x] == q ; p = fail[p] ) tr[p][x] = cq ;  
	  } 
	} 
	pi[ax] = u ; val[u] = ax ; 
  } 
  void upd( int &k , int l , int r , int x ) { 
    int tk = ++tot2 ; 
	lson[tk] = ls ; rson[tk] = rs ; k = tk ; 
    if( l == r ) { s[k] = 1 ; return ; } 
    int mid=l+r>>1 ; 
    if( x<=mid ) upd( ls , l , mid , x ) ; 
    else upd( rs , mid+1 , r , x ) ; 
    s[k] = s[ls] + s[rs] ; 
  } 
  int merge( int x , int y ) { 
    if( !x || !y ) return x + y ; 
	int k = ++tot2 ; 
	ls = merge( lson[x] , lson[y] ) ; 
	rs = merge( rson[x] , rson[y] ) ; 
	s[k] = s[ls] + s[rs] ; return k ; 
  } 
  int query( int k , int l , int r , int x , int y ) { 
    if( !k || x > y ) return 0 ; 
    if( x <= l && r <= y ) return s[k] ; 
    int mid=l+r>>1 , tp=0 ; 
    if( x<=mid ) tp += query( ls , l , mid , x , y ) ; 
    if( mid<y ) tp += query( rs , mid+1 , r , x , y ) ; 
    return tp ; 
  } 
  void dfs( int x ) { 
    int l = vf[x].size() , y ; 
    fp( i , 0 , l-1 ) { 
      y = vf[x][i] ; dfs( y ) ; 
      rt[x] = merge( rt[x] , rt[y] ) ; 
	} 
	if( val[x] ) upd( rt[x] , 1 , n , in_li[val[x]] ) ;  
  } 
  void build( ) { 
    fp( i , 1 , tot ) vf[fail[i]].push_back(i) ; dfs( 1 ) ; 
  } 
} sa ; 
void add( int x , int y , int z ) { 
  v[x].push_back(y) ; edge[x].push_back(z) ; 
} 
void dfs1( int x , int _fa ) { 
  pre[x] = _fa ; 
  sz[x] = 1 ; 
  dep[x] = dep[_fa] + 1 ; 
  int l = v[x].size() , y , z ;  
  fp( i , 0 , l-1 ) { 
    y = v[x][i] ; z = edge[x][i] ; 
    if( y == _fa ) continue ; 
    a[y] = z ; sa.ins( y , pi[x] , z ) ; 
    dfs1( y , x ) ;   
    sz[x] += sz[y] ; 
    if( sz[son[x]] < sz[y] ) 
      son[x] = y ; 
  } 
} 
void dfs2( int x ) { 
  if( son[x] ) { 
    in_li[son[x]] = ++tot1 ; 
    in_tr[tot1] = son[x] ; 
    top[son[x]] = top[x] ; 
    dfs2( son[x] ) ; 
  } 
  int l = v[x].size() , y ; 
  fp( i , 0 , l-1 ) { 
    y = v[x][i] ; 
    if( y == pre[x] || y == son[x] ) continue ; 
	in_li[y] = ++tot1 ; 
	in_tr[tot1] = y ; top[y] = y ; 
	dfs2( y ) ;  
  } 
} 
int lca( int x , int y ) { 
  int fx = top[x] , fy = top[y] ; 
  while( fx != fy ) { 
    if( dep[fx] < dep[fy] ) swap( x , y ) , swap( fx , fy ) ; 
    x = pre[fx] ; fx = top[x] ; 
  }  
  return ( dep[x] < dep[y] ? x : y ) ; 
} 
int ask_d( int x , int z , int d ) { 
  if( dep[x] - dep[z] + 1 <= d ) return -1 ; 
  int fx = top[x] ; 
  while( fx != top[z] ) {  
    if( dep[fx] <= d + dep[z] ) break ; 
    x = pre[fx] ; fx = top[x] ; 
  } 
  return in_tr[ in_li[fx] + (d-dep[fx]+dep[z]) ] ; 
} 
int ask( int x , int z , int p ) { 
  if( z == -1 ) return 0 ;  
  int fx = top[x] , ans = 0 ;  
  while( fx != top[z] ) { 
    ans += sa.query( p , 1 , n , in_li[fx] , in_li[x] ) ; 
	x = pre[fx] ; fx = top[x] ;  
  } 
  ans += sa.query( p , 1 , n , in_li[z] , in_li[x] ) ; 
  return ans ; 
} 
signed main( ) { 
  ios::sync_with_stdio(false) ; 
  cin.tie(0) ; 
  cin >> n ; 
  int x , y ; string z , tp , tp1 , tp2 ;  
  fp( i , 1 , n-1 ) { 
    cin >> x >> y >> z ; 
    add( x , y , z[0]-'a' ) ; add( y , x , z[0]-'a' ) ; 
  } 
  sa.prep( ) ; 
  dfs1( 1 , 0 ) ; 
  in_li[1] = in_tr[1] = top[1] = tot1 = 1 ; 
  dfs2( 1 ) ; 
  sa.build( ) ; 
  int q ; cin >> q ; 
  while( q -- ) { 
    cin >> x >> y >> z ; 
    int ans = 0 , l1 = z.length() , c = lca( x , y ) ; 
    int fx = ask_d( x , c , l1 ) , fy = ask_d( y , c , l1 ) ; 
    int px = 1 , py = 1 ; 
    fq( i , 0 , l1-1 ) px = sa.tr[px][z[i]-'a'] ; 
    fp( i , 0 , l1-1 ) py = sa.tr[py][z[i]-'a'] ; 
	ans = ask( x , fx , sa.rt[px] ) + ask( y , fy , sa.rt[py] ) ; 
	x = ( fx == -1 ? x : pre[fx] ) ; y = ( fy == -1 ? y : pre[fy] ) ; 
	tp1 = "" ; tp2 = "" ; 
	for( ; x != c ; x = pre[x] ) tp1 += (char)(a[x]+'a'); 
	for( ; y != c ; y = pre[y] ) tp2 += (char)(a[y]+'a') ; 
	int l2 = tp2.length() ; 
	fp( i , 1 , l2/2 ) swap( tp2[i-1] , tp2[l2-i] ) ; 
	tp = tp1 + tp2 ; int tl = tp.length() ; 
	tp = " " + tp ; z = " " + z ; 
	int j = 0 ; 
	fp( i , 2 , l1 ) { 
	  while( j && z[j+1] != z[i] ) j = kmp[j] ; 
	  if( z[j+1] == z[i] ) j ++ ; kmp[i] = j ;    
	} 
	j = 0 ; 
	fp( i , 1 , tl ) { 
	  while( j && z[j+1] != tp[i] ) j = kmp[j] ; 
	  if( z[j+1] == tp[i] ) j ++ ; 
	  if( j == l1 ) { ans ++ ; j = kmp[j] ; }  
	} 
	cout << ans << '\n' ; 
  } 
  return 0 ; 
}