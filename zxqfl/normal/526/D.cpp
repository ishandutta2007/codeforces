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

int z[1000010];
char s[1000010];
int arr[1000010];

int main()
{
	nrint(n); nrint(k);
	scanf("%s", s);
	int L = 0, R = 0;
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
	for (int len = 1; len <= n; len++)
	{
		bool ok = true;
		for (int i = 1; i < k; i++)
		{
			int p = len * i;
			if (p >= n || z[p] < len)
			{
				ok = false;
				break;
			}
		}
		if (!ok) continue;
		int fp = len * k;
		int tar = min(min(1000009, len * (k+1) + 1), fp + z[fp] + 1);
		// printf("%d %d %d\n", len, fp, tar);
		arr[fp]++;
		arr[tar]--;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[i] += arr[i-1];
		if (arr[i])
			putchar('1');
		else
			putchar('0');
	}
}