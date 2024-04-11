#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, p[MAXN];
bool vis[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		p[i]--;
	}

	for(int i = 0; i < n; i++)if(p[i] == i){
		printf("YES\n");
		for(int j = 0; j < n; j++)if(j != i)
			printf("%d %d\n", i + 1, j + 1);
		return 0;
	}

	for(int i = 0; i < n; i++)if(p[p[i]] == i){
		vis[i] = vis[p[i]] = true;
		for(int j = 0; j < n; j++)if(!vis[j]){
			int s = 0, k = j;
			do{
				vis[k] = true;

				k = p[k];
				s ^= 1;
			}while(k != j);

			if(s == 1){
				printf("NO\n");
				return 0;
			}
		}
		printf("YES\n");
		printf("%d %d\n", i + 1, p[i] + 1);

		memset(vis, false, sizeof vis);
		vis[i] = vis[p[i]] = true;
		for(int j = 0; j < n; j++)if(!vis[j]){
			int s = 0, k = j;
			do{
				vis[k] = true;
				if(s == 0)printf("%d %d\n", i + 1, k + 1);
				else printf("%d %d\n", p[i] + 1, k + 1);

				k = p[k];
				s ^= 1;
			}while(k != j);
		}
		return 0;
	}

	printf("NO\n");

	return 0;
}