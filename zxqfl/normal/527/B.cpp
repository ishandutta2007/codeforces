#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define rint(x) scanf("%d", &(x))
#define nrint(x) int x; rint(x);
#define pp make_pair

typedef long long ll;
typedef pair<int, int> pi;

const int MX = 200010;
char S[MX];
char T[MX];
int N;
int p[26][26];

int ham()
{
	int x = 0;
	ji(N) x += S[i] != T[i];
	return x;
}

int main()
{
	while (true)
	{
		N = -1;
		rint(N);
		if (N < 0) break;
		scanf("%s%s", S, T);
		memset(p, -1, sizeof p);
		ji(N) p[S[i]-'a'][T[i]-'a'] = i;
		int best = 0;
		pi bestAns = pp(0, 0);
		jij(26, 26) jjl(a, 26) jjl(b, 26)
		{
			if (p[i][j] < 0 || p[a][b] < 0) continue;
			{
				int v1 = (i == j) + (a == b);
				int v2 = (i == b) + (j == a);
				int gain = v2 - v1;
				if (gain > best)
				{
					best = gain;
					bestAns = pp(p[i][j], p[a][b]);
				}
			}
		}
		swap(S[bestAns.first], S[bestAns.second]);
		printf("%d\n", ham());
		if (bestAns.first == bestAns.second)
			printf("-1 -1\n");
		else
			printf("%d %d\n", bestAns.first + 1, bestAns.second + 1);
	}
}