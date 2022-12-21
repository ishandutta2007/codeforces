#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
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
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

#define MX 1000009
char s[MX];
int z[MX];
int arr[MX];

void fail()
{
	printf("0\n");
	exit(0);
}

int main()
{
	nrint(N);
	nrint(M);
	scanf("%s", s);
	int seq[M];
	ji(M) rint(seq[i]);
	ji(M) seq[i]--;
	int L = 0, R = 0;
	int n = strlen(s);
	for (int i = 1; i < n; i++) {
	  if (i > R) {
	    L = R = i;
	    while (R < n && s[R-L] == s[R]) R++;
	    z[i] = R-L; R--;
	  } else {
	    int k = i-L;
	    if (z[k] < R-i+1) z[i] = z[k];
	    else {
	      L = i;
	      while (R < n && s[R-L] == s[R]) R++;
	      z[i] = R-L; R--;
	    }
	  }
	}
	ji(M)
	{
		arr[seq[i]]++;
		arr[seq[i]+n]--;
		if (i > 0)
		{
			int a = seq[i-1];
			int b = seq[i];
			if (b - a >= n)
				continue;
			if (z[b-a] < a+n-b)
				fail();
		}
	}
	ll ans = 1;
	int tot = 0;
	ji(N)
	{
		tot += arr[i];
		if (tot == 0)
		{
			ans *= 26;
			ans %= MOD;
		}
	}
	printf("%lld\n", ans);
}