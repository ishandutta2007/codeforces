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
	res = (res * power(denom, p- 2)) % MOD;
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
/*A
int main()
{
	fastio;
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int m = s.length();
	int u, d, l, r;
	ll ans = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = i + 1; j < m; j++)
		{
			u = 0;
			d = 0;
			l = 0;
			r = 0;
			for(int k = i; k <= j; k++)
			{
				if(s[k] == 'U') u++;
				else if(s[k] == 'D') d++;
				else if(s[k] == 'L') l++;
				else r++;
			}
			if(u == d && r == l)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
*/

/*B
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	string s;
	cin >> n;
	cin >> s;
	int r = 0, b = 0, g = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == 'R') r++;
		else if(s[i] == 'B') b++;
		else g++;
	}
	if(r == 0 && b == 0)
	{
		cout << "G";
	}
	else if(r == 0 && g == 0)
	{
		cout << "B";
	}
	else if(g == 0 && b == 0)
	{
		cout << "R";
	}
	else if(r > 0 && b > 0 && g > 0)
	{
		cout << "BGR";
	}
	else if(r == 0)
	{
		if(b > 1 && g > 1)
		{
			cout << "BGR";
		}
		else if(b == 1 && g == 1)
		{
			cout << "R";
		}
		else if(b == 1)
		{
			cout << "BR";
		}
		else if(g == 1)
		{
			cout << "GR";
		}
	}
	else if(g == 0)
	{
		if(b > 1 && r > 1)
		{
			cout << "BGR";
		}
		else if(b == 1 && r == 1)
		{
			cout << "G";
		}
		else if(b == 1)
		{
			cout << "BG";
		}
		else if(r == 1)
		{
			cout << "GR";
		}
	}
	else if(b == 0)
	{
		if(r > 1 && g > 1)
		{
			cout << "BGR";
		}
		else if(r == 1 && g == 1)
		{
			cout << "B";
		}
		else if(r == 1)
		{
			cout << "BR";
		}
		else if(g == 1)
		{
			cout << "BG";
		}
	}
	return 0;
}
*/


int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ll n, m;
	cin >> n >> m;
	ll ans = ll(1e18);
	ll lo = 0; ll hi = ll(1e18);
	ll mid;
	ll a, b;
	ll give;
	while(lo <= hi)
	{
		mid = (lo + hi)/2;
		a = mid/2 - mid/6;
		b = mid/3 - mid/6;
		give = 0;
		give += max(0LL, m - b);
		give += max(0LL, n - a);
		if(give <= mid/6)
		{
			//cout << give << " " << mid << " " << mid/6 << endl;
			ans = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << ans;
	return 0;
}


/*D
int a[2001];
ll d[5001];
ll dp[5001];
int main()
{
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	read(n);
	for(int i = 0; i < n; i++)
	{
		read(a[i]);
	}
	sort(a, a + n);
	ll ans = 0;
	memset(dp, 0, sizeof(dp));
	memset(d, 0, sizeof(d));
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			d[a[j]-a[i]]++;
		}
	}
	dp[5000] = d[5000];
	for(int i = 4999; i >= 0; i--)
	{
		dp[i] = dp[i+1] + d[i];
	}
	ll total = (n*(n-1))/2;
	total = (total * total * total);
	ld answer = 0;
	ld tmp;
	for(int i = 1; i <= 4999; i++)
	{
		for(int j = 1; j <= 4999; j++)
		{
			tmp = d[i]*d[j];
			tmp /= total;
			if(i + j + 1 > 5000)
			{
				tmp = 0;
			}
			else
			{
				tmp = tmp*dp[i+j+1];
			}
			answer += tmp;
		}
	}
	cout << fixed << setprecision(15) << answer;
	return 0;
}
*/

/*E
int a[200001];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	if(n <= 2)
	{
		cout << 1 << endl;
		cout << a[0];
	}
	else
	{
		long double ans = 0;
		int k = 3;
		int d = 0, b = 1, c = 2;
		double tmp;
		for(int i = 1; i < n - 1; i++)
		{
			tmp = ld(a[i-1] + a[i] + a[n-1]);
			tmp /= 3;
			tmp -= a[i];
			if(tmp > ans)
			{
				d = i - 1;
				b = i;
				c = n - 1;
				k = 3;
				ans = tmp;
			}
		}
		int w = 0, x = 1, y = 2, z = 3;
		for(int i = 1; i < n - 2; i++)
		{
			tmp = ld(a[i-1] + a[i] + a[i + 1] + a[n-1]);
			tmp /= 4;
			tmp -= ld(a[i]+a[i+1])/2.0;
			if(tmp > ans)
			{
				w = i - 1;
				x = i;
				y = i + 1;
				z = n - 1;
				k = 4;
				ans = tmp;
			}
		}
		if(k == 3)
		{
			cout << 3 << endl;
			cout << a[d] << " " << a[b] << " " << a[c];
		}
		else if(k == 4)
		{
			cout << 4 << endl;
			cout << a[w] << " " << a[x] << " " << a[y] << " " << a[z];
		}
	}
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