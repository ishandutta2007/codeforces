#include <cstdio>
#include <cstring>

bool map[10][10];

int main() {
	int m;
	scanf("%d", &m);
	memset(map, 0, sizeof(map));
	while (m--) {
		int a, b; scanf("%d%d", &a, &b);
		map[a][b]=map[b][a]=true;
	}
	bool flag=false;
	for (int i=1; i<=5; i++)
		for (int j=i+1; j<=5; j++)
			for (int k=j+1; k<=5; k++)
				if ((map[i][j] && map[i][k] && map[k][j]) || (!map[i][j] && !map[i][k] && !map[k][j])) {
					flag=true;
				}
	if (flag) puts("WIN");
	else puts("FAIL");
	return 0;
}