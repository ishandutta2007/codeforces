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
	if (k * 2 > n + 1){
		cout << -1 << endl;
		return;
	}

	vector<vector<char> > a(n, vector<char>(n, '.'));
	for (int i=0;i<k;++i){
		a[2*i][2*i] = 'R';
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			cout << a[i][j];
		}
		cout << endl;
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