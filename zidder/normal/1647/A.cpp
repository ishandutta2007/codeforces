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
	// 121212121 = 3a-2
	if (n % 3 == 1){
		cout << 1;
		n--;
		for (int s=0;s<n;s+=3){
			cout << 21;
		}
		cout << endl;
		return;
	}
	for (int s=0;s<n/3;++s){
		cout << 21;
	}
	if (n % 3) cout << 2;
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