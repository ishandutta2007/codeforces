#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;

int ST[4 * 100001];

int dist(int qr, int l=0, int r=-1, int v=1){
	if (r == -1) r=n;
	if (l >= qr) return 0;
	if (r <= qr) return ST[v];
	int m = (l+r)/2;
	return dist(qr, l, m, 2*v)+dist(qr, m, r, 2*v+1);
}
void rem(int ind, int l=0, int r=-1, int v=1){
	if (r==-1) r = n;
	ST[v]--;
	if (l + 1 == r){
		return;
	}
	int m = (l + r) / 2;
	if (ind < m) rem(ind, l, m, 2*v);
	else rem(ind, m, r, 2*v+1);
}
void build(int l=0, int r=-1, int v=1){
	if(r==-1) r=n;
	ST[v] = r-l;
	if (l + 1 == r){
		return;
	}
	int m = (l+r)/2;
	build(l, m, 2*v);
	build(m, r, 2*v+1);
}

void solve(int test_ind){
	cin >> n;
	string s, t;
	cin >> s >> t;
	build();
	vector<vector<int> > inds(26);
	for (int i=0;i<n;++i){
		inds[s[i]-'a'].push_back(i);
	}
	for (auto &v: inds) reverse(v.begin(), v.end());

	long long ans = n * 1ll * n + 10;
	long long cans = 0;
	for (int i=0;i<n;++i){
		for (int j=t[i]-'a'-1; j>=0;--j){
			if (!inds[j].empty()){
				ans = min(ans, cans + dist(inds[j].back()));
			}
		}
		if (inds[t[i]-'a'].empty()) break;
		cans += dist(inds[t[i]-'a'].back());
		rem(inds[t[i]-'a'].back());
		inds[t[i]-'a'].pop_back();
	}
	if (ans == n * 1ll * n + 10){
		cout << -1 << endl;
	}
	else cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}