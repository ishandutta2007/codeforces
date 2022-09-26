#include <bits/stdc++.h>

using namespace std;

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

const int MOD = 1e9 + 7;
const ll INF = ll(1e18);

#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << " is " << x << endl;
#define gcd __gcd
#define forp(i, begin, end) for (__typeof(end) i = (begin); i < (end); i++)
#define form(i, begin, end) for (__typeof(end) i = (begin); i >= (end); i--)
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

//Main Program

/*A
vi result;
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int i = 1;
	while(n > 0)
	{
		if(n % 2)
		{
			result.pb(i);
			n--;
		}
		n /= 2;
		i++;
	}
	reverse(result.begin(), result.end());
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}
*/

/*B
int a[100][100];
int ans[100];
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(ans, -1, sizeof(ans));
	for(int i = 0; i < n; i++)
	{
		vi vec;
		for(int j = 0; j < n; j++)
		{
			vec.pb(a[i][j]);
		}
		sort(vec.begin(), vec.end());
		for(int j = 0; j < n - 1; j++)
		{
			if(vec[j] == vec[j + 1])
			{
				ans[i] = vec[j];
				break;
			}
		}
	}
	
	int count = n - 1;
	for(int i = 0; i < n; i++)
	{
		if(ans[i] != -1)
		{
			cout << ans[i] << " ";
		}
		else
		{
			cout << count << " ";
			count++;
		}
	}
	return 0;
}
*/

viii starx;
viii stary;

bool comp(iii a, iii b)
{
	if(a.fi.fi != b.fi.fi) return (a.fi.fi < b.fi.fi);
	else return (a.fi.se < b.fi.se);
}


bool comp2(iii a, iii b)
{
	if(a.fi.se != b.fi.se) return (a.fi.se < b.fi.se);
	else return (a.fi.fi < b.fi.fi);
}


bool check(iii a, iii b, iii c)
{
	ll ax = a.fi.fi;
	ll ay = a.fi.se;
	ll bx = b.fi.fi;
	ll by = b.fi.se;
	ll cx = c.fi.fi;
	ll cy = c.fi.se;
	if(ax == bx || bx == cx)
	{
		if(ax == bx && bx == cx)
		{
			return false;
		}
		return true;
	}
	ll res1, res2;
	res1 = (bx - ax)*(cy - by);
	res2 = (cx - bx)*(by - ay);
	if(res1 == res2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int x, y;
	forp(i, 0, n)
	{
		cin >> x >> y;
		starx.pb(iii(make_pair(x, y), i + 1));
		stary.pb(iii(make_pair(x, y), i + 1));
	}
	sort(starx.begin(), starx.end(), comp);
	sort(stary.begin(), stary.end(), comp2);
	for(int i = 0; i < n - 2; i++)
	{
		if(check(starx[i], starx[i + 1], starx[i + 2]))
		{
			cout << starx[i].se << " " << starx[i + 1].se << " " << starx[i + 2].se;
			return 0;
		}
	}
	for(int i = 0; i < n - 2; i++)
	{
		if(check(stary[i], stary[i + 1], stary[i + 2]))
		{
			cout << stary[i].se << " " << stary[i + 1].se << " " << stary[i + 2].se;
			return 0;
		}
	}
	return 0;
}


/*D
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*E
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*F
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/

/*G
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	
	return 0;
}
*/