#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN=100+10;
bool map[MAXN][MAXN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	memset(map, 0, sizeof(map));
	for (int a, b, i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		map[a][b]=map[b][a]=1;
	}
	int ret=0;
	vector<pair<int, int> > G;
	do {
		G.clear();
		for (int i=1; i<=n; i++) {
			int cnt=0;
			for (int j=1; j<=n; j++)
				if (map[i][j]) cnt++;
			if (cnt==1) {
				for (int j=1; j<=n; j++)
					if (map[i][j]) G.push_back(make_pair(i, j));
			}
		}
		if (G.size()>0) {
			ret++;
			for (int i=0; i<(int)G.size(); i++)
				map[G[i].first][G[i].second]=map[G[i].second][G[i].first]=0;
		}
	}while (G.size());
	printf("%d\n", ret);
	return 0;
}