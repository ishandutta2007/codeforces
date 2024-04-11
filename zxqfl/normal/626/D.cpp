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

int main()
{
	int n;
	rint(n);
	VI v(n);
	ji(n) rint(v[i]);
	VLL v1(5010), v2(5010), v3(5010);
	jij(n, n) if (i != j)
	{
		int andrew = v[i];
		int jerry = v[j];
		if (andrew > jerry)
		{
			++v1[andrew - jerry];
			++v2[andrew - jerry];
		}
		else
			++v3[jerry - andrew];
	}
	for (int i = v3.size() - 2; i >= 0; i--)
		v3[i] += v3[i+1];
	long double ret = 0;
	jij(v1.size(), v2.size())
	{
		int q = i + j;
		if (q+1 < v3.size())
			ret += (long double) v1[i] * v2[j] * v3[q+1];
	}
	ret /= accumulate(v1.begin(), v1.end(), 0LL);
	ret /= accumulate(v2.begin(), v2.end(), 0LL);
	ret /= accumulate(v2.begin(), v2.end(), 0LL);
	printf("%.15f\n", (double) ret);
}