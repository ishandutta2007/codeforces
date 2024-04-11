#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int a[26] = {0};
	for (char c: s) a[c - 'a']++;
	int e=0, o=0;
	for (int i=0;i<26;++i){
		e += a[i] / 2;
		o += a[i] % 2;
	}
	int ans = 0;
	for (int i=0;i<=min((k + 1) / 2, e);++i){
		// e - i in pairs
		// o + 2*i odds
		int c = (e-i) % k;
		if (c == 0){
			ans = max(ans, (e - i) / k * 2 + (o + 2 * i >= k));
		} else if (k - c > o + 2 * i){
			ans = max(ans, (e-i) / k * 2);
		} else {
			ans = max(ans, (e-i) / k * 2 + 1);
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}