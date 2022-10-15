#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	int q;
	cin >> q;
	vector<pair<int, int> > a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i].first);
	long long sm = 0;
	for (int i=0;i<n;++i) sm += a[i].first;
	int last = -1, lst=0;
	for (int i=0;i<q;++i){
		int t, x;
		scanf("%d", &t);
		if (t == 1){
			int ind;
			scanf("%d%d", &ind, &x);
			ind--;
			if (a[ind].second < last) {
				a[ind].first = lst;
			}
			sm -= a[ind].first;
			sm += x;
			a[ind].first = x;
			a[ind].second = i + 1;
		} else {
			scanf("%d", &x);
			sm = x * 1ll * n;
			last = i + 1;
			lst = x;
		}
		printf("%lld\n", sm);
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