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

long long modPow(long long a, long long b, int mod)
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

const int MX = 1.1e6;

char s1[MX], s2[MX];
int n;

char invert(char c)
{
	switch(c)
	{
		case 'N': return 'S';
		case 'S': return 'N';
		case 'W': return 'E';
		case 'E': return 'W';
		default: assert(false);
	}
}

void rev(char* s, bool inv)
{
	assert(strlen(s) == n);
	reverse(s, s + n);
	if (inv)
		ji(n) s[i] = invert(s[i]);
}

int f[MX];

bool check()
{
	// rev(s2, true);

	// h1[0] = h2[0] = {0, 0};
	// ji(n)
	// {
	// 	h1[i+1] = h1[i] * knst + Hash{s1[i], s1[i]};
	// 	h2[i+1] = h2[i] * knst + Hash{s2[i], s2[i]};
	// }

	// jjs(len, 1, n+1)
	// {
	// 	if (h2[n] - h2[n - len] == h1[len].adv(knst, n - len))
	// 		return false;
	// }

	// rev(s2, true);

	// return true;

	f[0] = f[1] = 0;
	jjs(i, 2, n+1)
	{
		f[i] = f[i-1];
		while (true)
		{
			if (s1[f[i]] == s1[i-1])
			{
				++f[i];
				break;
			}
			if (f[i] == 0)
				break;
			f[i] = f[f[i]];
		}
	}

	ji(n) s2[i] = invert(s2[i]);
	reverse(s2, s2 + n);

	int i = 0;
	int j = 0;
	while (true)
	{
		if (j == n)
			return i == 0;
		if (s2[j] == s1[i])
			i++, j++;
		else if (i > 0)
			i = f[i];
		else
			j++;
	}
}

bool solve()
{
	rint(n);
	--n;
	scanf("%s%s", s1, s2);
	rev(s1, false);
	rev(s2, false);
	return check();
}

int main()
{
	printf("%s\n", solve() ? "YES" : "NO");
}