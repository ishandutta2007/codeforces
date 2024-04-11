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
	int x = 1;
	while (x < n){
		x *= 2;
	}
	x /= 2;
	for (int i=0;i<n;++i){
		if (i >= x)
			printf("%d ", i);
		else
			printf("%d ", x-i-1);
	}
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