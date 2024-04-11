#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;

struct Node{
	vector<int> children;
	vector<long long> psum;
	int l;
	int r;
	int par = -1;
	long long cnt;
	Node(){
		cnt = 0;
		children.clear();
		psum.clear();
		par = -1;
	}
} nodes[300010];
int nind = 1;

void print(int v, int t=0){
	for (int i=0;i<t;++i) cout << "  ";
	cout << v << ": " << nodes[v].cnt << endl;
	for (int ch: nodes[v].children) print(ch, t+1);
}

void dfs(int v){
	nodes[v].psum.push_back(0);
	for (int ch: nodes[v].children) {
		nodes[ch].par = v;
		dfs(ch);
		nodes[v].cnt += nodes[ch].cnt;
		nodes[v].psum.push_back(nodes[v].cnt);
	}
	long long m = nodes[v].children.size();
	nodes[v].cnt += m * (m + 1) / 2;
}

int bisect(vector<int> &v, int x){
	int l = 0, r = v.size();
	while (l < r){
		int m = (l + r) / 2;
		if (v[m] < x) l = m + 1;
		else r = m;
	}
	return l;
}

long long query(int v, int lc, int rc){
	if (lc == nodes[v].children.front() && rc == nodes[v].children.back()) return nodes[v].cnt;
	int lind = bisect(nodes[v].children, lc);
	int rind = bisect(nodes[v].children, rc);
	long long m = (rind - lind + 1);
	return m * (m + 1) / 2 + nodes[v].psum[rind+1] - nodes[v].psum[lind];
}

void solve(int test_ind){
	int q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> inds(n), rinds(n);
	vector<int> v;
	for (int i=0;i<n;++i){
		if (s[i] == ')') {
			if (!v.empty()) {	
				int l1 = v.back();
				v.pop_back();
				rinds[i] = inds[l1];
				nodes[inds[l1]].l = l1;
				nodes[inds[l1]].r = i;
				if (v.empty()){
					nodes[0].children.push_back(inds[l1]);
				} else {
					nodes[inds[v.back()]].children.push_back(inds[l1]);
				}
			}
		} else if(s[i] == '(') {
			inds[i] = nind++;
			v.push_back(i);
		}
	}
	while (!v.empty()){
		int l1 = v.back();
		v.pop_back();
		if (v.empty()){
			nodes[0].children.push_back(inds[l1]);
		} else {
			nodes[inds[v.back()]].children.push_back(inds[l1]);
		}
	}

	dfs(0);
	// print(vend);

	for (int i=0;i<q;++i){
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 2){
			l--;
			r--;
			// cout << l << " " << r << endl;
			// cout << inds[l] << " " << rinds[r] << endl;
			// if (nodes[inds[l]].par == -1) throw "err";
			printf("%lld\n", query(nodes[inds[l]].par, inds[l], rinds[r]));
		}
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}