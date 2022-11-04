#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 105;

int next[N];
char s1[N], s2[N], s3[N];
int n, m, l;
int f[N][N][N];
pair<int, pair<int, int> > path[N][N][N];

void output(int i, int j, int k) {
	if (i == 0 && j == 0 && k == 0)
		return;
	int a = path[i][j][k].first;
	int b = path[i][j][k].second.first;
	int c = path[i][j][k].second.second; 
	output(a, b, c);
	if (a < i && b < j)
		printf("%c", s1[i]);
}

int main() {
	scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
	n = strlen(s1 + 1);
	m = strlen(s2 + 1);
	l = strlen(s3 + 1);
	next[1] = 0;
	for(int i = 2, j = 0; i <= l; i++) {
		while(j && s3[j + 1] != s3[i])
			j = next[j];
		if (s3[j + 1] == s3[i])
			j++;
		next[i] = j;	
	}
	memset(f, -1, sizeof(f));
	f[0][0][0] = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k < l; k++) {
				if (f[i][j][k] == -1)
					continue;
				if (i < n && f[i][j][k] > f[i + 1][j][k]) {
					f[i + 1][j][k] = f[i][j][k];
					path[i + 1][j][k] = make_pair(i, make_pair(j, k));
				}
				if (j < m && f[i][j][k] > f[i][j + 1][k]) {
					f[i][j + 1][k] = f[i][j][k];
					path[i][j + 1][k] = make_pair(i, make_pair(j, k));
				}
				if (i < n && j < m && s1[i + 1] == s2[j + 1]) {
					char ch = s1[i + 1];
					int nxtk = k;
					while(nxtk && s3[nxtk + 1] != ch)
						nxtk = next[nxtk];
					if (s3[nxtk + 1] == ch)
						nxtk++;
					if (nxtk == l)
						continue;
					if (f[i][j][k] + 1 > f[i + 1][j + 1][nxtk]) {
						f[i + 1][j + 1][nxtk] = f[i][j][k] + 1;
						path[i + 1][j + 1][nxtk] = make_pair(i, make_pair(j, k));
					}
				}
			}
	int maxVal = 0, ansi, ansj, ansk;
	for(int i = 0; i < l; i++) {
		if (f[n][m][i] > maxVal)
			maxVal = f[n][m][i], ansi = n, ansj = m, ansk = i;
	}
	//printf("%d\n", maxVal);
	if (maxVal == 0) {
		printf("0\n");
	} else 
		output(ansi, ansj, ansk);
	return 0;
}