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

typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;

const DOUBLE EPS = 1e-9;

struct LPSolver {
  int m, n;
  VI B, N;
  VVD D;

  LPSolver(const VVD &A, const VD &b, const VD &c) :
    m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, VD(n + 2)) {
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = A[i][j];
    for (int i = 0; i < m; i++) { B[i] = n + i; D[i][n] = -1; D[i][n + 1] = b[i]; }
    for (int j = 0; j < n; j++) { N[j] = j; D[m][j] = -c[j]; }
    N[n] = -1; D[m + 1][n] = 1;
  }

  void Pivot(int r, int s) {
    for (int i = 0; i < m + 2; i++) if (i != r)
      for (int j = 0; j < n + 2; j++) if (j != s)
        D[i][j] -= D[r][j] * D[i][s] / D[r][s];
    for (int j = 0; j < n + 2; j++) if (j != s) D[r][j] /= D[r][s];
    for (int i = 0; i < m + 2; i++) if (i != r) D[i][s] /= -D[r][s];
    D[r][s] = 1.0 / D[r][s];
    swap(B[r], N[s]);
  }

  bool Simplex(int phase) {
    int x = phase == 1 ? m + 1 : m;
    while (true) {
      int s = -1;
      for (int j = 0; j <= n; j++) {
        if (phase == 2 && N[j] == -1) continue;
        if (s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s]) s = j;
      }
      if (D[x][s] > -EPS) return true;
      int r = -1;
      for (int i = 0; i < m; i++) {
        if (D[i][s] < EPS) continue;
        if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||
          (D[i][n + 1] / D[i][s]) == (D[r][n + 1] / D[r][s]) && B[i] < B[r]) r = i;
      }
      if (r == -1) return false;
      Pivot(r, s);
    }
  }

  DOUBLE Solve(VD &x) {
    int r = 0;
    for (int i = 1; i < m; i++) if (D[i][n + 1] < D[r][n + 1]) r = i;
    if (D[r][n + 1] < -EPS) {
      Pivot(r, n);
      if (!Simplex(1) || D[m + 1][n + 1] < -EPS) return -numeric_limits<DOUBLE>::infinity();
      for (int i = 0; i < m; i++) if (B[i] == -1) {
        int s = -1;
        for (int j = 0; j <= n; j++)
          if (s == -1 || D[i][j] < D[i][s] || D[i][j] == D[i][s] && N[j] < N[s]) s = j;
        Pivot(i, s);
      }
    }
    if (!Simplex(2)) return numeric_limits<DOUBLE>::infinity();
    x = VD(n);
    for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n + 1];
    return D[m][n + 1];
  }
};

int best;
bool DBG = false;

void SolveInteger(const VVD& A, const VD& B, const VD& C)
{
	LPSolver ALGO(A, B, C);
	VD x;
	DOUBLE v = ALGO.Solve(x);
	if ((int) ceil(-v) >= best)
		return;
	if (DBG) {
		ji(C.size()) printf("%.2f ", (double) A.back()[i]);
		printf(" <= %.2f ", (double) B.back());
		printf(" -> ");
		ji(C.size()) printf("%.2f ", (double) (x[i]));
		printf("\n");
	}
	ji(x.size())
	{
		DOUBLE a = floor(x[i]);
		DOUBLE b = ceil(x[i]);
		if (min(x[i] - a, b - x[i]) >= EPS)
		{
			VVD NA;
			VD NB;
			NA = A;
			NB = B;
			int vars = C.size();
			VD nv(vars);
			nv[i] = -1;
			NA.pb(nv);
			NB.pb(-b);
			SolveInteger(NA, NB, C);

			NA.pop_back();
			NB.pop_back();

			nv[i] = 1;
			NA.pb(nv);
			NB.pb(a);
			SolveInteger(NA, NB, C);
			return;
		}
	}
	best = min(best, (int) round(-v));
}

int main()
{
	int n, a, b, c;
	rint(n); rint(a); rint(b); rint(c);
	best = n;
	VI x;
	ji(n)
	{
		int s;
		rint(s);
		if (s > a + b + c)
		{
			printf("-1\n");
			return 0;
		}
		else
			x.pb(s);
	}
	VPI opt {
		{a, 0},
		{b, 1},
		{c, 2},
		{a + b, 3},
		{a + c, 4},
		{b + c, 5},
		{a + b + c, 6}
	};
	sort(opt.begin(), opt.end());
	int need[7];
	ji(7) need[i] = 0;
	foreach(z, x)
	{
		ji(7)
		{
			if (opt[i].first >= z)
			{
				++need[i];
				break;
			}
		}
	}
	VVD A;
	VD B;
	VD C {0, 0, 0, 0, 0, 0, 0, -1};
	VD sol;
	A.pb({1, 0, 0, 1, 1, 0, 1, -1}); B.pb(0);
	A.pb({0, 1, 0, 1, 0, 1, 1, -1}); B.pb(0);
	A.pb({0, 0, 1, 0, 1, 1, 1, -1}); B.pb(0);
	A.pb({0, 0, 0, 1, 1, 1, 1, -1}); B.pb(0);
	ji(7)
	{
		VD nc {0, 0, 0, 0, 0, 0, 0, 0};
		double ncb = 0;
		jjs(j, i, 7)
			ncb -= need[j];
		jjs(j, i, 7)
			nc[opt[j].second] -= 1;
		A.pb(nc);
		B.pb(ncb);
	}
	ji(8)
	{

		VD nc {0, 0, 0, 0, 0, 0, 0, 0};
		double ncb = 0;
		nc[i] -= 1;
		A.pb(nc);
		B.pb(ncb);
	}
	SolveInteger(A, B, C);
	printf("%d\n", best);
}