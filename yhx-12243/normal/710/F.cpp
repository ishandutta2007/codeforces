#include <bits/stdc++.h>
#define N 3414680
#define LN 20
using namespace std;

typedef long long ll;

namespace AC{
	int cnt = 0;
	int d[N][26], p[N], f[N], que[N];
	int val[N], size[N]; ll sum[N];

	// add a new string to trie
	int append(int root, char *_str){
		int t = (root ? root : (root = ++cnt)), id;
		for(; *_str; ++_str){
			id = *_str - 97;
			p[d[t][id] ? d[t][id] : (d[t][id] = ++cnt)] = t;
			t = d[t][id];
		}
		++val[t];
		return root;
	}

	// dfs merge two tries
	int dfs(int x, int u){
		int id, y;
		if(!u) u = ++cnt;
		val[u] += val[x];
		for(id = 0; id < 26; ++id)
			if((y = d[x][id]) && p[y] == x){
				int &v = d[u][id];
				v = dfs(y, v); p[v] = u;
			}
		return u;
	}

	// clear the Aho-Corasick tags
	void clear(int x){
		int id, y;
		sum[x] = f[x] = 0;
		for(id = 0; id < 26; ++id)
			if(y = d[x][id])
				p[y] == x ? clear(y) : void(d[x][id] = 0);
	}

	// merge two tries to one trie (ensure root != 0)
	void merge(int root, int root2){
		clear(root);
		size[root] += size[root2]; size[root2] = 0;
		dfs(root2, root);
	}

	// build ac tags
	void build(int root){
		int h, ta = 1, i, t, id;
		clear(root);
		que[0] = root; f[root] = 0;
		for(h = 0; h < ta; ++h)
			for(i = que[h], id = 0; id < 26; ++id){
				t = (f[i] ? d[f[i]][id] : root);
				int &u = d[i][id];
				if(!u) {u = t; continue;}
				f[u] = t; que[ta++] = u;
				sum[u] = val[u] + sum[t];
				//la[u] = (val[t] ? t : la[t]);
			}
	}

	// match a string
	ll match(int root, char *_str){
		int t = root, id; ll ret = 0;
		for(; *_str; ++_str){
			id = *_str - 97;
			t = (d[t][id] ? d[t][id] : root);
			ret += sum[t];
		}
		return ret;
	}
}

int rootA[LN], rootB[LN];
bool acA[LN], acB[LN];
char s[N];

void insert(int *root, bool *ac){
	int i;
	for(i = 0; i < LN; ++i)
		if(AC::size[root[i]] >= 1 << i){
			if(root[i + 1]) {AC::merge(root[i + 1], root[i]); ac[i + 1] = false;}
			else {root[i + 1] = root[i]; ac[i + 1] = ac[i];}
			root[i] = 0; ac[i] = false;
		}
		else{
			if(root[i] && ac[i]) {ac[i] = false; AC::clear(root[i]);}
			root[i] = AC::append(root[i], s);
			++AC::size[root[i]];
			return;
		}
}

ll query(int *root, bool *ac){
	int i; ll ret = 0;
	for(i = 0; i < LN; ++i){
		if(!root[i]) continue;
		if(!ac[i]) {AC::build(root[i]); ac[i] = true;}
		ret += AC::match(root[i], s);
	}
	return ret;
}

int main(){
	int q, op;
	ios::sync_with_stdio(false);
	for(cin >> q; q; --q)
		switch(cin >> op >> s, op){
			case 1: insert(rootA, acA); break;
			case 2: insert(rootB, acB); break;
			case 3: cout << query(rootA, acA) - query(rootB, acB) << endl;
		}
	return 0;
}