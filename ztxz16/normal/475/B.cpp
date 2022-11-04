#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_q PQ
#define mp make_pair
#define pb push_back

using namespace std;

const int N = 105;

int n, m, flag, vis[N][N];
char row[N], col[N];
vector <pair <int, int> > q;

int main() {
	scanf("%d %d", &n, &m);
	scanf("%s", row);
	scanf("%s", col);
	flag = 1;
	for (int sx = 0; sx < n; sx++) { 
		for (int sy = 0; sy < m; sy++) {
			memset(vis, 0, sizeof(vis));
			q.clear();
			vis[sx][sy] = 1;
			q.pb(mp(sx, sy));
			for (int h = 0; h < (int)q.size(); h++) {
				pair<int, int> pos = q[h];
				if (col[pos.second] == 'v' && pos.first + 1 < n && vis[pos.first + 1][pos.second] == 0) {
					vis[pos.first + 1][pos.second] = 1;
					q.pb(mp(pos.first + 1, pos.second));
				}
				
				if (col[pos.second] == '^' && pos.first > 0 && vis[pos.first - 1][pos.second] == 0) {
					vis[pos.first - 1][pos.second] = 1;
					q.pb(mp(pos.first - 1, pos.second));
				}
				
				if (row[pos.first] == '>' && pos.second + 1 < m && vis[pos.first][pos.second + 1] == 0) {
					vis[pos.first][pos.second + 1] = 1;
					q.pb(mp(pos.first, pos.second + 1));
				}
				
				if (row[pos.first] == '<' && pos.second > 0 && vis[pos.first][pos.second - 1] == 0) {
					vis[pos.first][pos.second - 1] = 1;
					q.pb(mp(pos.first, pos.second - 1));
				}
			}
			
			if (q.size() != n * m) {
				flag = 0;
			}
		}
	} 
	
	if (flag) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}