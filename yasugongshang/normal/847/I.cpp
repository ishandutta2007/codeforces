#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int N = 260;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int n, m, q, p, cnt;
char a[N][N];
long long noise[N][N];
int vis[N][N];

struct Node{
	int x, y, v;
};

inline void bfs(Node s)
{
	queue<Node> q;
	q.push(s);
	while (!q.empty()){
		Node u = q.front(); q.pop();
		for (int i = 0; i < 4; i ++){
			int xx = u.x + dx[i], yy = u.y + dy[i];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] != '*'){
				Node t; t.x = xx; t.y = yy; t.v = u.v/2;
				if (t.v > 0 && vis[t.x][t.y] != cnt){
					noise[t.x][t.y] += t.v;
					vis[t.x][t.y] = cnt;
					q.push(t);
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &q, &p);
	for (int i = 1; i <= n; i ++) scanf("%s", a[i]+1);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (a[i][j] >= 'A' && a[i][j] <= 'Z'){
				Node t; t.x = i; t.y = j; t.v = (a[i][j]-'A'+1)*q;
				noise[t.x][t.y] += t.v;
				vis[t.x][t.y] = ++ cnt;
				bfs(t);
			}
	int ans = 0;
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= m; j ++){
			//printf("%d ", noise[i][j]);
			if (noise[i][j] > p) ans ++;
		}
		//puts("");
	}
	printf("%d\n", ans);
	return 0;
}