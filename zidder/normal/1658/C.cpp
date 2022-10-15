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
	
	for (int i=0;i<n;++i) scanf("%d", &p[i]);
	int one = -1, c=0;
	for (int i=0;i<n;++i) if (p[i] == 1) {one = i;c++;}
	if (c != 1) {
		cout << "NO" << endl;
		return;
	}
	for (int i=one;i!=(one+n-1)%n;i=(i+1)%n){
		int j = (i+1)%n;
		if (p[i] + 1 < p[j]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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