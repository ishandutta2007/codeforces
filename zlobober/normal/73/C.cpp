#include <iostream>
#include <memory.h>
#include <string>
#include <cstdio>
using namespace std;

//#define TASK ""



int B[256][256];

const int N = 105;
const int E = 26;

int D[105][105][26];

const int INF = 1e5;

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int k;
	string s;
	cin >> s >> k;
	int n;
	cin >> n;
	char a, b;
	int v;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> v;
		B[a - 'a'][b - 'a'] = v;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int e = 0; e < E; e++)
				D[i][j][e] = -INF;
	D[0][0][s[0] - 'a'] = 0;
	memset(D[0][1], 0, sizeof(D[0][1]));
	D[0][1][s[0] - 'a'] = -INF;
	
	int pp;
	n = s.size();
	for (int q = 1; q < n; q++)
	{
		for (int p = 0; p <= k; p++)
		{
			for (int l = 0; l < E; l++)
			{
				pp = p;
				if (l != s[q] - 'a')
					pp--;
				if (pp < 0)
					continue;
				for (int e = 0; e < E; e++)
					D[q][p][l] = max(D[q][p][l], D[q - 1][pp][e] + B[e][l]);
			}
		}
	}
	int ans = -1e9;
	for (int i = 0; i <= k; i++)
		for (int e = 0; e < 26; e++)
			ans = max(ans, D[n - 1][i][e]);
	cout << ans;
	return 0;
}