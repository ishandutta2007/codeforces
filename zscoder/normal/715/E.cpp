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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int N = 251;
const int MOD = 998244353;
ll inv2;
ll prt;
ll iprt;

ll dpncr[N][N];
ll fact[N];
ll inverse[N];
ll g[N][N];
ll sumg[N][N][N];

vector<ii> perm;
int A, B, C, D;

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

ll choose(int n, int m)
{
	if(m < 0) return 0;
	if(n < m) return 0;
	if(m == 0) return 1;
	if(n == m) return 1;
	if(dpncr[n][m] != -1) return dpncr[n][m];
	dpncr[n][m] = choose(n - 1, m - 1) + choose(n - 1, m);
	dpncr[n][m] += MOD; dpncr[n][m] %= MOD;
	return dpncr[n][m];
}

void computefact()
{
	fact[0] = 1;
	for(ll i = 1; i < N; i++)
	{
		fact[i] = (fact[i - 1]*i)%MOD;
	}
	for(ll i = 1; i < N; i++)
	{
		inverse[i] = modpow(i, MOD - 2);
	}
}

void print(vector<ii>& vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].fi << ' ' << vec[i].se << endl;
	}
	cout << "------------------------------------------------" << endl;
}

void printans(vector<ll>& vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;
}

void printansi(vector<int>& vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;
}

void calcpos(vector<ii>& pos)
{
	pos.resize(perm.size());
	for(int i = 0; i < perm.size(); i++)
	{
		pos[i] = ii(-1, -1);
	}
	for(int i = 1; i < perm.size(); i++)
	{
		if(perm[i].fi > 0)
		{
			pos[perm[i].fi].fi = i;
		}
		if(perm[i].se > 0)
		{
			pos[perm[i].se].se = i;
		}
	}
}

int reduce()
{
	int n = perm.size() - 1;
	vector<ii> pos;
	int cnt = 0;
	for(int i = 1; i <= n; i++) //Do a reduction
	{
		calcpos(pos);
		//print(pos);
		if(pos[i].fi > 0 && pos[i].se > 0)
		{
			if(pos[i].fi == pos[i].se) 
			{
				cnt++;
				ii tmp1 = perm[pos[i].fi];
				for(vector<ii>::iterator it = perm.begin(); it != perm.end(); it++)
				{
					if((*it) == tmp1)
					{
						perm.erase(it); break;
					}
				}
				continue;
			}
			int p1 = pos[i].se; int l = perm[p1].fi; ii tmp1 = perm[p1];
			int p2 = pos[i].fi; int r = perm[p2].se; ii tmp2 = perm[p2];
			for(vector<ii>::iterator it = perm.begin(); it != perm.end(); it++)
			{
				if((*it) == tmp1)
				{
					perm.erase(it); break;
				}
			}
			for(vector<ii>::iterator it = perm.begin(); it != perm.end(); it++)
			{
				if((*it) == tmp2)
				{
					perm.erase(it); break;
				}
			}
			perm.pb(ii(l, r));
		}
	}
	//count A, B, C, D
	for(int i = 1; i < perm.size(); i++)
	{
		if(perm[i].fi > 0 && perm[i].se > 0)
		{
			assert(perm[i].fi != perm[i].se);
			C++;
		}
		else if(perm[i].fi > 0)
		{
			A++;
		}
		else if(perm[i].se > 0)
		{
			B++;
		}
		else
		{
			D++;
		}
	}
	return cnt;
}

ll mult(ll a, ll b)
{
	ll r = (a*b)%MOD;
	r = (r+MOD)%MOD;
	return r;
}

ll add(ll a, ll b)
{
	ll r = ((a+b)%MOD+MOD)%MOD;
	return r;
}

ll F(ll a, ll b, ll c, ll d)
{
	ll ans = 1;
	if(d == 0)
	{
		if(a == 0 && b == 0 && c == 0) return 1;
		else return 0;
	}
	ans = mult(ans, fact[a]);
	ans = mult(ans, fact[b]);
	ans = mult(ans, fact[c]);
	ans = mult(ans, choose(a+d-1, d-1));
	ans = mult(ans, choose(b+d-1, d-1));
	ans = mult(ans, choose(d, C));
	return ans;
}

const int LG = 9;
const int root_pw = (1<<LG);
void fft (vector<int> & a, bool invert) 
{
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? iprt : prt;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int((wlen*1LL*wlen)%MOD);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j]; int v = int((a[i+j+len/2]*1LL*w)%MOD);
				a[i+j] = u+v < MOD ? u+v : u+v-MOD;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+MOD;
				w = int (w * 1LL * wlen % MOD);
			}
		}
	}
	if (invert) {
		ll nrev = inv(n);
		for (int i=0; i<n; ++i)
			a[i] = int((a[i]*1LL*nrev)%MOD);
	}
}

void multiply(vector<int>& a, vector<int>& b, vector<int>& res)
{
	vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while(n < max(a.size(), b.size())) n <<= 1;
	fa.resize(n); fb.resize(n);
	//cerr << "A : "; printansi(fa); cerr << "B : "; printansi(fb);
	fft(fa, 0); fft(fb, 0);
	//cerr << "INVERT ONCE : ";
	//printans(fa); printans(fb);
	//fft(fa, 1); fft(fb, 1); cerr << "INVERT BACK A: "; printans(fa); cerr << "INVERT BACK B: "; printans(fb);
	res.resize(n);
	for(int i = 0; i < n; i++) res[i] = int((fa[i]*1LL*fb[i])%MOD);
	//printans(fa);
	fft(res, 1);
	//cerr << "CONVOLUTION : "; printansi(res);
	
}

void computeg(int n)
{
	g[0][0] = 1;
	g[1][1] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			for(int k = 1; k <= i; k++)
			{
				g[i][j] = add(g[i][j], mult(g[i-k][j-1], mult(choose(i, k), fact[k-1])));
			}
			//cerr << g[i][j] << '\n';
			g[i][j] = mult(g[i][j], inverse[j]);
			//cerr << "G : " << i << ' ' << j << ' ' << g[i][j] << '\n';
		}
	}
	for(int i = 0; i <= A; i++)
	{
		for(int j = 0; j <= B; j++)
		{
			vector<int> gi; vector<int> gj;
			gi.resize(n+1); gj.resize(n+1);
			for(int k = 0; k <= n; k++)
			{
				gi[k] = int(g[i][k]);
				gj[k] = int(g[j][k]);
				//cerr << gi[k] << ' ' << gj[k] << '\n';
			}
			vector<int> res;
			multiply(gi, gj, res);
			for(int k = 0; k <= n; k++)
			{
				sumg[i][j][k] = res[k];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; perm.resize(n+1);
	for(int i = 1; i <= n; i++)
	{
		cin >> perm[i].fi;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> perm[i].se;
	}
	ll tmpmult = 7*17;
	tmpmult = mult(tmpmult, modpow(2, 23 - LG)); 
	prt = modpow(3, tmpmult);
	inv2 = inv(2);
	iprt = inv(prt);
	A = 0; B = 0; C = 0; D = 0;
	memset(dpncr, -1, sizeof(dpncr));
	memset(sumg, 0, sizeof(sumg));
	memset(g, 0, sizeof(g));
	memset(fact, 0, sizeof(fact));
	memset(inverse, 0, sizeof(inverse));
	int cycles = reduce();
	computefact(); 
	computeg(n);
	//cerr << h(1, 0, 0) << endl;
	
	vector<ll> ans; ans.assign(n+1, 0);
	
	if(D - C < 0)
	{
		for(int i = 0; i < n; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << endl;
		return 0;
	}

	for(int i = 0; i <= A; i++)
	{
		for(int j = 0; j <= B; j++)
		{
			ll coef = 1;
			coef = mult(coef, F(A-i,B-j,C,D));
			if(A > 0) coef = mult(coef, choose(A, i));
			if(B > 0) coef = mult(coef, choose(B, j));
			vector<int> gi; vector<int> gj;
			gi.resize(n+1); gj.resize(n+1);
			for(int k = 0; k <= n - cycles; k++)
			{
				gi[k] = int(g[D][k]);
				gj[k] = int(sumg[i][j][k]);
			}
			vector<int> res;
			multiply(gi, gj, res);
			//cout << gi.size() << ' ' << gj.size() << ' ' << res.size() << ' ' << ans.size() << ' ' << n << ' ' << cycles << '\n';
			for(int k = 0; k <= n - cycles; k++)
			{
				int moves = n - (k + cycles);
				ans[moves] = add(ans[moves], mult(res[k], coef));
			}
		}
	}
	
	for(int i = 0; i < ans.size(); i++)
	{
		ans[i] = mult(ans[i], fact[D-C]);
	}
	
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
	
	return 0;
}