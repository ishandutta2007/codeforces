#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, ans=-1;
	cin >> n;
	map<int, int> x;
	for(int i=0;i<n;++i){
		int q;
		cin >> q;
		if (x.count(q)){
			if (ans==-1)
				ans = i - x[q] + 1;
			else
				ans = min(ans, i-x[q] + 1);
		}
		
		x[q] = i;
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}