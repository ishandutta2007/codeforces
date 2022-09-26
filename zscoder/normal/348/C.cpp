#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
//using namespace __gnu_pbds;

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
#define scan scanf
#define print printf
#define mp make_pair

/*typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}
//__gcd(value1, value2)
//

/*ll power(ll base, ll exp)
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
*/

/*
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
*/

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

/*
bool prime[10000001];
vector<int> primes;
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
*/

#define fastio ios_base::sync_with_stdio(false)
#define read(x) scan("%d", &x);
//Main Program
/*
bool prime[10000001];
vector<int> primes;
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

int main()
{
	fastio;
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	ll n;
	cin >> n;
	ll x = n*n + 1;
	Sieve(2000000);
	if(is_prime(x)) cout << "Yes";
	else cout << "No";
	return 0;
}
*/

/*
int a[1000001];
int dp[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		dp[a[i]] = 1;
	}
	sort(a, a + n);
	int ans = 0;
	int m = 1000000;
	for(int i = 1; i <= m; i++)
	{
		if(dp[i] != 0)
		{
			for(int j = 2*i; j <= m; j += i)
			{
				if(dp[j] != 0)
				{
					dp[j] = max(dp[j], dp[i] + 1);
				}
			}
		}
	}
	for(int i = 1; i <= m; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
*/

/*
#define inf 0x3f3f3f3f

int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int dp[101][1 << 16];
int a[111];
int mask[62];
int pre[101][1 << 16][2];

int main() 
{
	fastio;
	for(int i = 1; i <= 60; ++i)
	{
		for(int j = 0; j < 16; ++j)
		{
			if (i % pri[j] == 0)
			{
				mask[i] |= 1 << j;
			}
		}
	}
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	int m = 1 << 16;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			//cout << i << " " << j << endl;
			if (dp[i - 1][j] != inf) 
			{
				for(int k = 1; k <= 58; ++k) 
				{
					if ((j & mask[k]) == 0) 
					{
						int t = j | mask[k];
						int z = dp[i - 1][j] + abs(k - a[i]);
						if (z < dp[i][t])
						{
							dp[i][t] = z;
							pre[i][t][0] = k;
							pre[i][t][1] = j;
						}
					}
				}
			}
		}
	}	
	//cout << "JQWE" << endl;
	int ret = inf;
	int rc;
	for(int i = 0; i < m; ++i)
	{
		if (dp[n][i] < ret) 
		{
			ret = dp[n][i];
			rc = i;
		}
	}
	vi ans;
	for (int i = n; i >= 1; --i) 
	{
		ans.pb(pre[i][rc][0]);
		rc = pre[i][rc][1];
	}
	for (int i = n - 1; i >= 0; --i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
*/

/*
int a[100001];
int main()
{
	fastio; cin.tie(0);
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	if(k % 2)
	{
		for(int i = 0; i < (k+1)/2; i++)
		{
			a[2*i] = i+1;
		}
		for(int i = 0; i < (k+1)/2; i++)
		{
			a[2*i + 1] = k+1-i;
		}
		for(int i = k+1; i < n; i++)
		{
			a[i] = i+1;
		}
	}
	else
	{
		for(int i = 0; i < k/2+1; i++)
		{
			a[2*i] = i+1;
		}
		for(int i = 0; i < k/2+1; i++)
		{
			a[2*i + 1] = k+1-i;
		}
		for(int i = k+1; i < n; i++)
		{
			a[i] = i+1;
		}
	}
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}
*/

/*
char s[1001][1001];
int a[1001][1001];
int l[1001][1001];
int r[1001][1001];
int u[1001][1001];
int d[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	int n, m;
	while(t > 0)
	{
		memset(a, 0, sizeof(a));
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(u, 0, sizeof(u));
		memset(d, 0, sizeof(d));
		cin >> m >> n;
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cin >> s[i][j];
				a[i][j] = s[i][j] - '0';
			}
		}
		for(int i = 1; i <= m; i++)
		{
			for(int j = n; j >= 1; j--)
			{
				if(a[i][j])
				{
					l[i][j] = 1;
					if(a[i - 1][j])
					{
						l[i][j] = l[i - 1][j + 1] + 2;
					}
				}
			}
		}	
		for(int i = m; i >= 1; i--)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j])
				{
					r[i][j] = 1;
					if(a[i + 1][j])
					{
						r[i][j] = r[i + 1][j - 1] + 2;
					}
				}
			}
		}	
		for(int i = m; i >= 1; i--)
		{
			for(int j = n; j >= 1; j--)
			{
				if(a[i][j])
				{
					u[i][j] = 1;
					if(a[i][j + 1])
					{
						u[i][j] = u[i + 1][j + 1] + 2;
					}
				}
			}
		}	
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j])
				{
					d[i][j] = 1;
					if(a[i][j - 1])
					{
						d[i][j] = d[i - 1][j - 1] + 2;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j])
				{
					ans = max(ans, l[i][j]+d[i][j]+u[i][j]+r[i][j]-3);
				}
			}
		}
		cout << ans << endl;
		t--;
	}
	return 0;
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ll a;
	cin >> a;
	ll n = ll(1e17);
	n *= 18;
	//cout << n << endl;
	n %= a;
	ll k = n;
	//cout << n << endl;
	for(int i = 0; i < 44; i++)
	{
		n = (n + k)%a;
	}
	//cout << n << endl;
	if(n < 0)
	{
		n += a;
	}
	ll c = a - n; ll d = c + ll(1e18) - 1LL;
	cout << c << " " << d;
	return 0;
}
*/

/*A
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string a, b;
	cin >> a;
	cin >> b;
	int ans = 0;
	int x, y;
	int w, z;
	for(int i = 0; i < n; i++)
	{
		x = a[i] - '0';
		y = b[i] - '0';
		w = min(x, y);
		z = max(x, y);
		ans += min(z - w, w + 10 - z);
	}
	cout << ans;
	return 0;
}
*/

/*B
ld a[200001];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n, w;
	cin >> n >> w;
	for(int i = 0; i < 2*n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + 2*n);
	ld lo = 0;
	ld hi = 1e10;
	ld mid;
	while((hi - lo)>=1e-7)
	{
		mid = (lo+hi)/2;
		if(a[0] >= mid && a[n] >= 2*mid)
		{
			lo = mid;
		}
		else hi = mid;
	}
	//cout << lo << endl;
	ld answer;
	answer = lo*ld(n)*ld(3);
	answer = min(answer, ld(w));
	cout << fixed << setprecision(20) << answer;
	return 0;
}
*/

/*C
char b[20];
int a[20];
int power[4];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		a[i] = b[i] - '0';
		if(a[i] >= 2) power[0]++;
		if(a[i] >= 3) power[1]++;
		if(a[i] >= 4) power[0]+=2;
		if(a[i] >= 5) power[2]++;
		if(a[i] >= 6) {power[0]++; power[1]++;}
		if(a[i] >= 7) power[3]++;
		if(a[i] >= 8) power[0] += 3;
		if(a[i] >= 9) power[1]+=2;
	}
	//for(int i = 0; i < 4; i++) cout << power[i] << " ";
	for(int i = 0; i < power[3]; i++)
	{
		cout << 7;
		power[2]--;
		power[1] -= 2;
		power[0] -= 4;
	}
	for(int i = 0; i < power[2]; i++)
	{
		cout << 5;
		power[1]--;
		power[0] -= 3;
	}
	for(int i = 0; i < power[1]; i++)
	{
		cout << 3;
		power[0]--;
	}
	for(int i = 0; i < power[0]; i++)
	{
		cout << 2;
	}
	return 0;
}
*/

/*D
map<ll, ll> ma;
ll ans[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ll n;
	cin >> n;
	ll x;
	//cout << n << endl;
	for(ll i = 0; i < ll(n)*ll(n); i++)
	{
		cin >> x;
		ma[-1*x]++;
		//cout << -1*x << " " << ma[-1*x] << endl;
	}
	map<ll, ll>::iterator it;
	for(int i = n - 1; i >= 0; i--)
	{
		for(it = ma.begin(); it != ma.end(); ++it)
		{
			x = it->first;
			if(it->second > 0) break;
		}
		//cout << x << endl;
		ma[x]--;
		ans[i] = -1*x;
		for(int j = n - 1; j > i; j--)
		{
			ma[-1*gcd(ans[j], ans[i])] -= 2;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
*/

/*E
ll d[200001];
ll h[200001];
ll treel[800001];
ll treer[800001];
ll range[100001][2];
ll l[200001];
ll r[200001];
int n, m;

void initialize(int node, int b, int e, int mode)
{
	if (b == e)
	{
		if(mode == 1)
		{
			treel[node] = b;
		}
		else
		{
			treer[node] = b;
		}
	}
	else
	{
		//compute the values in the left and right subtrees
		initialize(2 * node, b, (b + e) / 2, mode);
		initialize(2 * node + 1, (b + e) / 2 + 1, e, mode);
		if(mode == 1)
		{
			if (l[treel[2*node]] >= l[treel[2 * node + 1]])
			{
				treel[node] = treel[2 * node];
			}
			else
			{
				treel[node] = treel[2 * node + 1]; 
			}
		}
		else
		{
			if (r[treer[2*node]] >= r[treer[2 * node + 1]])
			{
				treer[node] = treer[2 * node];
			}
			else
			{
				treer[node] = treer[2 * node + 1]; 
			}
		}
	}
} 

int query(int node, int b, int e, int i, int j, int mode)
{
	int p1, p2;
   
	if (i > e || j < b)
	{
		return -1;
	}
   
	if (b >= i && e <= j)
	{
		if(mode == 1)
		{
			return treel[node];
		}
		else
		{
			return treer[node];
		}
	}
   
	p1 = query(2 * node, b, (b + e) / 2, i, j, mode);
	p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j, mode);
   
	if (p1 == -1)
	{
		return p2;
	}
	if (p2 == -1)
	{
		return p1;
	}
	if(mode == 1)
	{
		if (l[p1] >= l[p2])
		{
			return p1;
		}
		return p2;
	}
	else
	{
		if (r[p1] >= r[p2])
		{
			return p1;
		}
		return p2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	l[0] = 0;
	r[0] = 0;
	d[0] = 0;
	h[0] = 0;
	for(int i = 1; i <= n; i++) 
	{
		cin >> d[i];
		d[n + i] = d[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> h[i];
		h[n + i] = h[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> range[i][0] >> range[i][1];
	}
	for(int i = 1; i <= 2*n; i++)
	{
		l[i] = 2*h[i];
		r[i] = 2*h[i];
		r[i] += (r[i-1]-2*h[i-1]+d[i-1]);
		l[i] -= (2*h[i-1]-l[i-1]+d[i-1]);
		//cout << l[i] << " " << r[i] << endl;
	}
	
	initialize(1, 1, 2*n, 1);
	initialize(1, 1, 2*n, 2);
	
	int left, right;
	int idxl, idxr, idx2l, idx2l2, idx2r, idx2r2;
	for(int i = 0; i < m; i++)
	{
		if(range[i][0] <= range[i][1])
		{
			left = range[i][1] + 1;
			right = range[i][0] + n - 1;
		}
		else
		{
			left = range[i][1] + 1;
			right = range[i][0] - 1;
		}
		//cout << left << " " << right << endl;
		idxl = query(1, 1, 2*n, left, right, 1);
		idxr = query(1, 1, 2*n, left, right, 2);
		//cout << idxl << " " << idxr << endl;
		if(idxl != idxr)
		{
			cout << l[idxl] + r[idxr] << endl;
		}
		else
		{
			idx2l = query(1, 1, 2*n, left, idxl - 1, 1);
			idx2l2 = query(1, 1, 2*n, idxl + 1, right, 1);
			idx2r = query(1, 1, 2*n, left, idxr - 1, 2);
			idx2r2 = query(1, 1, 2*n, idxr + 1, right, 2);
			if(idx2l == -1) idx2l = idx2l2;
			if(idx2l2 == -1) idx2l2 = idx2l;
			if(idx2r == -1) idx2r = idx2r2;
			if(idx2r2 == -1) idx2r2 = idx2r;
			//cout << idx2l << " " << idx2l2 << " " << idx2r << " " << idx2r2 << endl;
			cout << max(l[idxl] + max(r[idx2r], r[idx2r2]), r[idxr] + max(l[idx2l], l[idx2l2])) << endl;
		}
	}
	return 0;
}
*/


ll n, m, q;
ll a[100001];
ll SQRT = 350;
vector<ll> s[100001];
int id[100001];
bool found[400][100001];
int intersect[400][100001];
ll original[400];
ll add[400];
vector<ll> large;
ll k, el;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(found, false, sizeof(found));
	//freopen("input.txt", "r", stdin);
	//scanf("%d %d %d", &n, &m, &q);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
	{
		//scanf("%I64d", &a[i]);
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++)
	{
		//scanf("%d", &k);
		cin >> k;
		if(k > SQRT)
		{
			id[i] = int(large.size());
			large.pb(i);
		}
		for(int j = 0; j < k; j++)
		{
			//scanf("%d", &el);
			cin >> el;
			s[i].pb(el);
			if(k > SQRT)
			{
				found[id[i]][el] = true;
				original[id[i]] += a[el];
			}
		}
		sort(s[i].begin(), s[i].end());
	}
	for(int i = 0; i < large.size(); i++)
	{
		for(int j = 1; j <= m; j++)
		{
			for (int a = 0; a < s[j].size(); a++)
			{
                //if(*lower_bound(s[large[i]].begin(),s[large[i]].end(),s[j][a]) == s[j][a])
				if(found[i][s[j][a]])
				{
                    intersect[i][j]++;
				}
            }
		}
	}

	char mode; ll u, v, ans;
	for(int i = 0; i < q; i++)
	{
		//scanf("\n%c", &mode);
		cin >> mode;
		if(mode == '?')
		{
			ans = 0;
			//scanf("%d", &u);
			cin >> u;
			if(s[u].size() > SQRT)
			{
				ans += original[id[u]];
			}
			else
			{
				for(int j = 0; j < s[u].size(); j++)
				{
					ans += a[s[u][j]];
				}
			}
			for(int j = 0; j < large.size(); j++)
			{
				ans += ll(add[j]) * ll(intersect[j][u]);
			}
			cout << ans << endl;
		}
		else
		{
			//scanf("%d %d", &u, &v);
			cin >> u >> v;
			if(s[u].size() > SQRT)
			{
				add[id[u]] += ll(v);
			}
			else
			{
				for(int j = 0; j < s[u].size(); j++)
				{
					a[s[u][j]] += ll(v);
				}
				for(int j = 0; j < large.size(); j++)
				{
					original[j] += ll(v) * ll(intersect[j][u]);
				}
			}
		}
	}
	return 0;
}


/*559A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	ll ans = (a+b+c)*(a+b+c);
	ans -= (a*a+c*c+e*e);
	cout << ans;
	return 0;
}
*/

/*492A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	char x;
	int a = 0;
	int b = 0;
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			cin >> x;
			if(x == 'Q') a+=9;
			if(x == 'R') a+=5;
			if(x == 'B') a+=3;
			if(x == 'N') a+=3;
			if(x == 'P') a++;
			if(x == 'q') b+=9;
			if(x == 'r') b+=5;
			if(x == 'b') b+=3;
			if(x == 'n') b+=3;
			if(x == 'p') b++;
		}
	}
	if(a > b) cout << "White";
	else if(a == b) cout << "Draw";
	else cout << "Black";
	return 0;
}
*/

/*492A
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int sum = 0;
	int ans = 0;
	while(sum <= n)
	{
		sum += ((ans+2)*(ans+1))/2;
		if(sum <= n)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
*/

/*493D
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	if(n % 2) cout << "black";
	else cout << "white\n1 2";
	return 0;
}
*/

/*
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
vii vec;
ll dp[201000];
ll fact[201000];
ll invfact[201000];

ll choose(ll n, ll r)
{
	ll res = 0;
	res = ((fact[n] * invfact[r])%MOD * invfact[n - r])%MOD;
	if(res < 0) res += MOD;
	return res;
}

bool comp(ii a, ii b)
{
	if(a.fi + a.se != b.fi + b.se) return a.fi + a.se < b.fi + b.se;
	else return a.fi < b.fi;
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	fact[0] = 1;
	for (ll i = 1; i < 200010; ++i) 
	{
		fact[i] = (fact[i - 1] * i)%MOD;
		if(fact[i] < 0) fact[i] += MOD;
	}
	invfact[200009] = power(fact[200009], MOD - 2);
	for (ll i = 200008; i >= 0; --i) 
	{
		invfact[i] = (invfact[i + 1] * (i + 1))%MOD;
		if(invfact[i] < 0) invfact[i] += MOD;
	}
	int h, w, n;
	//cin >> h >> w >> n;
	scanf("%d %d %d", &h, &w, &n);
	int x, y;
	vec.pb(ii(0, 0));
	vec.pb(ii(h-1, w-1));
	for(int i = 0; i < n; i++)
	{
		//cin >> x >> y;
		scanf("%d %d", &x, &y);
		x--; y--;
		vec.pb(ii(x, y));
	}
	sort(vec.begin(), vec.end(), comp);
	dp[0] = 1;
	ll c, d;
	for(int i = 1; i < vec.size(); i++)
	{
		dp[i] = 0;
		c = vec[i].fi - vec[0].fi;
		d = vec[i].se - vec[0].se;
		if(c >= 0 && d >= 0)
		{
			dp[i] = choose(c + d, c);
		}
		for(int j = 1; j < i; j++)
		{
			c = vec[i].fi - vec[j].fi;
			d = vec[i].se - vec[j].se;
			if(c >= 0 && d >= 0)
			{
				dp[i] -= dp[j] * choose(c + d, c);
			}
			dp[i] %= MOD;
		}
		dp[i] %= MOD;
	}
	if(dp[vec.size() - 1] < 0) dp[vec.size() - 1] += MOD;
	//cout << dp[vec.size() - 1];
	printf("%I64d", dp[vec.size() - 1]);
	return 0;
}
*/

/*
bool prime[10000001];
vector<int> primes;
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

bool is_pal(ll n)
{
	vi digits;
	while(n > 0)
	{
		digits.pb(n%10);
		n /= 10;
	}
	for(int i = 0; i < digits.size(); i++)
	{
		if(digits[i] != digits[digits.size() - 1 - i]) return false;
	}
	return true;
}

ll prep[10000001];
ll prepal[10000001];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ll p, q;
	cin >> p >> q;
	Sieve(2000000);
	
	prime[1] = false;
	prep[0] = 0; prepal[0] = 0;
	ll ans = 1;
	for(int i = 1; i < 2000001; i++)
	{
		prep[i] = prep[i-1];
		if(prime[i]) prep[i]++;
		prepal[i] = prepal[i-1];
		if(is_pal(i)) prepal[i]++;
		if(q*prep[i] <= p*prepal[i])
		{
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
*/

/*Water Tree
const ll N = 1000010;
ll n, q;
vi vec[N];
ll start[N]; ll en[N];
ll counter = -1;
ll par[N];
void dfs(ll node, ll parent)
{
	start[node] = ++counter;
	par[node] = parent;
	for(ll i = 0; i < ll(vec[node].size()); i++)
	{
		if(vec[node][i] != parent)
		{
			dfs(vec[node][i], node);
		}
	}
	en[node] = counter;
}

ll lazy[2*N+1];
ll tree[2*N+1];

void upd(ll node, ll l, ll r)
{
	if (lazy[node])
	{
        lazy[node] = 0;
        tree[node] = 1;
        if (l != r)
		{
            lazy[2*node + 1] = 1;
            lazy[2*node + 2] = 1;
        }
    }
}

void update1(ll node, ll l, ll r, ll x, ll y) 
{
    upd(node, l, r);
    if (x > r || y < l) return ;
    if (x <= l && r <= y)
	{
        tree[node] = 1;
        lazy[node] = 1;
        upd(node, l, r);
        return ;
    }
	ll mid = (l + r)/2;
    update1(2*node + 1, l, mid, x, y);
    update1(2*node + 2, mid + 1, r, x, y);
    tree[node] = tree[2*node + 1] && tree[2*node + 2];
}

void update2(ll node, ll l, ll r, ll x) 
{
	upd(node, l, r);
    if (x > r || x < l) return ;
    tree[node] = 0;
    if (l == r) return ;
	ll mid = (l+r)/2;
    update2(2*node + 1, l, mid, x);
    update2(2*node + 2, mid + 1, r, x);
}

bool query(ll node, ll l, ll r, ll x, ll y) 
{
    upd(node, l, r);
    if (x > r || y < l) return 1;
    if (x <= l && r <= y) return tree[node];
	ll mid = (l+r)/2;
    return query(2*node + 1, l, mid, x, y) && query(2*node + 2, mid + 1, r, x, y);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	ll x, y;
	for(ll i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		x--; y--;
		vec[x].pb(y);
		vec[y].pb(x);
	}
	dfs(0, -1);
	memset(lazy, 0, sizeof(lazy));
	memset(tree, 0, sizeof(tree));
	cin >> q;
	for(ll i = 0; i < q; i++)
	{
		cin >> x >> y; y--;
		//cout << x << endl;
		if(x == 1)
		{
			if (!query(0, 0, n - 1, start[y], en[y])) 
			{
				//yes();
                update1(0, 0, n - 1, start[y], en[y]);
                if (par[y] != -1)
				{
					update2(0, 0, n - 1, start[par[y]]);
				}
            }
			
		}
		else if(x == 2)
		{
			update2(0, 0, n - 1, start[y]);
		}
		else
		{
			cout << query(0, 0, n - 1, start[y], en[y]) << endl;
		}
	}
	return 0;
}
*/

/*G
double dp[205][257][250][2];

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ll n, q, p2;
	cin >> n >> q >> p2;
	ld p = ld(p2)/ld(100);
	int cnt1 = 0;
	int cnt0 = 0;
	for(int i = 8; i < 31; i++)
	{
		if(n & (1<<i)) cnt1++;
		else break;
	}
	for(int i = 8; i < 31; i++)
	{
		if(n & (1<<i)) break;
		else cnt0++;
	}
	int cnt = 0;
	for(int j = 1; j <= 255; j++)
	{
		cnt = 0;
		for(int i = 0; i < 8; i++)
		{
			if(j & (1<<i)) break;
			else cnt++;
		}
		for(int i = 0; i < 250; i++)
		{
			dp[0][j][i][0] = dp[0][j][i][1] = cnt;
		}
	}
	for(int i = 0; i < 250; i++)
	{
		dp[0][0][i][0] = 8;
		dp[0][0][i][1] = 8 + i;
	}
	ld d1, d2;
	for(int i = 1; i <= q; i++)
	{
		for(int j = 0; j < 256; j++)
		{
			for(int k = 0; k < 250; k++)
			{
				for(int l = 0; l < 2; l++)
				{
					if((j & (1<<7)) && l == 0) d1 = dp[i-1][(j*2)%256][k+1][0];
					else if((j & (1<<7)) && l == 1) d1 = dp[i-1][(j*2)%256][1][0];
					else if(l == 0) d1 = dp[i-1][(j*2)%256][1][1];
					else d1 = dp[i-1][(j*2)%256][k+1][1];
					if(j != 255) d2 = dp[i-1][j+1][k][l];
					else if(l == 0) d2 = dp[i-1][0][k][1];
					else d2 = dp[i-1][0][1][0];
					dp[i][j][k][l] = p*d1 + (1-p)*d2;
				}
			}
		}
	}
	ld ans;
	if(cnt1 > 0) ans = dp[q][n%256][cnt1][0];
	else ans = dp[q][n%256][cnt0][1];
	cout << fixed << setprecision(20) << ans;
	return 0;
}
*/

/*
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
	if(res < 0) res += MOD;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ll n; cin>>n;
	ll ans = choose(2*n + 2, n + 1) - 1;
	if(ans < 0) ans += MOD;
	cout << ans;
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