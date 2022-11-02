#include <bits/stdc++.h>
using namespace std;

const int N = 155;
char name[N][N];
int len[N];
vector < int > e[N];
int income[N];
int n;

void init() {
	scanf("%d",&n);
	for (int i=1; i<=n; i++) {
		scanf("%s",name[i]);
		len[i] = strlen(name[i]);
	}
}

void Edge() {
	for (int i=1; i<n; i++) {
		int st = 0;
		while (st < len[i] && st < len[i+1] && name[i][st] == name[i+1][st]) st++;
		if (st == len[i + 1]) {
			puts("Impossible");
			exit(0);
		} else if (st == len[i]) continue;
		else {
			e[name[i][st]].push_back((int)(name[i + 1][st]));
			income[name[i + 1][st]] ++;
		}
	}
}

vector < char > ans;
void topicSort() {
	queue < int > que;
	for (int i='a'; i<='z'; i++) if (!income[i]) {
		que.push(i);
		ans.push_back(i);
	}
	while (!que.empty()) {
		int pos = que.front();que.pop();
		for (int i=0;i<(int)e[pos].size();i++) {
			income[e[pos][i]]--;
			if (income[e[pos][i]] == 0) {
				que.push(e[pos][i]);
				ans.push_back(e[pos][i]);
			}
		}
	}
	if (ans.size() != 26) puts("Impossible");
	else for (int i=0;i<26;i++) putchar(ans[i]);
	puts("");
}

int main() {
	init();
	Edge();
	topicSort();
	return 0;
}