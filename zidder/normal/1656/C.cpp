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
	set<int> a;
	for (int i=0;i<n;++i){
		int x;
		scanf("%d", &x);
		a.insert(x);
	}
	if (n == 1){
		cout << "yes" << endl;
		return;
	}
	if (a.count(0) && a.count(1)) {
		cout << "NO" << endl;
		return;
	}
	if (a.count(1) == 0){
		cout << "YES" << endl;
		return;
	}
	
	for (int i: a){
		if (a.count(i+1)){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}