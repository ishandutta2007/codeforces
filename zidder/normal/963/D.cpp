// Frequency of String
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int N = 1000 * 100 + 5;
const int K = 26;

struct Vertex{
	int next[K];
	bool leaf = false;
	int p = -1;
	char pch;
	int link = -1;
	int _go[K];
	int exit_link = -1;
	vector<int> acc;
	Vertex(int p=-1, char ch='$'): p(p), pch(ch){
		for (int i=0;i<K;++i){
			next[i] = -1;
			_go[i] = -1;
		}
	}
};

vector<Vertex> t(1);
map<int, pair<int, int> > leafs;

int get_link(int);

int go(int v, char ch){
	int c = ch - 'a';
	if (t[v]._go[c] == -1){
		if (t[v].next[c] != -1)
			t[v]._go[c] = t[v].next[c];
		else
			t[v]._go[c] = v == 0 ? 0 : go(get_link(v), ch);
	}
	return t[v]._go[c];
}

int get_link(int v){
	if (t[v].link == -1){
		if (v == 0 || t[v].p == 0)
			t[v].link = 0;
		else
			t[v].link = go(get_link(t[v].p), t[v].pch);
	}
	return t[v].link;
}

int exit_link(int v){
	if (t[v].exit_link == -1){
		if (t[v].leaf || v == 0)
			t[v].exit_link = v;
		else
			t[v].exit_link = exit_link(get_link(v));
	}
	return t[v].exit_link;
}

int add_string(string s){
	int v = 0;
	for (char ch: s){
		int c = ch-'a';
		if (t[v].next[c] == -1){
			t[v].next[c] = t.size();
			t.emplace_back(v, ch);
		}
		v = t[v].next[c];
	}
	t[v].leaf = true;
	return v;
}

int main(){
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<int> inpt(n);
	for (int i = 0; i < n; ++i){
		int cnt;
		cin >> cnt;
		string cur;
		cin >> cur;
		inpt[i] = cur.size();
		leafs[add_string(cur)] = make_pair(cnt, i);
	}
	int v = 0;
	for (int ind = 0;ind<s.size(); ++ind){
		v = go(v, s[ind]);
		int vv = exit_link(v);
		while (vv){
			t[vv].acc.push_back(ind);
			vv = exit_link(get_link(vv));
		}
	}
	vector<int> ans(n);
	for (auto leaf: leafs){
		int v = leaf.first;
		int cnt = leaf.second.first;
		int ind = leaf.second.second;
		if (t[v].acc.size() < cnt){
			ans[ind] = -1;
			continue;
		}
		ans[ind] = s.size();
		for(int i=cnt-1;i<t[v].acc.size();i++){
			ans[ind] = min(t[v].acc[i] - t[v].acc[i-cnt+1] + inpt[ind], ans[ind]);
		}
	}
	for(int i:ans)
		cout << i << endl;
	return 0;
}