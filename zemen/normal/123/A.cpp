#include <stdio.h>
#include <iostream>
#include <string.h>
#include <memory.h>

using namespace std;

int col[1001];
int rank[1001];

int get(int u) {
    if (col[u] == u)
        return u;
    return col[u] = get(col[u]);
}

void join(int u, int v) {
    u = get(u);
    v = get(v);
    if (rank[u] > rank[v])
        swap(u, v);
    if (rank[u] == rank[v])
        ++rank[v];
    col[u] = col[v];
}

int main() {
	int n;
	char s[1003];
	char res[1003];
	gets(s);
	n = strlen(s);
	int c[27];
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; ++i) {
		c[s[i] - 'a']++;
	}
	bool pr[1001];
	memset(pr, 0, sizeof(pr));
    for (int i = 0; i < 1001; ++i) {
        col[i] = i;
        rank[i] = 1;
    }
	for (int i = 2; i <= n; ++i) {
		if (!pr[i]) {
			for (int j = i; j + i <= n; j += i) {
				join (j - 1, j + i - 1);
			}
			for (int j = i * i; j < 1000; j += i) {
				pr[j] = 1;
			}
		}
	}
	bool used[1001];
	for (int i = 0; i < n; ++i)
		get(i);
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; ++i) {
		if (used[col[i]])
			continue;
		used[col[i]] = 1;
		int cnt = 0;
		for (int j = 0; j < n; ++j)
			cnt += (col[i] == col[j]);
		int min = -1;
		for (int j = 0; j < 26; ++j) {
			if (c[j] < cnt)
				continue;
			if (min == -1 || c[j] < c[min])
				min = j;
		}
		if (min == -1) {
			printf("NO");
			return 0;
		}
		c[min] -= cnt;
		for (int j = 0; j < n; ++j)
			if (col[i] == col[j]) {
				res[j] = min + 'a';
			}
	}
	res[n] = 0;
	printf("YES\n%s", res);
}