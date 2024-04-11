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
	int n, k, nimber = 0;
	rint(n); rint(k);
	ji(n)
	{
		nrint(x);
		int v;
		if (k % 2 == 0)
		{
			if (x <= 2)
				v = x;
			else
				v = (x+1) % 2;
		}
		else
		{
			if (x < 4)
				v = x % 2;
			else if (x % 2 == 1)
				v = 0;
			else
			{
				jjs(i, 2, 32)
				{
					int c = 1 << i;
					assert(c <= x);
					if (x == c || x == c+c/2)
					{
						v = (i+1) % 2 + 1;
						break;
					}
					else if (x % c == c/2)
					{
						v = i % 2 + 1;
						break;
					}
				}
			}
		}
		nimber ^= v;
	}
	if (nimber == 0)
		printf("Nicky\n");
	else
		printf("Kevin\n");
}