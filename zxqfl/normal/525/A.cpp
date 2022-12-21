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

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int keys[256];
char str[250000];	

int main()
{
	int cnt = 0;
	scanf("%*d");
	scanf("%s", str);
	for (int i = 0; str[i]; i++)
	{
		if (i % 2)
		{
			int v = int(str[i]) - 'A' + 'a';
			if (keys[v])
				keys[v]--;
			else
				cnt++;
		}
		else
			keys[str[i]]++;
	}
	printf("%d\n", cnt);
}