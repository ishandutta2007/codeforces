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
	int neg = 0;
	for (int i: a) if (i<0) neg++;
	for (int i=0;i<neg-1;++i) if (abs(a[i]) < abs(a[i+1])){
		cout << "NO" << endl;
		return;
	}
	for (int i=neg;i<n-1;++i) if (abs(a[i]) > abs(a[i+1])){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}