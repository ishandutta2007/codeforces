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
	// max 2 a - 1, s.t. 2a-1 + a <= n
	// 3a-1 <= n
	// 3a <= n + 1
	// a <= (n + 1) / 3
	// a = (n+1) / 3

	// 00x00000
	// 0x000000
	// x0000000
	// 0000x000
	// 000x0000
	// 00000xxx
	// 00000x00
	// 00000x00

	int a = (n+1) / 3;
	vector<pair<int, int> > v;
	for (int i=0;i<a;++i){
		v.emplace_back(a - i - 1, i);
	}
	for (int i=0;i<a-1;++i){
		v.emplace_back(a-i-2+a, i+a);
	}
	for (int i=0;i<n-a-a-a+1;++i){
		if (i + 2 * a - 1 >= 0) v.emplace_back(i+2*a-1, i+2*a-1);
	}
	cout << v.size() << endl;
	for (auto &p: v){
		cout << p.first + 1 << " " << p.second + 1 << endl;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}