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
	int odd = 0;
	for (int i=0;i<n;++i) {
		int x;
		scanf("%d", &x);
		if (x%2) odd++;
	}
	cout << min(odd, n-odd) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}