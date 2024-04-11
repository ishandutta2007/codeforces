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
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	vector<int> pc(n+1);
	for (int i=0;i<n;++i) pc[i+1] = pc[i] + (a[i] == 0);
	int ans = 0;
	for (int i=0;i<n;++i){
		for (int j=i;j<n;++j){
			ans += (j + 1 - i) + (pc[j+1] - pc[i]);
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