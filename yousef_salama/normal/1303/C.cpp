#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;

int T;
char s[MAXN], ans[27];

bool g[26][26], vis[26];
int d[26];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		
		memset(g, false, sizeof g);
		memset(vis, false, sizeof vis);
		
		for(int i = 0; s[i]; i++){
			if(i > 0){
				g[s[i] - 'a'][s[i - 1] - 'a'] = true;
				g[s[i - 1] - 'a'][s[i] - 'a'] = true;
			}
		}
		
		bool ok = true;
		for(int c = 0; c < 26; c++){
			d[c] = 0;
			for(int e = 0; e < 26; e++)
				d[c] += g[c][e];
				
			if(d[c] > 2){
				ok = false;
				break;
			}
		}
		
		if(!ok){
			printf("NO\n");
			continue;
		}
		/*
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++)
				cout << g[i][j] << ' ';
			cout << endl;
		}*/
		
		int j = 0;
		for(int c = 0; c < 26; c++)if(!vis[c] && d[c] < 2){
			int i = c;
			while(true){
				vis[i] = true;
				ans[j++] = i + 'a';
				
				int nxt = -1;
				for(int e = 0; e < 26; e++)if(g[i][e] && !vis[e]){
					nxt = e;
					break;
				}
				
				if(nxt != -1){
					i = nxt;
				}else break;
			}
		}
		
		if(j < 26){
			printf("NO\n");
			continue;
		}
		ans[27] = 0;
		
		printf("YES\n%s\n", ans);
	}
	return 0;
}