#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long ST[4 * 100003];
long long lazy[4 * 100003];

int m;
void build(vector<int> &bind, int l=0, int r=-1, int v=1){
	if (r == -1) r = m;
	lazy[v] = 0;
	if (l + 1 == r) {
		ST[v] = bind[l];
		return;
	}
	int mid = (l + r) / 2;
	build(bind, l, mid, 2 * v);
	build(bind, mid, r, 2 * v + 1);
	ST[v] = min(ST[2 * v], ST[2 * v + 1]);
}

void push(int v){
	lazy[2 * v] += lazy[v];
	lazy[2 * v + 1] += lazy[v];
	lazy[v] = 0;
	ST[v] = min(ST[2 * v] + lazy[2 * v], ST[2 * v + 1] + lazy[2*v+1]);
}

void update(int ql, int d, int l=0, int r=-1, int v=1){
	if (r == -1) r = m;
	if (r <= ql) return;
	if (ql <= l){
		if (l + 1 == r){
			ST[v] += d + lazy[v];
			lazy[v] = 0;
			return;
		}
		lazy[v] += d;
		push(v);
		return;
	}
	push(v);
	int mid = (l + r) / 2;
	update(ql, d, l, mid, 2 * v);
	update(ql, d, mid, r, 2 * v + 1);
	push(v);
}

void update2(int q, int val, int l=0, int r=-1, int v=1){
	if (r == -1) r = m;
	if (l + 1 == r){
		ST[v] = val;
		lazy[v] = 0;
		return;
	}
	push(v);
	int mid = (l + r) / 2;
	if (q < mid) update2(q, val, l, mid, 2 * v);
	else update2(q, val, mid, r, 2 * v + 1);
	push(v);
}

long long query(){
	return ST[1] + lazy[1];
}

void solve(int test_ind){
	int n;
	scanf("%d%d", &n, &m);
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end()); // hereafter size = m

	vector<pair<int, int> > A(m);
	for (int i=0;i<m;++i) A[i] = make_pair(a[i+n-m], i);

	vector<pair<int, int> > B(m);
	vector<vector<int> > b;
	for (int i=0;i<m;++i){
		int c = 0;
		scanf("%d", &c);
		b.emplace_back(c);
		long long sm = 0;
		for (int j=0;j<c;++j){
			int x;
			scanf("%d", &x);
			b[i][j] = x;
			sm += x;
		}
		B[i].first = (sm + c - 1) / c;
		B[i].second = i;
	}
	sort(B.begin(), B.end());

	vector<int> bind(m);
	for (int i=0;i<m;++i){
		auto it = upper_bound(A.begin(), A.end(), make_pair(B[i].first, -1));
		if (it == A.end()){
			bind[i] = i - m;
		} else {
			bind[i] = i - (it->second);
		}
	}

	build(bind);

	vector<vector<bool> > ans;
	for (int i=0;i<m;++i) ans.emplace_back(b[i].size(), false);

	for (int i=0;i<m;++i){
		long long sm = 0;
		int ind = B[i].second;
		for (int j=0;j<b[ind].size();++j){
			sm += b[ind][j];
		}
		update(i, -1);
		update2(i, 1);
		// cout << query() << endl;
		for (int j=0;j<b[ind].size();++j){
			sm -= b[ind][j];
			int nsm = (sm + b[ind].size() - 2) / (b[ind].size() - 1);
			auto bit = upper_bound(B.begin(), B.end(), make_pair(nsm, -1));
			int nind = bit-B.begin();
			int uind = nind;
			if (nind > i){
				nind--;
				update(nind + 1, 1);
			} else {
				update(nind, 1);
			}
			// if (ind == 0) cout << j << " " << bind[i] + i << " " << nind << endl;
			auto it = upper_bound(A.begin(), A.end(), make_pair(nsm, -1));
			int bbind;
			if (it == A.end()){
				bbind = nind - m;
			} else {
				bbind = nind - (it->second);
			}
			// cout << ind << " " << j << " " << nind << " " << bbind << endl;

			ans[ind][j] = min(bbind+0ll, query()) >= 0;
			sm += b[ind][j];
			update(uind, -1);
		}
		update(i, 1);
		update2(i, bind[i]);
	}

	for (auto &VV: ans) for (bool anss: VV) printf("%d", anss);
	printf("\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}