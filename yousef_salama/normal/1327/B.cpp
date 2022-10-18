#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int t, n, k, vi;
vector <int> g[MAXN];
bool vis[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &k);
			
			g[i].clear();
			while(k--){
				scanf("%d", &vi);
				vi--;
				
				g[i].push_back(vi);
			}
			
			vis[i] = false;
		}
		
		int a = -1;
		for(int i = 0; i < n; i++){
			int b = -1;
			for(int v : g[i]){
				if(vis[v])continue;
				
				b = v;
				break;
			}
			
			if(b == -1){
				if(a == -1){
					a = i;
				}
			}else{
				vis[b] = true;
			}
		}
		
		if(a == -1){
			printf("OPTIMAL\n");
		}else{
			int j = 0;
			while(vis[j])j++;
			
			printf("IMPROVE\n%d %d\n", a + 1, j + 1);
		}
	}
	
	
	return 0;
}