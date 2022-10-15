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
	for (int i=0;i<n;++i){
		cin >> a[i];
	}

	int ind = 0;
	while (ind < n && a[ind] == ind+1) ind++;
	int ind2 = ind;
	vector<int> b = a;
	if (ind != n){
		for (;a[ind2] != ind + 1;++ind2){}

		for (int i=ind;i<=ind2;++i){
			b[i] = a[ind2 - (i - ind)];
		}
	}

	for (int i: b) cout << i << " ";
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