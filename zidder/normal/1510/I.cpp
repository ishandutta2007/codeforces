#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <random>

using namespace std;

long double ipow(int x){
	if (x > 15) return 0.0;
	long double res = 1;
	for(int i = 0; i < x; i++){
		res /= 2;
	}
	return res;
}

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int mn = 0;
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		long double num = 0, denom = 0;
		for (int j = 0; j < n; j++){
			num += (s[j] - 48) * ipow(a[j] - mn);
			denom += ipow(a[j] - mn);
		}

		int ret = (((long double) rand() / (RAND_MAX)) < num / denom);
 		cout << ret << endl;
		fflush(stdout);

		int ans;
		cin >> ans;

		mn = 100000;
		for (int j = 0; j < n; j++){
			if (ans ^ (s[j] - 48)){
				a[j]++;
			}
			mn = min(mn, a[j]);
		}
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