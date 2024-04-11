#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 105;

char s[maxn];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

char g[maxn][maxn];
int n,m;

int main(){
	cin >> n >> m;
	int sx,sy,ex,ey;
	for(int i = 1;i <= n;i++){
		scanf("%s",g[i] + 1);
		for(int j = 1;j <= m;j++){
			if(g[i][j] == 'S'){
				sx = i,sy = j;
			}
			if(g[i][j] == 'E'){
				ex = i,ey = j;
			}
		}
	}
	scanf("%s",s + 1);
	int k = strlen(s + 1);
	int a[10];
	for(int i = 0;i < 4;i++) a[i] = i;
	int ans = 0;
	do{
		int nx = sx,ny = sy;
		bool flag = true;
		for(int i = 1;i <= k;i++){
			nx += dx[a[s[i] - '0']];
			ny += dy[a[s[i] - '0']];
			if(nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '#'){
				flag = false;
				break;
			}
			if(g[nx][ny] == 'E') break;
		}
		if(g[nx][ny] != 'E') flag = false;
		if(flag) ans++;
	}while(next_permutation(a,a + 4));
	cout << ans << endl;
	return 0;
}