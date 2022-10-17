#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int n, m, k, t;
vector<int> a;
vector<pair<int, pair<int, int> > > lrd;

bool check(int dm){
	long long ans = 0, loc = 0, ml=0;
	for(auto p: lrd){
		ans += p.first - 1 - loc;
		loc = p.first - 1;
		if (p.second.second <= dm || ml > p.second.first){
			ans += p.first - loc;
			loc = p.first;
			continue;
		}
//		cout << ans << " " << loc << " " << ml << endl;
		long long r = p.second.first;
//		cout << r << endl;
		ans += min(r - ml, r - loc) * 2;
		ml = p.second.first;
		ans++;
		loc++;
	}
//	cout << ans << " " << loc << " " << ml << endl;
	return (ans + (n + 1 - loc)) <= t;
}

void solve(int test_ind){
	cin >> m >> n >> k >> t;
	a = vector<int>(m);
	for(int i=0;i<m;++i)cin>>a[i];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for(int i=0;i<k;++i){
		int l, r, d;
		cin >> l >> r >> d;
		lrd.emplace_back(l, make_pair(r, d));
	}
	sort(lrd.begin(), lrd.end());
	int L = 0, R = m + 1;
	while(L + 1 < R){
		int M = (L + R) >> 1;
		if (check(a[M - 1])){
			L = M;
		} else{
			R = M;
		}
	}
	cout << L << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}