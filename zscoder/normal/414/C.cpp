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

int a[(1<<20) + 10];

struct node
{
	vector<int> vec;
	ll a, b;
};

node st[(1<<22)+5];

void combine(int id)
{
	int l = (id<<1); int r = (l^1);
	int ptr = 0;
	ll ans = 0;
	int siz = st[r].vec.size();
	for(int i = 0; i < st[l].vec.size(); i++)
	{
		int val = st[l].vec[i];
		while(ptr < siz && st[r].vec[ptr] < val)
		{
			 ptr++;
		}
		ans += ptr;
	}
	st[id].a = ans;
	ptr = 0;
	ans = 0;
	siz = st[l].vec.size();
	for(int i = 0; i < st[r].vec.size(); i++)
	{
		int val = st[r].vec[i];
		while(ptr < siz && st[l].vec[ptr] < val)
		{
			 ptr++;
		}
		ans += ptr;
	}
	st[id].b = ans;
	st[id].vec.resize(2*siz);
	merge(st[l].vec.begin(), st[l].vec.end(), st[r].vec.begin(), st[r].vec.end(), st[id].vec.begin());
	//cerr << "END" << endl;
}

ll a1[22];
ll a2[22];

void build(int id, int l, int r, int lvl)
{
	if(r - l < 2)
	{
		st[id].a = 0;
		st[id].b = 0;
		st[id].vec.pb(a[l]);
		a1[lvl] = 0; a2[lvl] = 0;
		return ;
	}
	int mid = (l+r)>>1;
	build(2*id, l, mid, lvl-1);
	build(2*id+1, mid, r, lvl-1);
	combine(id);
	a1[lvl] += st[id].a; a2[lvl] += st[id].b;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int lg = n;
	n = (1<<n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	build(1, 0, n, lg);
	int m; cin >> m;
	/*
	for(int i = 0; i <= lg; i++)
	{
		cout << a1[i] << ' ' << a2[i] << '\n';
	}
	*/
	for(int i = 0; i < m; i++)
	{
		int x; cin >> x;
		ll sum = 0;
		for(int j = 0; j <= x; j++)
		{
			swap(a1[j], a2[j]);
		}
		for(int j = 0; j <= lg; j++)
		{
			sum += a1[j];
		}
		cout << sum << '\n';
	}
}