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
	vector<int> a;
	for (int i=0;i<n;++i){
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	long long r = 0, b = a.back();
	int rght = a.size() - 2;
	for (int l=0;l<rght;++l,--rght){
		r += a[l];
		b += a[rght];
		if (r > b){
			cout << "YES" <<endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}