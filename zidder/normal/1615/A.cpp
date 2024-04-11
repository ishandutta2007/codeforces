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

	sort(a.begin(), a.end());
	int sm = 0;
	for (int i=0;i<n;++i){
		sm += a[i];
	}
	if (sm % n) cout << 1 << endl;
	else cout << 0 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}