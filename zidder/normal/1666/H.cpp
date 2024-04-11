#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, d, hp;
	cin >> n >> d >> hp;
	{
		int g = __gcd(d, hp);
		d /= g;
		hp /= g;
	}
	vector<int> a(n);
	for (int &i: a) scanf("%d", &i);

	int s = 0;
	for (int &i: a) s += i;

	long long ans = 0;
	if (hp <= 40000){
		for (int &i: a) {
			s -= i;
			int num_cycles = i / d;
			long long cycle = 0;
			for (int j=0;j<hp;++j) {
				cycle += (j * d + hp - 1) / hp;
			}
			i %= d;
			s += i;
			ans += s * 1ll * num_cycles * 1ll * hp;
			ans += cycle * 1ll * num_cycles;
			ans += (d * 1ll * hp * 1ll * num_cycles * 1ll * (num_cycles - 1)) / 2;
			// cycle, cycle + d * hp, cycle + 2 * d * hp, ..
		}
	}

	// i < d


	// maxi <= 10^4
	// (a blows, b killed), a minimal, s.t. b > 0
	vector<vector<pair<int, int> > > bk(n);
	vector<pair<int, int> > last(n);
	int m = 0, mind = -1;
	int AA = d / hp;
	for (int i=0;i<n;++i){
		int rc = 0;
		int aa = a[i];
		while (a[i]) {
			int A = (hp - rc + d - 1) / d;
			int B = min((int)((A * 1ll * d + rc) / hp), a[i]);
			rc = (A * 1ll * d + rc) % hp;
			bk[i].push_back({A, B});
			a[i] -= B;
		}
		a[i] = aa;
		if (!bk[i].empty()){
			last[i] = bk[i].back();
			if (last[i].second <= AA || d < hp && last[i].second == 1 && last[i].first > (hp-1) / d) {
				bk[i].pop_back();
			} else {
				last[i] = {0, 0};
			}
			if (bk[i].size() > m){
				m = bk[i].size();
				mind = i;
			}
		}
	}

	vector<int> pi(m);
	for (int i=1; i<m; ++i) {
		int j = pi[i-1];
		while (j > 0 && bk[mind][i] != bk[mind][j])
			j = pi[j-1];
		if (bk[mind][i] == bk[mind][j])  ++j;
		pi[i] = j;
	}

	auto suf = [&](int l) -> int {
		if (l == 0) return 0;
		return pi[l-1];
	};

	set<pair<pair<int, int>, int> > lind;
	for (int i=0;i<n;++i) lind.emplace(make_pair(a[i], (int)bk[i].size()), i);
	while (!lind.empty()){
		auto p = *lind.rbegin();
		lind.erase(p);
		int suflen = suf(p.first.second);
		for (int j=0;j<p.first.second - suflen;++j){
			ans += (bk[p.second][j].first - 1) * 1ll * s;
			s -= bk[p.second][j].second;
			p.first.first -= bk[p.second][j].second;
			ans += s;
		}
		if (suflen){
			p.first.second = suflen;
			lind.insert(p);
		}
	}

	sort(last.begin(), last.end());
	if (d >= hp) reverse(last.begin(), last.end());
	for (auto p: last){
		if (p.second == 0) continue;
		ans += (p.first - 1) * 1ll * s;
		s -= p.second;
		ans += s;
	}
	cout << ans + 1 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}