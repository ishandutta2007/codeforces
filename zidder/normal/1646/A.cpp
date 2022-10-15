#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long n, s;
	cin >> n >> s;
	long long n2 = n * n;
	cout << s / n2 << endl;
	// (n+1-a) * (n - 1) + a * n * n >= s >= a * n * n
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}