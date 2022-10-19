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
	if (k == 1){
		cout << "YES" << endl;
		for (int i=0;i<n;++i){
			cout << i + 1 << endl;
		}
		return;
	}
	if (n * k % 2){
		cout << "NO" << endl;
		return;
	}

	if (n % 2 == 0){
		cout << "YES" << endl;
		int ind = 1;
		for (int i=1;i<=n;i+=2){
			for (int j=0;j<k;++j){
				cout << ind + 2 * j << " ";
			}
			cout << endl;
			for (int j=0;j<k;++j){
				cout << ind + 2 * j + 1 << " ";
			}
			cout << endl;
			ind += 2 * k;
		}
		return;
	}

	// n is odd
	cout << "NO" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}