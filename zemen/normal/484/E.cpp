#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;

#define NAME "e"

int a[100001];
pair <int, int> h[100001];
int n;

struct node
{
	node *l, *r;
	int suff, pref, best, len;
	
	node(): l(0), r(0), suff(0), pref(0), best(0), len(0) {}
	
};

node *root[100001];

node *build(int n)
{
	node *v = new node();
	if (n == 1)
	{
		v->len = 1;
		return v;
	}
	v->l = build(n / 2);
	v->r = build(n - n / 2);
	v->len = n;
	return v;
}

node combine(node a, node b)
{
	if (a.len == 0)
		return b;
	if (b.len == 0)
		return a;
	node res;
	if (a.best == a.len)
		res.pref = a.len + b.pref;
	else
		res.pref = a.pref;
	if (b.best == b.len)
		res.suff = a.suff + b.len;
	else
		res.suff = b.suff;
	res.best = max(max(a.best, b.best), a.suff + b.pref);
	res.len = a.len + b.len;
	return res;
}

node *put(int pos, node *v)
{
	if (v->len == 1)
	{
		node *nv = new node(*v);
		nv->best = nv->pref = nv->suff = 1;
		return nv;
	} else if (pos < v->l->len) {
		node *l = put(pos, v->l);
		node *res = new node(combine(*l, *v->r));
		res->l = l, res->r = v->r;
		return res;
	} else {
		node *r = put(pos - v->l->len, v->r);
		node *res = new node(combine(*v->l, *r));
		res->l = v->l, res->r = r;
		return res;
	}
}

node get(int l, int r, node *v)
{
	assert(v);
	l = max(l, 0);
	r = min(r, v->len);
	if (l >= r)
		return node();
	if (l == 0 && r == v->len)
		return *v;
	return combine(get(l, r, v->l), get(l - v->l->len, r - v->l->len, v->r));
}

int main()
{
	#ifdef LOCAL
	freopen(NAME ".in", "r", stdin);
	#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		h[i] = make_pair(a[i], i);
	}
	sort(h, h + n);
	reverse(h, h + n);
	root[0] = build(n);
	for (int i = 0; i < n; ++i)
	{
		root[i + 1] = put(h[i].second, root[i]);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int l, r, w;
		scanf("%d%d%d", &l, &r, &w);
		--l;
		int lb = 0, rb = n;
		while (lb + 1 < rb)
		{
			int c = (lb + rb) / 2;
			//~ cerr << "get " << l << ' ' << r << ' ' << c << ' ' << get(l, r, root[c]).best << '\n';
			if (get(l, r, root[c]).best >= w)
				rb = c;
			else
				lb = c;
		}
		cout << h[rb - 1].first << '\n';
	}
}