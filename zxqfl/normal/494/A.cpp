#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define INF ((int) 1e9+10)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

char s[100001];
int L;

int main()
{
	scanf("%s", s);
	L = strlen(s);

	int tcount = 0;
	int crnt = 0;
	int idx = -1;
	ji(L)
	{
		if (s[i] == '#')
		{
			idx = i;
			tcount++;
			crnt--;
		}
		else if (s[i] == '(')
			crnt++;
		else
			crnt--;
		if (crnt < 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	int nex = crnt;
	crnt = 0;
	tcount = 0;
	ji(L)
	{
		if (s[i] == '#')
		{
			tcount++;
			crnt--;
			if (idx == i)
				crnt -= nex;
		}
		else if (s[i] == '(')
			crnt++;
		else
			crnt--;
		if (crnt < 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	ji(tcount-1)
		printf("1\n");
	printf("%d\n", nex+1);
}