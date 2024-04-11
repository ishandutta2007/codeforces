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
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	int mi = 0, ma=0;
	for (int i=0;i<n;++i){
		if (a[mi] > a[i]) mi = i;
		if (a[ma] < a[i]) ma = i;
	}
	cout << mi + 1<< " " << 1 + ma << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}