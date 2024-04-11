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
	vector<int> a(n), b(n);
	for (int i=0;i<n;++i){
		cin >> a[i];
	}for (int i=0;i<n;++i){
		cin >> b[i];
	}
	long long ans = 0;
	for (int i=1;i<n;++i){
		ans += min(abs(a[i] - a[i-1]) + abs(b[i] - b[i-1]), abs(a[i] - b[i-1]) + abs(b[i] - a[i-1]));
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