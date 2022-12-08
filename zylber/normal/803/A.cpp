#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<vector<int> > ans(n, vector<int>(n, 0));
	if(k > n*n) cout << -1 << endl;
	else {
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				if(ans[i][j] == 0 && k > (i!=j)) {
					k -= 1 + (i!=j);
					ans[i][j] = 1;
					ans[j][i] = 1;
				}
			}
		
		if(k) {
			for(int i=0; i<n; i++) {
				if(ans[i][i] == 0 && k) {
					ans[i][i] = 1;
					k--;
				}
			}
		}
	
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(j) cout << " ";
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
}