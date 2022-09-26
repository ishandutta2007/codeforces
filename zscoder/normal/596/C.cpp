#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 100000;

vector<ii> pt;
vi special[200001];
vi ptsp[200001];
int color[200001];
ii ans[200001];
int best[200001];
int st[800001];

void build(int id, int l, int r)
{
	if(r - l < 2)
	{
		st[id] = -1;
		return ;
	}
	int mid =(l+r)>>1;
	build(id*2, l, mid);
	build(id*2 + 1, mid, r);
	st[id] = max(st[id*2], st[id*2+1]);
}

void update(int id, int l, int r, int pos, int v)
{
	if(l > pos) return ;
	if(r <= pos) return ;
	if(r - l < 2)
	{
		st[id] = v;
		return ;
	}
	int mid = (l+r)>>1;
	update(id*2, l, mid, pos, v);
	update(id*2+1, mid, r, pos, v);
	st[id] = max(st[id*2], st[id*2+1]);
}

int query(int id, int l, int r, int ql, int qr)
{
	if(r <= ql || qr <= l) return -1;
	if(l >= ql && r <= qr) return st[id];
	int mid = (l+r)>>1;
	return max(query(id*2, l, mid, ql, qr), query(id*2+1, mid, r, ql, qr));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		ii x;
		cin >> x.fi >> x.se;
		pt.pb(x);
	}
	sort(pt.begin(), pt.end());
	for(int i = 0; i < n; i++)
	{
		ii x = pt[i];
		ptsp[x.se - x.fi + N].pb(i);	
	}
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		special[x+N].pb(i);
	}
	for(int i = 0; i < 200001; i++)
	{
		if(special[i].size() != ptsp[i].size())
		{
			cout << "NO";
			return 0;
		}
	}
	for(int i = 0; i < 200001; i++)
	{
		sort(ptsp[i].begin(), ptsp[i].end());
		for(int j = 0; j < special[i].size(); j++)
		{
			//cout << "COLOR : " << ptsp[i][j] << ' ' << special[i][j] << '\n';
			color[ptsp[i][j]] = special[i][j];
		}
	}
	memset(best, -1, sizeof(best));
	build(1, 0, 2*N+1);
	for(int i = 0; i < n; i++)
	{
		int y = pt[i].se;
		int maxcol = query(1, 0, N*2 + 1, 0, y+1+N);
		//cout << pt[i].fi << ' ' << pt[i].se << ' ' << color[i] << ' ' << maxcol << '\n';
		if(maxcol > color[i])
		{
			cout << "NO";
			return 0;
		}
		update(1, 0, N*2+1, y + N, color[i]);
	}
	cout << "YES" << '\n';
	for(int i = 0; i < n; i++)
	{
		ans[color[i]] = pt[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i-1].fi << ' ' << ans[i-1].se << '\n';
	}
	return 0;
}