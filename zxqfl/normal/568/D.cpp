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

const int MX = 1.1e5;
const int MXMV = 6;
int N, K;
ll A[MX];
ll B[MX];
ll C[MX];
int u[MXMV], v[MXMV];
ll interX;
ll interY;
ll denom;

default_random_engine gen;

int randint(int x)
{
	return uniform_int_distribution<int>(0, x-1)(gen);
}

bool intersect(int p, int q)
{
	ll det = B[p] * A[q] - A[p] * B[q];
	if (det == 0)
		return false;
	denom = det;
	interX = C[p] * B[q] - B[p] * C[q];
	interY = A[p] * C[q] - C[p] * A[q];
	return true;
}

bool liesOn(int p)
{
	ll x1 = A[p] * interX;
	ll y1 = B[p] * interY;
	return x1 + y1 == -C[p] * denom;
}

void put(int used)
{
	printf("YES\n%d\n", used);
	ji(used)
	{
		printf("%d %d\n", u[i] + 1, v[i] + 1);
	}
	exit(0);
}

void solve(const VI& lines, int used)
{
	int rem = K - used;
	if (lines.size() <= rem)
	{
		ji(lines.size())
		{
			u[used+i] = lines[i];
			v[used+i] = -2;
		}
		put(used + lines.size());
	}
	int tries = 10;
	int sz = lines.size();
	while (tries > 1 && sz)
		++tries, sz >>= 1;
	jk(tries)
	{
		int a = randint(lines.size());
		int b = randint(lines.size());
		u[used] = a;
		v[used] = b;
		if (a == b || !intersect(a, b))
			continue;
		else
		{
			static bool lay[MX];
			int cnt = 0;
			ji(lines.size())
			{
				lay[i] = liesOn(lines[i]);
				cnt += lay[i];
			}
			if (cnt * rem < lines.size())
				continue;
			VI nv;
			ji(lines.size()) if (!lay[i])
				nv.pb(lines[i]);
			solve(nv, used + 1);
		}
	}
}

int main()
{
	gen.seed(time(NULL));
	rint(N); rint(K);
	ji(N)
	{
		rint(A[i]);
		rint(B[i]);
		rint(C[i]);
	}
	VI z(N);
	ji(N) z[i] = i;
	auto t1 = clock();
	while ((double) (clock() - t1) / CLOCKS_PER_SEC < 1.6)
		solve(z, 0);
	printf("NO\n");
}