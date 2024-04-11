#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool wins(long long h1, long long d1, long long h2, long long d2) {
	long long c1 = (h2 + d1 - 1) / d1;
	long long c2 = (h1 + d2 - 1) / d2;
	return c1 <= c2;
}

void solve(int test_ind){
	long long hc, dc;
	long long hm, dm;
	long long k, w, a;
	cin >> hc >> dc >> hm >> dm >> k >> w >> a;
	dc += w * k;
	for (int i=0;i<=k;++i){
		if (wins(hc, dc, hm, dm)) {
			cout << "YES" << endl;
			return;
		}
		hc += a;
		dc -= w;
	}
	cout << "NO" << endl;
	return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}