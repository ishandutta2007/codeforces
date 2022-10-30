#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX_N = 100000 + 10;
const int MAX_LEN = 1000000 + 10;

vector<pair<int, int> > matching;
int ans = 0;

struct Bag {
	vector<int> a, b;

	int size() {
		return a.size() + b.size();
	}
};

Bag*merge(Bag*a, Bag*b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a->size() < b->size())
		swap(a, b);
	a->a.insert(a->a.end(), b->a.begin(), b->a.end());
	a->b.insert(a->b.end(), b->b.begin(), b->b.end());
	delete b;
	return a;
}

Bag*shuffle(Bag*a) {
	if (a == 0)
		return a;
	while (a->a.size() > 0 && a->b.size() > 0) {
		int x = a->a.back();
		int y = a->b.back();
		a->a.pop_back();
		a->b.pop_back();
		matching.push_back(make_pair(x, y));
	}
	return a;
}

struct Trie {
	Trie*ch[26];
	Bag bag;

	Trie() {
		memset(ch, 0, sizeof ch);
	}

	Trie*go(int w) {
		if (ch[w] == 0)
			ch[w] = new Trie;
		return ch[w];
	}
	Bag*dfs() {
		Bag*t = new Bag;
		*t = bag;

		for (int i = 0; i < 26; ++i) {
			if (ch[i])
				t = merge(t, ch[i]->dfs());
		}

		shuffle(t);
		ans += t->size();
		return t;
	}
}*root = new Trie;

int n;

int main() {
	cin >> n;
	static char buf[MAX_LEN];
	int S = 0;
	for (int i = 0; i < n; ++i) {
		scanf(" ");
		scanf("%s", buf);
		int L = strlen(buf);
		S += L;
		Trie*rt = root;
		for (int j = 0; j < L; ++j) {
			rt = rt->go(buf[j] - 'a');
		}
		rt->bag.a.push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		scanf(" ");
		scanf("%s", buf);
		int L = strlen(buf);
		S += L;
		Trie*rt = root;
		for (int j = 0; j < L; ++j) {
			rt = rt->go(buf[j] - 'a');
		}
		rt->bag.b.push_back(i);
	}
	ans = 0;
	root->dfs();
	cout << (S - ans) / 2 << endl;
	for (int i = 0; i < matching.size(); ++i) {
		printf("%d %d\n", matching[i].first + 1, matching[i].second + 1);
	}
}