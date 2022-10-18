#include <bits/stdc++.h>
using namespace std;

vector <int> res;

struct BIT{
	vector <int> tree;
	BIT(){}
	void init(int n){
		tree.resize(n + 1, 0);
	}
	void add(int u, int val){
		u++;
		while(u < (int)tree.size()){
			tree[u] += val;
			u += u & (-u);
		}
	}
	int sum(int u){
		u++;
		int r = 0;
		while(u > 0){
			r += tree[u];
			u -= u & (-u);
		}
		return r;
	}
} bit;

struct query{
	int index, l, r;
	query(){}
	query(int index, int l, int r): index(index), l(l), r(r){}
};

struct suffix_automaton{
	struct node{
		map <int, int> go;
		int suflink, len;
		vector <int> endpoints;
		
		node(int suflink, int len): suflink(suflink), len(len){}
		node(int suflink, int len, const vector <int>& endpoints): suflink(suflink), len(len), endpoints(endpoints){}
		node(){}
	};
	vector <node> tree;
	int len, n, last;
	
	suffix_automaton(){
		tree.push_back(node(-1, 0));
		n = 0;
		len = 0, last = n++;
	}
	
	void extend(int c, bool add = true){
		int cur = last;
		last = n++;
		while(cur != -1 && !tree[cur].go.count(c)){
			tree[cur].go[c] = last;
			cur = tree[cur].suflink;
		}
		
		if(cur == -1){
			if(add)tree.push_back(node(0, len + 1, {len}));
			else tree.push_back(node(0, len + 1));
			
			len++;
			return;
		}
		
		if(tree[tree[cur].go[c]].len == tree[cur].len + 1){
			if(add)tree.push_back(node(tree[cur].go[c], len + 1, {len}));
			else tree.push_back(node(tree[cur].go[c], len + 1));
			
			len++;
			return;
		}
		
		int parent = tree[cur].go[c];
		int tmp = n++;
		node ntmp = tree[parent];
		ntmp.len = tree[cur].len + 1;
		ntmp.endpoints.clear();
		
		while(cur != -1 && tree[cur].go[c] == parent){
			tree[cur].go[c] = tmp;
			cur = tree[cur].suflink;
		}
		
		tree[parent].suflink = tmp;
		
		if(add)tree.push_back(node(tmp, len + 1, {len}));
		else tree.push_back(node(tmp, len + 1));
		
		tree.push_back(ntmp);
		len++;
	}
	
	void print(int i = 0, vector <int> cur = {}){
		cout << i << " :: ";
		for(int j : cur)
			cout << j << ", ";
		cout << endl;
		
		for(auto c : tree[i].go){
			cur.push_back(c.first);
			print(c.second, cur);
			cur.pop_back();
		}
	}
	
	vector < vector <query> > q;
	vector < vector <int> > g, par;
	
	void init(){
		q.resize(n);
		g.resize(n);
		par.resize(n, vector <int> (20));
		
		for(int i = 1; i < n; i++)
			g[tree[i].suflink].push_back(i);
			
		for(int i = 0; i < n; i++)
			par[i][0] = tree[i].suflink;
		
		for(int j = 1; j < 20; j++)
		for(int i = 0; i < n; i++){
			if(par[i][j - 1] == -1)par[i][j] = -1;
			else par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	
	void dfs(int u){
		for(query z : q[u]){
			int l = z.l;
			int r = min(len - 1, 2 * z.r - z.l);
			
			res[z.index] = 0;
			res[z.index] -= bit.sum(len - 1);
			res[z.index] += bit.sum(min(r + 1, len - 1));
			res[z.index] -= bit.sum(l - 2);
		}
		
		for(int i : tree[u].endpoints)
			bit.add(i, 1);
		
		for(int v : g[u]){
			dfs(v);
		}
		
		for(query z : q[u]){
			int l = z.l;
			int r = min(len - 1, 2 * z.r - z.l);
			
			res[z.index] += bit.sum(len - 1);
			res[z.index] -= bit.sum(min(r + 1, len - 1));
			res[z.index] += bit.sum(l - 2);
		}
	}
	void solve(){
		bit.init(len);
		dfs(0);
	}
	
};

int main(){
	int n;
	scanf("%d", &n);
	
	vector <int> h(n);
	for(int i = 0; i < n; i++)scanf("%d", &h[i]);
	
	int q;
	scanf("%d", &q);
	
	vector < pair <int, int> > vq(q);
	
	for(int i = 0; i < q; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		l--, r--;
		
		vq[i] = {l, r};
	}
	
	if(n == 1){
		for(int i = 0; i < q; i++)printf("0\n");
		return 0;
	}
	
	suffix_automaton tree;
	vector <int> vlast;
	
	for(int i = 0; i < n - 1; i++){
		tree.extend(h[i + 1] - h[i]);
		vlast.push_back(tree.last);
	}
	tree.extend(1 << 30, false);
	vlast.push_back(tree.last);
	
	for(int i = 0; i < n - 1; i++){
		tree.extend(h[i] - h[i + 1], false);
		vlast.push_back(tree.last);
	}
	tree.init();
	
	res.resize(q, -1);
	for(int i = 0; i < q; i++){
		if(vq[i].first == vq[i].second){
			res[i] = n - 1;
			continue;
		}
		
		vq[i].second--;
		
		int cur = vlast[vq[i].second + n];
		for(int j = 19; j >= 0; j--)if(tree.par[cur][j] != -1){
			int p = tree.par[cur][j];
			if(tree.tree[p].len >= vq[i].second - vq[i].first + 1){
				cur = p;
			}
		}
		
		tree.q[cur].push_back(query(i, vq[i].first, vq[i].second));
	}
	tree.solve();
	
	for(int i = 0; i < q; i++){
		printf("%d\n", res[i]);
	}
	
	
	return 0;
}