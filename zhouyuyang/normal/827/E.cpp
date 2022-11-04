#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

int T, n, vis[N], can[N];
map<char, int> mp, ha = {{'?', 0}, {'V', 1}, {'K', 2}};
char s[N];

bool check(int l){
	static int vis[N];
	for(int i = 0; i < l; ++ i){
		int who = ha[s[i]], now = i + l;
		while(now < n){
			if(who && s[now] != '?' && who != ha[s[now]]) return false;
			if(s[now] != '?') who = ha[s[now]];
			now += l;
		}
	}
	return true;
}

int main(){
	cin >> T;
	while(T --){
		scanf("%d", &n);
		scanf("%s", s);
		memset(vis, 0, sizeof(int) * (n+1));
		memset(can, 0, sizeof(int) * (n+1));
		mp.clear();
		for(int i = 0; i < n; ++ i) mp[s[i]] = 1;
		if(mp['V'] + mp['K'] <= 1){
			printf("%d\n", n);
			for(int i = 1; i <= n; ++ i) printf("%d%c", i, i == n ? '\n' : ' ');
			continue;
		}
	  for(int i = 2; i <= n; ++ i){
			if(!vis[i]){
				if(check(i)){
					for(int j = i; j <= n; j += i) can[j] = true;
					 can[i] = true;
				}
			}
		}
		int ans = 0, first = 1;
		for(int i = 2; i <= n; ++ i) ans += can[i];
		printf("%d\n", ans);
		for(int i = 2; i <= n; ++ i){
			if(can[i]){
				if(first) first = false;
				else putchar(' ');
				printf("%d", i);
			}
		}
		puts("");
	}
	return 0;
}