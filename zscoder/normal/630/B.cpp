#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;
typedef long double ld;
const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << " is " << x << endl;
#define gcd __gcd
#define forp(i, begin, end) for (__typeof(end) i = (begin); i < (end); i++)
#define form(i, begin, end) for (__typeof(end) i = (begin); i >= (end); i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define scan scanf
#define print printf
#define mp make_pair

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
//__gcd(value1, value2)
//

/*bool comp(ii a, ii b)
{
	if(a.first != b.first) return (a.first < b.first);
	else return (a.second < b.second);
}
*/

/*Graph Struct (Unweighted), Weighted add another i
vvi graph;
vi empty;
forp(i, 0, n)
{
	graph[i].pb(empty);
}
*/

/*DFS
bool visited[MAX_N + 1];
memset(visited, false, sizeof(visited));

void dfs(int u)
{
	visited[u] = true;
	stack<int> s;
	s.push(u);
	int v, w;
	while(!s.empty())
	{
		v = s.top();
		s.pop();
		forp(i, 0, graph[v].size())
		{
			w = graph[v][i];
			if(!visited[w])
			{
				s.push(w);
			}
			visited[w] = true;
		}
	}
}
*/

/*BFS (SSSP Unweighted)
int dist[MAX_N + 1];
memset(dist, -1, sizeof(dist));

void bfs(int u)
{
	dist[u] = 0;
	queue<int> q;
	q.push(u);
	int v, w;
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		forp(i, 0, graph[v].size())
		{
			w = graph[v][i];
			if(dist[w] == -1)
			{
				dist[w] = dist[u] + 1;
				q.push(w);
			}
		}
	}
}
*/

/*
Dijkstra
ll dist[MAXN + 1];
void dijkstra(int v)
{
	dist[v] = 0;
	int u;
	priority_queue<ii, vii, less<ii> > > pq;
	pq.push(ii(dist[v], v));
	while(!pq.empty())
	{
		u = pq.top().second;
		pq.pop();
		forp(i, 0, graph[u].size())
		{
			ii p = graph[u][i]
			if(dist[p.first] > dist[u] + p.second)
			{
				d[p.first] = d[u] + p.second;
				pq.push(ii(d[p.first], p.first));
			}
		}
	}
}
*/

/*BIT Sample
ll tree[MAX_N + 1];
void update(int p, ll val)
{
	for(int i = p; i <= n; i += (i & -i))
	{
		tree[i] += val;
	}
}
ll sum(int p)
{
	ll ans = 0;
	for(int i = p; i > 0 ;i -= (i & -i))
	{
		ans += tree[i];
	}
	return ans;
}
*/

/*Segment Tree
ll tree[4*MAX_N + 1];
void build(int id = 1, int l = 0, int r = n)
{
	if(r - l < 2)
	{
		tree[id] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

void modify(int p, int x, int id = 1, int l = 0, int r = n)
{
	tree[id] += x - a[p];
	if(r - l < 2)
	{	
		a[p] = x;
		return ;
	}
	int mid = (l + r)/2;
	if(p < mid)
	{
		modify(p, x, id * 2, l, mid);
	}
	else
	{
		modify(p, x, id * 2 + 1, mid, r);
	}
}

ll sum(int x, int y, int id = 1, int l = 0, int r = n)
{
	if(x >= r || l >= y)	return 0;
	if(x <= l && r <= y)	return tree[id];
	int mid = (l+r)/2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}

//Lazy part
//Increase Update
ll lazy[4*MAX_N + 1];
void upd(int id, int l, int r, int x)
{
	lazy[id] += x;
	tree[id] += (r - l) * x;
}

void shift(int id, int l, int r)
{
	int mid = (l + r)/2;
	upd(id*2, l, mid, lazy[id]);
	upd(id*2 + 1, mid, r, lazy[id]);
	lazy[id] = 0;
}

void increase(int x, int y, ll v, int id = 1, int l = 0, int r = n)
{
	if(x >= r or l >= y)	return ;
	if(x <= l && r <= y)
	{
		upd(id, l, r, v);
		return ;
	}
	shift(id, l, r);
	int mid = (l+r)/2;
	increase(x, y, v, id * 2, l, mid);
	increase(x, y, v, id*2+1, mid, r);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll sum(int x, int y, int id = 1, int l = 0, int r = n)
{
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return tree[id];
	shift(id, l, r);
	int mid = (l+r)/2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}
*/

/*Mo's Algorithm (sqrt-decompression)
int block;
int cnt[MAX_N + 1];
bool cmp(iii x, iii y)
{
	if(x.first.first/block != y.first.first/block) return x.first.first/block < y.first.first/block;
	return x.first.second < y.first.second;
}

void add(int pos)
{
	
}

void remove(int pos)
{

}

int currL = 1, currR = 1;
for(int i=0; i<m; i++) 
{
	int L = q[i].first.first, R = q[i].first.second;
	while(currL < L) {
		remove(currL);
		currL++;
	}
	while(currL > L) {
		add(currL-1);
		currL--;
	}
	while(currR <= R) {
		add(currR);
		currR++;
	}
	while(currR > R+1) {
		remove(currR-1);
		currR--;
	}
	ans[q[i].i] = answer;
}
*/

/*KMP
void computeLPSArray(char *pat, int M, int *lps);
 
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}
 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example 
           // AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
*/

/*struct matrix {
  // N is the size of the matrix
  ll m[N][N];
  matrix()
  {
     memset(m,0,sizeof(m));
  }
  matrix operator * (matrix b)
	{
		matrix c = matrix();
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < N; ++j) 
                c.m[i][j] = (c.m[i][j] + m[i][k] * b.m[k][j]) % MOD;
    return c;
	}
  ...
};

matrix modPow(matrix m,ll n)
{
  if ( n == 0 )
    return unit; // the unit matrix - that is 1 for principal diagonal , otherwise 0
  matrix half = modPow(m,n/2);
  matrix out = half * half;
  if ( n % 2 )
    out = out * m;
  return out; 
}

*/


/*DSU (Values are -ve)
memset(par, -1, sizeof(par));
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/


bool prime[10000001];
vector<ll> primes;
void Sieve(int n)
{
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
	for(int i = 2; i <= n; i++)
	{
		if(prime[i])
		{
			primes.push_back(i);
		}
	}
}

bool is_prime(ll n)
{
	for(int i = 0; primes[i]*primes[i]<=n; i++)
    {
        if(n % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}

#define double long double
const double EPS = 1E-9;
const double PI = 3.1415926535897932384626433832795;
struct pt {
  double x, y;

  pt() {}
  pt(double x, double y): x(x), y(y) {}

  bool operator< (const pt& p) const {
    return x < p.x - EPS || abs(x - p.x) < EPS && y < p.y - EPS;
  }
};

struct line {
  double a, b, c;

  line() {}
  line(const pt& a, const pt& b) {
    this->a = a.y - b.y;
    this->b = -a.x + b.x;
    this->c = -a.x * this->a - a.y * this->b;

    double t = sqrt(this->a * this->a + this->b * this->b);
    this->a /= t;
    this->b /= t;
    this->c /= t;
  }

  double dist(const pt& p) {
    return a * p.x + b * p.y + c;
  }
};

//pt a[110];
//double ans;
//int n;

line perp(const pt& a, const pt& b) {
  line res;
  res.a = a.x - b.x;
  res.b = a.y - b.y;
  res.c = -res.a * (a.x + b.x) / 2 - res.b * (a.y + b.y) / 2;

  double t = sqrt(res.a * res.a + res.b * res.b);
  res.a /= t;
  res.b /= t;
  res.c /= t;
  return res;
}

#define det(a, b, c, d) (a * d - b * c)

bool intersect(const line& l1, const line& l2, pt& res) {
  double d = det(l1.a, l1.b, l2.a, l2.b);
  if (abs(d) < EPS)
    return false;

  res.x = -det(l1.c, l1.b, l2.c, l2.b) / d;
  res.y = -det(l1.a, l1.c, l2.a, l2.c) / d;
  return true;
}

double dist(const pt& a, const pt& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int sg(double a) {
  if (abs(a) < EPS)
    return 0;
  return a < 0 ? -1 : +1;
}

bool one_side(const pt& a, const pt& b, const pt& c, const pt& d) {
  line l(a, b);
  
  return sg(l.a * c.x + l.b * c.y + l.c) == sg(l.a * d.x + l.b * d.y + l.c);
}

bool inside(const pt& a, const pt& b, const pt& c, const pt& d) {
  return one_side(a, b, c, d) && one_side(a, c, b, d) && one_side(b, c, a, d);
}

vector<pair<double, pt> > v;

void divide(vector<pt>& a, line l, int s) {
  vector<pt> res;
  forn(i, a.size()) {
    pt& cur = a[i];
    pt& to = a[(i + 1) % a.size()];

    if (sg(l.dist(cur)) == s || sg(l.dist(cur)) == 0)
      res.pb(cur);
    if (sg(l.dist(cur)) * sg(l.dist(to)) < 0) {
      pt r;
      intersect(l, line(cur, to), r);
      res.pb(r);
    }
  }
  a = res;
}

bool inside(vector<pt>& a, pt b) {
  bool res = false;
  forn(i, a.size()) {
    pt p = a[i], q = a[(i + 1) % a.size()];
    if (min(p.x, q.x) - EPS <= b.x && b.x < max(p.x, q.x) - EPS) {
      double sy = p.y + (q.y - p.y) * (b.x - p.x) / (q.x - p.x);
      if (abs(sy - b.y) < EPS)
        return false;
      res ^= b.y < sy;
    }
  }

  return res;
}

double vec(pt a, pt b, pt c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double area(vector<pt> a) {
  double res = 0;
  forn(i, a.size() - 1)
    res += vec(a[0], a[i], a[i + 1]);
  return abs(res) / 2;
}

void rot(pt& a, double al) {
  double x = a.x * cos(al) - a.y * sin(al);
  double y = a.x * sin(al) + a.y * cos(al);
  a.x = x;
  a.y = y;
}

ll power(ll base, ll exp)
{
	ll ans = 1;
    while (exp != 0) 
	{
        if (exp % 2) 
		{    // q is odd
            ans = (ans * base)%MOD;
			exp--;
        }
        base = (base * base)%MOD;
        exp /= 2;
    }
	ans %= MOD;
	if(ans < 0)
	{
		ans += MOD;
	}
    return ans;
}


ll choose(ll n, ll r)
{
	if(r == 0)
	{
		return 1;
	}
	if(n == r)
	{
		return 1;
	}
	long long denom = 1;
	for (long long i = 2; i <= r; i++)
	{
		denom = (denom * i) % MOD;
	}
	long long res = 1;
	for (long long i = n; i > n - r; i--) 
	{
		res = (res * i) % MOD;
	}
	res = (res * power(denom, MOD - 2)) % MOD;
	return res;
}

#define fastio ios_base::sync_with_stdio(false)
#define read(x) scan("%d", &x);

//Main Program


/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ll n;
	cin >> n;
	cout << 25;
	return 0;
}
*/

/*c
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	ll ans = 1;
	for(int i = 0; i < n + 1; i++)
	{
		ans *= 2LL;
	}
	ans -= 2;
	cout << ans;
	return 0;
}
*/
/*D
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ll n;
	cin >> n;
	cout << 1 + 3*n*(n+1);
	return 0;
}
*/

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ld n;
	cin >> n;
	ld t;
	cin >> t;
	ld ans = n;
	ld constant =  1.000000011;
	ans *= pow(constant, t);
	cout << fixed << setprecision(20) << ans;
	return 0;
}


/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/