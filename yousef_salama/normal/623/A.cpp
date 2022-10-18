#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int n, m, ai, bi;
bool G[MAXN][MAXN];

char s[MAXN];
bool vis[MAXN];

bool color(int i, char c){
	vis[i] = true;

	char c_;
	if(c == 'a')c_ = 'c';
	else c_ = 'a';

	for(int j = 0; j < n; j++)if(!G[i][j]){
		if(vis[j]){
			if(s[j] != c_)return false;
			else continue;
		}

		s[i] = c;
		s[j] = c_;

		if(!color(j, c_))return false;
	}
	return true;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		G[i][i] = true;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &ai, &bi);
		G[ai - 1][bi - 1] = true;
		G[bi - 1][ai - 1] = true;
	}

	s[n] = 0;
	for(int i = 0; i < n; i++)
		s[i] = 'b';

	bool ok = true;
	for(int i = 0; i < n; i++)if(!vis[i])
		ok &= color(i, 'a');

	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)if(G[i][j]){
		if(s[i] == 'a' && s[j] == 'c')ok = false;
		if(s[i] == 'c' && s[j] == 'a')ok = false;
	}

	if(ok)printf("Yes\n%s\n", s);
	else printf("No\n");

	return 0;
}