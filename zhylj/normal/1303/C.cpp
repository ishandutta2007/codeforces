#include <bits/stdc++.h>

const int kMaxN = 300 + 5;

char s[kMaxN]; bool vis[kMaxN];

std::deque<int> que;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(vis, false, sizeof(vis));
		scanf("%s", s + 1);
		int n = strlen(s + 1); que.clear();
		que.push_back(s[1] - 'a'); vis[s[1] - 'a'] = true;
		int ptr = 0; bool flag = true;
		for(int i = 2; i <= n; ++i) {
			int c = s[i] - 'a';
			if(!vis[c]) {
				if(ptr == que.size() - 1) que.push_back(c), ++ptr;
				else if(ptr == 0) que.push_front(c);
				else { flag = false; break; }
			} else {
				if(ptr != 0 && que[ptr - 1] == c) ptr = ptr - 1;
				else if(ptr != que.size() - 1 && que[ptr + 1] == c) ptr = ptr + 1;
				else { flag = false; break; }
			}
			vis[c] = true;
		}
		if(flag) {
			printf("YES\n");
			for(int i = 0; i < que.size(); ++i) printf("%c", que[i] + 'a');
			for(int i = 0; i < 26; ++i)
				if(!vis[i]) printf("%c", i + 'a');
			printf("\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}