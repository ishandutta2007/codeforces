#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<int> v(n+m);
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			v[max(n-i-1, i) + max(m-j-1, j)]++;
		}
	}
	for (int i=0;i<n+m;++i){
		while (v[i]--){
			printf("%d ", i);
		}
	}
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}