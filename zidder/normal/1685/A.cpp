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
	if (n%2){
		cout << "NO" << endl;
		return;
	}
	sort(a.begin(), a.end());
	vector<int> b;
	for (int i=0;i<n/2;++i){
		if (a[i] == a[i+n/2-(i!=0)]) {
			cout << "NO" << endl;
			return;
		}
		b.push_back(a[i]);
		b.push_back(a[i+n/2]);
	}
	cout << "YES" << endl;
	for (int i: b) printf("%d ", i);
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