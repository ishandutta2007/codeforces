#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

struct node
{
	int h, ans;
};

node st[(1<<19)+5];
int a[(1<<17)+5];

void combine(int id)
{
	st[id].h = (st[id*2].h)^1;
	if(st[id].h)
	{
		st[id].ans = st[id*2].ans|st[id*2 + 1].ans;
	}
	else
	{
		st[id].ans = st[id*2].ans^st[id*2 + 1].ans;
	}
}

void build(int id, int l, int r)
{
	if(r - l < 2)
	{
		st[id].h = 0;
		st[id].ans = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(id*2, l, mid);
	build(id*2+1, mid, r);
	combine(id);
}

void update(int id, int l, int r, int p, int v)
{
	if(l > p || r <= p) return ;
	if(r - l < 2)
	{
		st[id].ans = v;
		return ;
	}
	int mid = (l+r)>>1;
	update(2*id, l, mid, p, v);
	update(2*id+1, mid, r, p, v);
	combine(id);
}

int query()
{
	return st[1].ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	n = (1<<n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	build(1, 0, n);
	for(int i = 0; i < m; i++)
	{
		int p, v;
		cin >> p >> v;
		p--;
		update(1, 0, n, p, v); 
		cout << query() << '\n';
	}
}