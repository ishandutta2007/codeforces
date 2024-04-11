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

typedef VVI mat;
int MSIZ;

mat emptyMatrix()
{
	return mat(MSIZ, VI(MSIZ, 0));
}
mat identity()
{
	auto ret = emptyMatrix();
	return ret;
}
void multiply(const mat& a, const mat& b, mat& c)
{
	jij(MSIZ, MSIZ)
		c[i][j] = 0;
	ji(MSIZ) jjs(k, i, MSIZ) {
		jjs(j, k, MSIZ)
		{
			c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
		}
	}
}
void MultiplyInPlace(mat& a, const mat& b)
{
	mat cp = a;
	multiply(cp, b, a);
}
mat cmultiply(mat a, mat b)
{
	mat ans = identity();
	multiply(a, b, ans);
	return ans;
}

mat mpow(mat a, int v)
{
	if (v == 0) return identity();
	if (v == 1) return a;
	if (v % 2 == 1) return cmultiply(mpow(a, v-1), a);
	mat x = mpow(a, v/2);
	return cmultiply(x, x);
}

mat makeMatrix(int x)
{
	mat ret = identity();
	ji(MSIZ) if (i <= x)
		ret[i][x] = 1;
	return ret;
}

int main()
{
	MSIZ = 101;
	int N, T;
	rint(N); rint(T);
	int A[N];
	ji(N) rint(A[i]);
	set<int> S;
	ji(N) S.insert(A[i]);
	map<int, int> M;
	int nxt = 0;
	foreach(z, S) M[z] = nxt++;
	ji(N) A[i] = M[A[i]];
	mat ans = identity();
	ji(N)
	{
		MultiplyInPlace(ans, makeMatrix(A[i]));
	}
	ans = mpow(ans, T);
	int ret = 0;
	jij(MSIZ, MSIZ) if (j >= i)
	{
		ret = max(ret, ans[i][j]);
	}
	printf("%d\n", ret);
}