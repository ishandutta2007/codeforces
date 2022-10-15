#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 2 * 500005;


struct ST {
	int n;
	int *T;
	ST(int n): n(n){
		T = new int[4 * n];
		for (int i=0;i<4*n;++i) T[i] = 0;
	}

	~ST(){
		delete[] T;
	}

	void _sett(int ind, int val, int l, int r, int v){
		if (l + 1 == r) {
			T[v] = max(T[v], val);
			return;
		}
		int m = (l + r) / 2;
		if (ind < m) _sett(ind, val, l, m, 2*v);
		else _sett(ind, val, m, r, 2*v+1);
		T[v] = max(T[2*v], T[2*v+1]);
	}

	void sett(int ind, int val){
		_sett(ind, val + N, 0, n, 1);
	}

	int _query(int ql, int qr, int l, int r, int v){
		if (ql >= r || qr <= l) return 0;
		if (ql <= l && qr >= r) return T[v];
		int m = (l + r) / 2;
		return max(_query(ql, qr, l, m, 2*v), _query(ql, qr, m, r, 2*v+1));
	}

	int query(int ql, int qr){
		// last >= a with ind >= ql
		return _query(ql, qr, 0, n, 1) - N;
	}
};

void solve(int test_ind){
	// 2 -1 -100 101 -1 -1 -1 -1 -1 -1 -1 -1

	// query max dp where pref[x] = pref[y]
	// query y + max dp - x where pref[x] < pref[y]
	// query -y + max dp + x where pref[x] > pref[y]
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i: v) scanf("%d", &i);
	vector<long long> prf(n+1);
	set<long long> prfst;
	for (int i=0;i<n;++i){
		prf[i+1] = prf[i] + v[i];
		prfst.insert(prf[i]);
		prfst.insert(prf[i+1]);
	}

	vector<long long> prfsorted(prfst.begin(), prfst.end());
	map<long long, int> prfind;
	map<long long, int> mx;
	int m = prfsorted.size();
	for (int i=0;i<m;++i) prfind[prfsorted[i]] = i;

	ST stl(m), str(m);
	auto sg = [&](int x){
		return x>0?1:x<0?-1:0;
	};

	mx[0] = N;
	stl.sett(prfind[0], 0);
	str.sett(prfind[0], 0);


	for(int ind=0;ind < n;++ind) {
		int ans = -N;
		long long p = prf[ind + 1];
		int pi = prfind[p];
		ans = max(ans, ind + 1 + stl.query(0, pi));
		// cout << ind << " " << ans << endl;
		ans = max(ans, mx[p] - N);
		// cout << ind << " " << ans << endl;
		ans = max(ans, -(ind + 1) + str.query(pi + 1, m));
		// cout << ind << " " << ans << endl;
		mx[p] = ans + N;
		stl.sett(pi, ans - ind - 1);
		str.sett(pi, ans + ind + 1);
	}

	cout << mx[prf[n]] - N << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}