#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 300002;

int n;
int mn[4 * N];

int mnnn(int x, int y){
	if (x==-1) return y;
	if (y==-1) return x;
	return min(x, y);
}

void insrt(int i, int val, int l=0, int r=-1, int v=1){
	if (r==-1)r=n+1;
	mn[v] = mnnn(mn[v], val);
	if (l+1==r) return;
	int m = (l+r)/2;
	if (i < m) insrt(i, val, l, m, 2*v);
	else insrt(i, val, m, r, 2*v+1);
}

void rem(int i, int l=0, int r=-1, int v=1){
	if (r==-1) r=n+1;
	if (l+1 == r){
		mn[v] = N;
		return;
	}
	int m=(l+r)/2;
	if (i<m) rem(i, l, m, 2*v);
	else rem(i, m, r, 2*v+1);
	mn[v] = mnnn(mn[2*v], mn[2*v+1]);
}

set<int> qu(int i, int l=0, int r=-1, int v=1){
	if (r==-1) r=n+1;
	if (r <= i) return {};
	if (mn[v] > i) return {};
	if (l + 1 == r) return {l};
	int m=(l+r)/2;
	set<int> lft=qu(i, l, m, 2*v), rght=qu(i, m, r, 2*v+1);
	if (lft.size() < rght.size()) swap(lft, rght);
	for (int i: rght) lft.insert(i);
	return lft;
}

void solve(int test_ind){
	cin >> n;
	vector<int> a(n+1), b(n+1);
	for (int i=0;i<4*N;++i) mn[i] = N;
	for (int i=1;i<=n;++i) scanf("%d", &a[i]);
	for (int i=1;i<=n;++i) scanf("%d", &b[i]);
	for (int i=1;i<=n;++i) insrt(i, max(i-a[i], 0));
	// i + (0 to ai) = k hard -> j = k - bk easy
	vector<vector<int> > slips(n+1);
	for (int i=1;i<=n;++i){
		slips[i + b[i]].push_back(i);
	}

	int iter=0;
	set<int> cur;
	cur.insert(0);
	rem(0);
	vector<int> prev(n+1, -1);
	while (!cur.empty()){
		if (cur.find(n) != cur.end())
			break;
		iter++;
		set<int> intr, nxt;
		for (int i: cur){
			for (int j: qu(i)){
				prev[j] = i;
				intr.insert(j);
				rem(j);
			}
		}

		for (int i: intr){
			for (int j: slips[i])
				nxt.insert(j);
		}
		swap(cur, nxt);
	}
	if (cur.empty()) cout << -1 << endl;
	else {
		cout << iter << endl;
		int c = n;
		while (c!=0){
			cout << prev[c] << " ";
			c = prev[c];
			c += b[c];
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