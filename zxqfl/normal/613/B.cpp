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
ll A, cf, cm, mmm;
pair<ll, int> mapi[MX];
int fin[MX];
ll skills[MX];
int n;

void finish(ll v)
{
	printf("%lld\n", v);
	ji(n) fin[mapi[i].second] = skills[i];
	ji(n)
	{
		printf("%d ", fin[i]);
	}
	printf("\n");
	ll a = 0, b = A;
	ji(n) if (fin[i] == A) ++a;
	ji(n) b = min(b, (ll) fin[i]);
	exit(0);
}

int sol(int z = -2)
{
	ll m = mmm;
	// ll totn = 
	// printf("z=%d\n", z);
	int idx = n-1;
	ll used = 0;
	while (idx > 0)
	{
		used += (ll) (n - idx) * (skills[idx-1] - skills[idx]);
		--idx;
	}
	ll best = -1;
	int bestIdx = -2;
	for (int i = -1; i < n; i++)
	{
		if (i >= 0)
			m -= (A - skills[i]);
		if (m < 0)
			break;
		while (used > m || (idx == i && idx != n-1))
		{
			++idx;
			used -= (ll) (n - idx) * (skills[idx-1] - skills[idx]);
		}
		assert(used <= m);
		ll extra = m - used;
		ll cmin = min((ll) A, skills[idx] + extra / (n - idx));
		ll val = cf * (i+1) + cm * cmin;
		if (i == n-1)
			val = cf * n + cm * A;
		if (val > best)
		{
			best = val;
			bestIdx = i;
		}
		if (i == z)
		{
			for (int j = idx; j < n; j++)
				skills[j] = cmin;
			for (int j = 0; j <= i; j++)
				skills[j] = A;
			finish(best);
			return -3;
		}
	}
	return bestIdx;
}

int main()
{
	// while (true)
	// {
	// 	n = rand() % 10 + 1;
	// 	A = rand() % 10 + 1;
	// 	cf = rand() % 10 + 1;
	// 	cm = rand() % 10 + 1;
	// 	mmm = rand() % 100 + 1;
	// 	ji(n) skills[i] = rand() % A + 1;
	// 	ji(n) printf("%d ", skills[i]);
	// 	printf("\n");
	// 	ji(n) mapi[i] = {skills[i], i};
	// 	sort(mapi, mapi + n);
	// 	sort(skills, skills + n);
	// 	reverse(mapi, mapi + n);
	// 	reverse(skills, skills + n);
	// 	sol(sol());
	// }
	rint(n);
	rint(A);
	rint(cf);
	rint(cm);
	rint(mmm);
	ji(n) rint(skills[i]);
	ji(n) mapi[i] = {skills[i], i};
	sort(mapi, mapi + n);
	sort(skills, skills + n);
	reverse(mapi, mapi + n);
	reverse(skills, skills + n);
	sol(sol());
}