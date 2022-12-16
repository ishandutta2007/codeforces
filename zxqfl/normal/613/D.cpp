#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rint(x);
#define rfloat(x) scanf("%lf", &(x))

#define rint readInteger
template<typename T>
bool readInteger(T& x)
{
	char c,r=0,n=0;
	x=0;
	for (ever)
	{
		c=getchar();
		if ((c<0) && (!r))
			return(0);
		else if ((c=='-') && (!r))
			n=1;
		else if ((c>='0') && (c<='9'))
			x=x*10+c-'0',r=1;
		else if (r)
			break;
	}
	if (n)
		x=-x;
	return(1);
}

const int MOD = 1000000007;

long long modPow(long long a, long long b, int mod = MOD)
{
	assert(b >= 0);
	long long ret = 1 % mod;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

const int MX = 1.1e5;
int n;
VI E[MX];
int par[MX];
int dep[MX];
int order[MX];
int end_order[MX];
bool important[MX];
bool pillaged[MX];
VI stree;
VI nodes;

int qmin(int a, int b)
{
	if (a < 0) return b;
	if (b < 0) return a;
	return dep[a] < dep[b] ? a : b;
}

void ini_stree(int idx, int l, int r)
{
	if (idx >= stree.size())
		stree.resize(idx+1);
	if (l == r)
		stree[idx] = nodes[l];
	else
	{
		int L = idx * 2 + 1;
		int R = idx * 2 + 2;
		int mid = (l + r) / 2;
		ini_stree(R, mid+1, r);
		ini_stree(L, l, mid);
		stree[idx] = qmin(stree[L], stree[R]);
	}
}

int q_stree(int idx, int l, int r, int a, int b)
{
	if (a > b) swap(a, b);
	if (a <= l && b >= r)
		return stree[idx];
	if (a > r || b < l)
		return -1;
	int L = idx * 2 + 1;
	int R = idx * 2 + 2;
	int mid = (l + r) / 2;
	return qmin(q_stree(L, l, mid, a, b), q_stree(R, mid+1, r, a, b));
}

int LCA(int a, int b)
{
	return q_stree(0, 0, nodes.size()-1, order[a], order[b]);
}

void init(int x, int p)
{
	par[x] = p;
	if (par[x] < 0)
		dep[x] = 0;
	else
		dep[x] = 1 + dep[par[x]];
	order[x] = nodes.size();
	nodes.push_back(x);
	for (int e : E[x]) if (e != p)
	{
		init(e, x);
		nodes.push_back(x);
	}
	end_order[x] = nodes.size();
}

int main()
{
	rint(n);
	jk(n-1)
	{
		int a, b;
		rint(a); rint(b);
		--a; --b;
		E[a].pb(b);
		E[b].pb(a);
	}
	init(0, -1);
	ini_stree(0, 0, nodes.size()-1);
	int q;
	rint(q);
	jjl(ALSFKAMSMSA, q)
	{
		int k;
		rint(k);
		VI v(k);
		ji(k) rint(v[i]);
		ji(k) --v[i];
		for (int x : v)
			important[x] = true;
		int ans = 0;
		for (int x : v)
		{
			if (par[x] != -1 && important[par[x]])
				ans = -1;
		}
		if (ans != -1)
		{
			VPI vp(k);
			ji(k) vp[i] = {order[v[i]], v[i]};
			sort(vp.begin(), vp.end());
			priority_queue<tuple<int, int, int>> Q;
			set<int> s;
			set<pi> pos;
			ji(k) s.insert(i);
			ji(k) pos.insert({vp[i].first, i});
			ji(k-1)
				Q.push(make_tuple(dep[LCA(vp[i].second, vp[i+1].second)], i, i+1));
			vector<char> hit(k);
			while (!Q.empty())
			{
				auto t = Q.top();
				Q.pop();
				int a = get<1>(t);
				int b = get<2>(t);
				if (hit[a] && hit[b])
					;
				else if (hit[a])
				{
					auto it = s.find(b);
					if (it != s.begin())
					{
						--it;
						int z = *it;
						Q.push(make_tuple(dep[LCA(vp[z].second, vp[b].second)], z, b));
					}
				}
				else if (hit[b])
				{
					auto it = s.find(a);
					++it;
					if (it != s.end())
					{
						int z = *it;
						Q.push(make_tuple(dep[LCA(vp[a].second, vp[z].second)], a, z));
					}
				}
				else
				{
					set<pi>::iterator it;
					++ans;
					int z = LCA(vp[a].second, vp[b].second);
					if (z == vp[a].second)
						z = vp[b].second;
					else if (z == vp[b].second)
						z = vp[a].second;
					else if (important[z])
					{
						++ans;
						hit[a] = hit[b] = true;
						s.erase(a);
						s.erase(b);
						pos.erase({order[a], a});
						pos.erase({order[b], b});
						goto fi;
					}
					it = pos.lower_bound({order[z], -1});
					while (it != pos.end() && it->first < end_order[z])
					{
						hit[it->second] = true;
						s.erase(it->second);
						it = pos.erase(it);
					}
					fi:;
				}
			}
		}
		for (int x : v)
			important[x] = false;
		printf("%d\n", ans);
	}
}