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

const int MX = 510;

int h, w;

struct a2
{
	int vals[MX][MX];

	void prefix()
	{
		jij(MX, MX)
		{
			if (i) vals[i][j] += vals[i-1][j];
			if (j) vals[i][j] += vals[i][j-1];
			if (i && j) vals[i][j] -= vals[i-1][j-1];
		}
	}

	int r(int x1, int y1, int x2, int y2)
	{
		return
			vals[x2][y2] - vals[x1-1][y2] - vals[x2][y1-1] + vals[x1-1][y1-1];
	}

	void print()
	{
		jjs(i, 1, h+1) { jjs(j, 1, w+1)
		{
			printf("%d ", vals[i][j]);
		} printf("\n"); }
		printf("\n");
	}
};

#define right RRRR

a2 right, down;
char field[MX][MX];

int main()
{
	rint(h); rint(w);
	ji(h)
	{
		char buf[MX];
		scanf("%s", buf);
		field[i+1][0] = '#';
		jj(w) field[i+1][j+1] = buf[j];
	}
	jjs(i, 1, h+1) jjs(j, 1, w+1)
	{
		if (field[i][j] == '.' && field[i][j+1] == '.')
			++right.vals[i][j];
		if (field[i][j] == '.' && field[i+1][j] == '.')
			++down.vals[i][j];
	}
	right.prefix();
	down.prefix();
	int q;
	rint(q);
	jk(q)
	{
		int r1, c1, r2, c2;
		rint(r1); rint(c1); rint(r2); rint(c2);
		printf("%d\n",
			right.r(r1, c1, r2, c2 - 1) +
			 down.r(r1, c1, r2 - 1, c2));
	}
}