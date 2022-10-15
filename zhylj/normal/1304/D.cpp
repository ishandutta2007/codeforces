#include <bits/stdc++.h>

const int kMaxN = 2e5 + 5;

char s[kMaxN];
int p1[kMaxN];
std::deque<int> que;

void Output() {
	for(int i = 0; i < que.size(); ++i)
		printf("%d ", que[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d%s", &n, s + 1);
		que.clear();
		que.push_back(1);
		auto it = que.begin();
		for(int i = 2; i <= n; ++i) {
			if(s[i - 1] == '<') it = que.insert(++it, i);
			else que.push_front(i), it = que.begin();
		}
		for(int i = 0; i < n; ++i) p1[que[i]] = i + 1;
		for(int i = 1; i <= n; ++i) printf("%d ", p1[i]);
		printf("\n");
		que.clear();
		que.push_back(1);
		it = que.begin();
		for(int i = 2; i <= n; ++i) {
			if(s[i - 1] == '>') it = que.insert(it, i);
			else que.push_back(i), it = --que.end();
		}
		for(int i = 0; i < n; ++i) p1[que[i]] = i + 1;
		for(int i = 1; i <= n; ++i) printf("%d ", p1[i]);
		printf("\n");
	}
	return 0;
}