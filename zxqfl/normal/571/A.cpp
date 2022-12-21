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
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

ll f(ll a, ll b, ll k, ll t)
{
	if (a + b > t) return 0;
	ll z = min(k, t - (a + b));
	// 0->1
	// 1->3
	// 2->6
	ll ret = (z + 1) * (z + 2) / 2;
	return ret;
}

int main()
{
	ll a, b, c, l;
	rint(a); rint(b); rint(c); rint(l);
	ll* dp1 = new ll[l+1];
	ll* dp2 = new ll[l+1];
	ji(l+1) dp1[i] = 1;
	jk(3)
	{
		ll tot = 0;
		ji(l+1)
		{
			tot += dp1[i];
			dp2[i] = tot;
		}
		swap(dp1, dp2);
	}
	ll ret = dp1[l];
	ji(l+1)
	{
		ret -= f(b, c, l - i, a + i);
		ret -= f(a, c, l - i, b + i);
		ret -= f(a, b, l - i, c + i);
	}
	printf("%lld\n", ret);
}