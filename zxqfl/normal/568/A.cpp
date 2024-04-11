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

const int LIM = 5e7;
bool composite[LIM];
int ans;

bool palin(int x)
{
	static char arr[20];
	int z = 0;
	while (x)
	{
		arr[z++] = x % 10;
		x /= 10;
	}
	ji(z) if (arr[i] != arr[z-i-1])
		return false;
	return true;
}

int main()
{
	ll p, q;
	rint(p); rint(q);
	composite[1] = true;
	int primeCount = 0;
	int palinCount = 0;
	for (int i = 1; i < LIM; i++)
	{
		if (!composite[i])
		{
			primeCount++;
			for (int j = i*2; j < LIM; j += i)
				composite[j] = true;
		}
		if (palin(i))
			++palinCount;
		if (q * primeCount <= p * palinCount)
			ans = i;
	}
	printf("%d\n", ans);
}