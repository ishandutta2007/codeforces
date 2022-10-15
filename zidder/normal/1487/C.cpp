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
	if (n % 2 == 0) {
		for (int i=1;i<=n;++i){
			for (int j=i+1;j<=n;++j){
				if (i+n/2 == j) cout << "0 ";
				else if ((i+j + (j-i>n/2))%2) cout << "1 ";
				else cout << "-1 ";
			}
		}
		cout << endl;
	} else {
		for (int i=1;i<=n;++i){
			for (int j=i+1;j<=n;++j){
				if ((i+j)%2) cout << "1 ";
				else cout << "-1 ";
			}
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