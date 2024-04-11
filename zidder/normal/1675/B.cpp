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
	for (int &i: a) scanf("%d", &i);
	int c = 0;
	for (int i=n-1;i>0;--i){
		if (a[i] == 0) {
			cout << -1 << endl;
			return;
		}
		while (a[i] <= a[i-1]) {
			a[i-1] /= 2;
			c++;
		}
	}
	cout << c << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}