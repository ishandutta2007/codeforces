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
	vector<int> b = a;
	sort(b.begin(), b.end());
	if (a == b){
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}