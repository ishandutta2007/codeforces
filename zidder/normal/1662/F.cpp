#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 200000;
int n;

pair<int, int> st[4 * N];

void build(vector<int> &p, int l=0, int r=-1, int v=1) {
	if (r == -1) r = n;
	if (l + 1 == r) {
		st[v] = {l - p[l], p[l] + l};
		return;
	}
	int m = (l + r) / 2;
	build(p, l, m, 2*v);
	build(p, m, r, 2*v+1);
	st[v].first = min(st[2*v].first, st[2*v+1].first);
	st[v].second = max(st[2*v].second, st[2*v+1].second);
}

void remove(int x, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;
	if (l + 1 == r) {
		st[v] = {2 * N, -1};
		return;
	}
	int m = (l + r) / 2;
	if (x < m) remove(x, l, m, 2*v);
	else remove(x, m, r, 2*v+1);
	st[v].first = min(st[2*v].first, st[2*v+1].first);
	st[v].second = max(st[2*v].second, st[2*v+1].second);
}

void get(vector<int>& inds, int ql, int qr, int val, bool geq, int l=0, int r=-1, int v=1) {
	if (r == -1) r = n;
	if (l >= qr || r <= ql) return;
	int m = (l + r) / 2;
	if (ql <= l && qr >= r) {
		if (geq) {
			if (st[v].second >= val) {
				if (l + 1 == r) inds.push_back(l);
				else {
					get(inds, ql, qr, val, geq, l, m, 2*v);
					get(inds, ql, qr, val, geq, m, r, 2*v+1);
				}
			}
		} else {
			if (st[v].first <= val) {
				if (l + 1 == r) inds.push_back(l);
				else {
					get(inds, ql, qr, val, geq, l, m, 2*v);
					get(inds, ql, qr, val, geq, m, r, 2*v+1);
				}
			}
		}
		return;
	}
	get(inds, ql, qr, val, geq, l, m, 2*v);
	get(inds, ql, qr, val, geq, m, r, 2*v+1);
}

void solve(int test_ind){
	cin >> n;
	int a, b;
	cin >> a >> b;
	a--;b--;
	vector<int> p(n);
	for (int i=0;i<n;++i) scanf("%d", &p[i]);
	build(p);
	vector<int> d(n, -1);
	vector<int> q;
	q.push_back(a);
	d[a] = 0;
	remove(a);
	for (int indd=0;indd<q.size();++indd) {
		if (q[indd] == b) {
			cout << d[b] << endl;
			return;
		}
		int v = q[indd];
		vector<int> inds;
		get(inds, v - p[v], v, v, true);
		// cout << v << ": " << inds.size() << endl;
		for (int ind: inds) {
			// cout << v << " " << ind << endl;
			d[ind] = d[v] + 1;
			q.push_back(ind);
			remove(ind);
		}
		inds.clear();
		get(inds, v + 1, v + p[v] + 1, v, false);
		// cout << v << ": " << inds.size() << endl;
		for (int ind: inds) {
			// cout << v << " " << ind << endl;
			d[ind] = d[v] + 1;
			q.push_back(ind);
			remove(ind);
		}
		inds.clear();
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}