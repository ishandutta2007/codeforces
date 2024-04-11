#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int Q;
int ans;
map<int, int> cache;
int ask(int w) {
	if (cache.find(w) != cache.end()) return cache[w];
	if (Q == 0) throw "error";
	Q--;
	cout << "? " << w << endl;
	fflush(stdout);
	int x;
	cin >> x;
	if (x) ans = min(ans * 1ll, x * 1ll * w);
	return cache[w] = x;
}

void solve(int test_ind){
	int n;
	cin >> n;
	Q = n + 30;
	int r = n * 2001 + 5;
	ans = r;
	int l = n - 1;

	while (l + 1 != r) {
		int m = (l + r) / 2;
		if (ask(m) == 1) {
			r = m;
		} else {
			l = m;
		}
	}

	l = 0;
	r = 2001;
	while (l + 1 != r) {
		int m = (l + r) / 2;
		if (ask(m) == 0) {
			l = m;
		} else {
			r = m;
		}
	}
	l++;

	int h = 2;
	while (Q && h < n) {
		int h2 = ask((ans - 1) / h);
		if (h2 == 0) break;
		if (h2 > h) h = h2;
	}
	cout << "! " << ans << endl;
	fflush(stdout);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}