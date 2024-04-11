#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int f(int l, int i){
	int p = 1<<i;
	if (l < p) return 0;
	if ((l&p)==0){
		return (l / p / 2) * p;
	}
	return l / p / 2 * p + l % p + 1;
}

void solve(int test_ind){
	int l, r;
	cin >> l >> r;
	int mn = r - l + 1;
	for (int i=0;i<20;++i){
		f(r, i);
		// cout << i << " " << f(r, i) << " " << f(l-1, i) << endl;
		mn = min(mn ,r - l + 1 - f(r, i) + f(l-1, i));
	}
	cout << mn << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}