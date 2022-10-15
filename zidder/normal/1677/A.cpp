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
	vector<int> p(n);
	for (int &i: p) scanf("%d", &i);
	vector<vector<int> > pref(n+1, vector<int>(n+1));
	for (int i=0;i<n;++i){
		for (int j=0;j<=n;++j){
			pref[i+1][j] = pref[i][j];
			pref[i+1][j] += p[i] < j;
		}
	}
	for (int i=0;i<=n;++i){
		// for (int j=0;j<=n;++j) cout << pref[i][j] << " ";
		// cout << endl;
	}
	// cout << endl;
	// pref[i][j] means < i indices < j values
	long long ans = 0;
	for (int b=1;b<n;++b){
		for (int c=b+1;c<n;++c){
			// cout << b << " " <<pref[b][p[c]] * (p[b] - pref[c+1][p[b]]) << endl;
			ans += pref[b][p[c]] * (p[b] - 1 - pref[c+1][p[b]]);
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