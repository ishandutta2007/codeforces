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
	vector<bool> a(1000001);
	int x;
	for (int i=0;i<n;++i) {
		scanf("%d", &x);
		a[x] = true;
	}
	int c = 0;
	for (int i=1;i<=1000000;++i){
		int g = 0;
		for (int j=i;j<=1000000;j+=i){
			if (a[j]){
				g = __gcd(g, j);
			}
		}
		if (g == i){
			c++;
		}
	}
	cout << c - n << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}