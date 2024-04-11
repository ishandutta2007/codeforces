#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 254, N2 = N * N;

int n, R, C;
int a[N][N], b[N][N];
int rm[N], cm[N], rmi[N], cmi[N];
bool isrm[N2], iscm[N2];
int num[N2];
pr pos[N2];

int seq[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int main() {
	int i, j, k = 0, r = 0, c = 0, z = 0, n_num = 0, n_pos = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> R >> C, n = R * C;
/********
	std::iota(seq, seq + n, 1);
	//int seed = time(NULL)+(size_t)new char;
	int seed = 1599695760;
	std::mt19937 gen(seed);
	fprintf(stderr, "seed = %d\n", seed);
	std::shuffle(seq, seq + n, gen);
********/
	memset(rm, 0, sizeof rm), memset(cm, 0, sizeof cm);
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j)
			cin >> a[i][j],
//			a[i][j] = seq[z++],
			up(rm[i], a[i][j]), up(cm[j], a[i][j]);
	for (i = 1; i <= R; ++i) isrm[rm[i]] = true;
	for (j = 1; j <= C; ++j) iscm[cm[j]] = true;
	for (i = n; i; --i) {
		if (isrm[i] && iscm[i]) b[++r][++c] = i;
		else if (isrm[i]) b[++r][c] = i;
		else if (iscm[i]) b[r][++c] = i;
		else num[n_num++] = i;
		if (isrm[i] || iscm[i]) {
			for (j = c; j; --j) if (!b[r][j]) b[r][j] = -1, pos[n_pos++] = pr(r, j);
			for (j = r; j; --j) if (!b[j][c]) b[j][c] = -1, pos[n_pos++] = pr(j, c);
		}
	}
	assert(r == R && c == C && n_num == n_pos);
	for (i = 0; i < n_num; ++i) b[pos[i].first][pos[i].second] = num[i];

	memset(rmi, 0, sizeof rmi), memset(cmi, 0, sizeof cmi);
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j)
			up(rmi[i], b[i][j]), up(cmi[j], b[i][j]);
	std::sort(rm + 1, rm + R + 1), std::sort(rmi + 1, rmi + R + 1);
	bool flag = true;
	for (i = 1; i <= R; ++i) flag = flag && rm[i] == rmi[i];
	std::sort(cm + 1, cm + C + 1), std::sort(cmi + 1, cmi + C + 1);
	for (j = 1; j <= C; ++j) flag = flag && cm[j] == cmi[j];
	if (!flag) return cout << "-1\n", 0;
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j)
			cout << b[i][j] << (j == C ? '\n' : ' ');
	return 0;
}