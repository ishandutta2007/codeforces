#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const long long inf = 2000000000000000007;

void solve(int test_ind){
	int n;
	cin >> n;
	multiset<long long> apt, t;
	map<long long, vector<long long> > a, b;
	set<long long> keter;
	// a -> vector ti
	// b = b - ti -> vector ti
	for (int i=0;i<n;++i){
		long long ai, bi, ti;
		scanf("%lld%lld%lld", &ai, &bi, &ti);
		apt.insert(ai + ti);
		a[ai].push_back(ti);
		b[bi - ti + 1].push_back(ti);
		keter.insert(ai);
		keter.insert(bi - ti + 1);
	}

	long long ans = 0, cur = 0;
	auto itt = keter.begin();
	while (itt != keter.end()){
		long long ket = *itt;
		long long tnext = inf, aptnext = inf, tt;

		if (cur < ket){
			{
				if (!t.empty()){
					tt = (*t.begin());
					tnext = tt + cur;
				}
				// get min cur + t
			}
			{
				if (!apt.empty())
					aptnext = min(aptnext, *apt.begin());
				// get min a + t
			}

			if (tnext == inf && aptnext == inf){
				// no more ket
				break;
			}

			if (tnext < aptnext){
				long long count = (ket - cur) / tt;
				if (count == 0){
					count = 1;
				}
				ans += count;
				cur += count * tt;
			} else {
				cur = aptnext;
				ans++;
			}
		}
		else {
			if (b.find(ket) != b.end()){
				for (long long ti: b[ket]){
					t.erase(t.find(ti));
				}
			}
			itt++;
			if (a.find(ket) != a.end()){
				for (long long ti: a[ket]){
					t.insert(ti);
					apt.erase(apt.find(ket + ti));
				}
			}
		}

	}
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}