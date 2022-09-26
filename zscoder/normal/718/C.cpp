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

const int MOD = 1e9 + 7;

ll modpow(ll a, ll b)
{
	ll r = 1;
	while(b)
	{
		if(b&1) r = (r*a)%MOD;
		a = (a*a)%MOD;
		b>>=1;
	}
	return r;
}

ll inv(ll a)
{
	return modpow(a, MOD - 2);
}

struct number
{
	ll a, b;
};

ll Plus(ll a, ll b)
{
	//return (a+b)%MOD;
	return a+b;
}

ll Minus(ll a, ll b)
{
	return a-b;
	/*
	ll res = (a-b)%MOD; if(res<0) res+=MOD;
	return res;
	*/
}

ll times(ll a, ll b)
{
	a%=MOD;b%=MOD;
	return (a*b)%MOD;
}

ll relax(ll a)
{
	a%=MOD; if(a<0) a+=MOD;
	return a;
}

number add(number x, number y)
{
	number res;
	res.a = Plus(x.a, y.a);
	res.b = Plus(x.b, y.b);
	return res;
}

number subtract(number x, number y)
{
	number res;
	res.a = Minus(x.a, y.a);
	res.b = Minus(x.b, y.b);
	return res;
}

ll inv2; ll inv5;

number mult(number x, number y)
{
	number res;
	res.a = Plus(times(x.a, y.a), times(x.b, y.b*5));
	res.b = Plus(times(x.a, y.b), times(x.b, y.a));
	return res;
}

number invert(number x)
{
	number res;
	res.a = x.b;
	res.b = times(x.a, inv5);
	return res;
}

number one;
ll a[100001];
number m1, m2;
number zero;
number M1[63];
number M2[63];

number powercalc(number x, ll n)
{
	if(n == 0) return one;
	if(n == 1) return x;
	number res;
	res = powercalc(x, n/2LL);
	res = mult(res, res);
	if(n&1) res = mult(res, x);
	return res;
}

number power(number x, ll n)
{
	if(n == 0) return one;
	if(n == 1) return x;
	number res = one;
	int mode;
	if((x.a==m1.a)&&(x.b==m1.b)) mode = 1;
	else mode = 2;
	for(int i = 0; i < 45; i++)
	{
		if(n&(1LL<<i))
		{
			if(mode == 1) res = mult(res, M1[i]);
			else res = mult(res, M2[i]);
		}
	}
	return res;
}

struct node
{
	number ans1, ans2;
	number lazy1, lazy2;
};

node st[400001];

void combine(int id)
{
	int l = (id<<1); int r = (l^1);
	st[id].ans1 = add(st[l].ans1, st[r].ans1);
	st[id].ans2 = add(st[l].ans2, st[r].ans2);
}

void build(int id, int l, int r)
{
	if(r - l < 2)
	{
		st[id].ans1 = power(m1, a[l]);
		st[id].ans2 = power(m2, a[l]);
		st[id].lazy1 = one;
		//cerr << st[id].lazy1.a << ' ' << st[id].lazy1.b << '\n';
		st[id].lazy2 = one;
		return ;
	}
	int mid = (l+r)>>1;
	build(id*2, l, mid);
	build(id*2+1, mid, r);
	st[id].lazy1 = one; st[id].lazy2 = one;
	combine(id);
}

void push(int id, int l, int r)
{
	//cerr << st[id].lazy1.a << ' ' << st[id].lazy1.b << '\n';
	if(st[id].lazy1.a == 1 && st[id].lazy1.b == 0) return ;
	else
	{
		//cerr << "PUSH " << id << ' ' << l << ' ' << r << '\n';
		st[id].ans1 = mult(st[id].ans1, st[id].lazy1);
		st[id].ans2 = mult(st[id].ans2, st[id].lazy2);
		if(r - l < 2) 
		{
			st[id].lazy1 = st[id].lazy2 = one; return ;
		}
		st[2*id].lazy1 = mult(st[2*id].lazy1, st[id].lazy1);
		st[2*id+1].lazy1 = mult(st[2*id+1].lazy1, st[id].lazy1);
		st[2*id].lazy2 = mult(st[2*id].lazy2, st[id].lazy2);
		st[2*id+1].lazy2 = mult(st[2*id+1].lazy2, st[id].lazy2);
		st[id].lazy1 = st[id].lazy2 = one;
	}
}

void update(int id, int l, int r, int ql, int qr, number v1, number v2)
{
	push(id, l, r);
	//cerr << "UPDATE : " << id << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << st[id].ans << ' ' << st[id].lazy << '\n';
	//cerr << "UPDATE : " << id << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << v << ' ' << st[id].ans1.a << ' ' << st[id].ans1.b << ' ' << st[id].ans2.a << ' ' << st[id].ans2.b << ' ' << st[id].lazy << '\n';
	if(ql >= r || l >= qr) return ;
	if(ql <= l && r <= qr)
	{
		st[id].lazy1 = mult(st[id].lazy1, v1);
		st[id].lazy2 = mult(st[id].lazy2, v2);
		//cerr << "UPDATE : " << id << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << st[id].ans << ' ' << st[id].lazy << '\n';
		push(id, l, r);
		return;
	}
	int mid = (l+r)>>1;
	update(id*2, l, mid, ql, qr, v1, v2);
	update(id*2+1, mid, r, ql, qr, v1, v2);
	combine(id);
}

number query(int id, int l, int r, int ql, int qr)
{
	//cerr << "QUERY : " << id << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << st[id].ans1.a << ' ' << st[id].ans1.b << ' ' << st[id].ans2.a << ' ' << st[id].ans2.b << ' ' << st[id].lazy1.a << ' ' << st[id].lazy1.b << '\n';
	push(id, l, r);
	//cerr << "QUERY : " << id << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << st[id].ans1.a << ' ' << st[id].ans1.b << ' ' << st[id].ans2.a << ' ' << st[id].ans2.b << '\n';
	if(ql >= r || l >= qr) return zero;
	if(ql <= l && r <= qr) return subtract(st[id].ans1, st[id].ans2);
	int mid = (l+r)>>1;
	return add(query(id*2,l,mid,ql,qr),query(id*2+1,mid,r,ql,qr));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	inv2 = inv(2); inv5 = inv(5);
	one.a = 1; one.b = 0;
	zero.a = 0; zero.b = 0;
	m1.a = inv2; m1.b = inv2;
	m2.a = inv2; m2.b = relax(-inv2);
	ll x = 1;
	for(int i = 0; i < 63; i++)
	{
		M1[i] = powercalc(m1, x);
		M2[i] = powercalc(m2, x);
		x<<=1;
	}
	int n, m; cin>>n>>m; //scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		//scanf("%d", a + i);
	}
	build(1, 0, n);
	for(int i = 0; i < m; i++)
	{
		int t; cin>>t;//scanf("%d", &t);
		if(t == 1)
		{
			int l, r; ll v;
			cin>>l>>r>>v;
			//scanf("%d %d %lld", &l, &r, &v);
			l--; r--;
			number v1 = power(m1, v);
			number v2 = power(m2, v);
			update(1, 0, n, l, r + 1, v1, v2);
		}
		else
		{
			int l, r;
			cin>>l>>r;
			//scanf("%d %d", &l, &r);
			l--; r--;
			number ans = query(1, 0, n, l, r + 1);
			ans = invert(ans);
			//cerr << ans.a << ' ' << ans.b << endl;
			//ans.b%=MOD; if(ans.b<0) ans.b+=MOD;
			//assert(ans.b==0);
			ans.a%=MOD;
			if(ans.a<0) ans.a+=MOD;
			cout<<ans.a<<'\n';
			//printf("%lld\n", ans.a);
		}
	}
}