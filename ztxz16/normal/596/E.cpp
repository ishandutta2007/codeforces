#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 205;

int n, m, q, deg[N][N], dx[N], dy[N], visit[N][N], hashTag;
int inCircle[N][N], value[N][N], maskNow[1000005];
char str[N][N], ss[1000005];
pair <int, int> go[N][N];

void makeCircle(int x, int y) {
	int mask = 0;
	int tempx = x, tempy = y;
	while (1) {
		mask |= (1 << str[x][y] - '0');
		inCircle[x][y] = 1;
		pair <int, int> gogo = go[x][y];
		x = gogo.first, y = gogo.second;
		if (x == tempx && y == tempy) {
			break;
		}
	}
	
	while (1) {
		value[x][y] = mask;
		pair <int, int> gogo = go[x][y];
		x = gogo.first, y = gogo.second;
		if (x == tempx && y == tempy) {
			break;
		}
	}
}

void work() {
	scanf("%s", ss + 1);
	int len = strlen(ss + 1);
	maskNow[len + 1] = 0;
	for (int i = len; i >= 1; i--) {
		maskNow[i] = maskNow[i + 1];
		maskNow[i] |= (1 << ss[i] - '0');
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!inCircle[i][j] && deg[i][j]) {
				continue;
			}
				
			if (inCircle[i][j]) {
				if ((value[i][j] & maskNow[1]) == maskNow[1]) {
					printf("YES\n");
					return;
				}
			} else {
				int x = i, y = j;
				for (int k = 1; k <= len; k++) {
					while (1) {
						if (ss[k] == str[x][y]) {
							break;
						}
						
						pair <int, int> gogo = go[x][y];
						x = gogo.first, y = gogo.second;
						if (inCircle[x][y]) {
							break;
						}
					}
					
					if (ss[k] == str[x][y]) {
						pair <int, int> gogo = go[x][y];
						x = gogo.first, y = gogo.second;
						if (k == len || (inCircle[x][y] && (value[x][y] & maskNow[k + 1]) == maskNow[k + 1])) {
							printf("YES\n");
							return;
						}
					}
					
					if (inCircle[x][y]) {
						if ((value[x][y] & maskNow[k]) == maskNow[k]) {
							printf("YES\n");
							return;
						} else {
							break;
						}
					}
				}
			}
		}
	}
	
	printf("NO\n");
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str[i] + 1);
	}
	
	for (int i = 0; i < 10; i++) {
		scanf("%d %d", &dx[i], &dy[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j]) {
				continue;
			}
			
			hashTag++;	
			int x = i, y = j;
			while (1) {
				int nx = x, ny = y;
				visit[x][y] = hashTag;
				int d = str[x][y] - '0';
				if (x + dx[d] >= 1 && x + dx[d] <= n && y + dy[d] >= 1 && y + dy[d] <= m) {
					x += dx[d];
					y += dy[d];
				}
				
				go[nx][ny] = make_pair(x, y);
				deg[x][y]++;
				if (visit[x][y] == hashTag) {
					makeCircle(x, y);
					break;
				} else if (visit[x][y]) {
					break;
				}
			}
		}
	}
	
	while (q--) {		
		work();
	}
	
	return 0;
}