#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Node {
	int lind=-1;
	int rind=-1;
	int val;
} bor[5000000];
int bind = 1;

void add(int val){
	int v = 0;
	for (int i=29;i>=0;--i){
		int rght = ((1<<i) & val);
		if (rght){
			if (bor[v].rind == -1){
				bor[v].rind = bind++;
			}
			v = bor[v].rind;
		}
		else {
			if (bor[v].lind == -1){
				bor[v].lind = bind++;
			}
			v = bor[v].lind;
		}
		bor[v].val = val;
	}
}

pair<int, int> slv2(int v1, int v2, int k, int d){
	if (d == -1)
		return {bor[v1].val, bor[v2].val};
	if (k & (1 << d)){
		pair<int, int> ans, ans1;
		if (bor[v1].lind != -1 && bor[v2].rind != -1) {
			ans = slv2(bor[v1].lind, bor[v2].rind, k, d-1);
			if (ans.second != -1){
				return ans;
			}
		}
		if (bor[v1].rind != -1 && bor[v2].lind != -1) {
			ans1 = slv2(bor[v1].rind, bor[v2].lind, k, d-1);
			if (ans1.second != -1)
				return ans1;
		}
		return {bor[v1].val, -1};
	} else {
		if (bor[v1].lind != -1 && bor[v2].rind != -1)
			return {bor[bor[v1].lind].val, bor[bor[v2].rind].val};
		if (bor[v1].rind != -1 && bor[v2].lind != -1)
			return {bor[bor[v1].rind].val, bor[bor[v2].lind].val};
		pair<int, int> ans, ans1;
		if (bor[v1].lind != -1 && bor[v2].lind != -1){
			ans = slv2(bor[v1].lind, bor[v2].lind, k, d-1);
			if (ans.second != -1)
				return ans;
		}
		if (bor[v1].rind != -1 && bor[v2].rind != -1){
			ans1 = slv2(bor[v1].rind, bor[v2].rind, k, d-1);
			if (ans1.second != -1)
				return ans1;
		}
		return {bor[v1].val, -1};
	}
}
vector<int> vc;
void slv(int v, int k, int d=29){
	int one = ((1<<d) & k);
	vc.clear();
	if (!one) {
		vector<int> vv;
		if (bor[v].lind != -1) {
			slv(bor[v].lind, k, d-1);
			for (int i: vc) {
				vv.push_back(i);
			}
		}
		if (bor[v].rind != -1) {
			slv(bor[v].rind, k, d-1);
			for (int i: vc){
				vv.push_back(i);
			}
		}
		swap(vv, vc);
	} else {
		if (bor[v].lind != -1 && bor[v].rind != -1) {
			auto p = slv2(bor[v].lind, bor[v].rind, k, d-1);
			vc.push_back(p.first);
			if (p.second != -1) vc.push_back(p.second);
		} else {
			vc = {bor[v].val};
		}
	}
}

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	if (k == 0){
		cout << n << endl;
		for (int i=1;i<=n;++i){
			printf("%d ", i);
		}
		cout << endl;
		return;
	}
	map<int, vector<int> > m;
	for (int i=0;i<n;++i) m[a[i]].push_back(i);
	for (int i: a) add(i);
	slv(0, k);
	if (vc.size() < 2) cout << -1 << endl;
	else {
		cout << vc.size() << endl;
		for (int i: vc){
			printf("%d ", 1+m[i].back());
			m[i].pop_back();
		}
		cout << endl;
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