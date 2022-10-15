#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, q;
	cin >> n >> q;
	vector<int> p(n);
	for (int &i: p) scanf("%d", &i);
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	vector<long long> pr(n+1);
	for (int i=0;i<n;++i) pr[i+1] = pr[i] + p[i];
	for (int i=0;i<q;++i){
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", pr[x] - pr[x-y]);
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