#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long r, b, k;
	cin >> r >> b >> k;
	if (r > b)
		swap(r, b);
	if (b == r){
		cout << "OBEY" << endl;
		return;
	}
	if (b % r == 0){
		int c = b / r - 1;
		if (c >= k){
			cout << "REBEL" << endl;
		}
		else{
			cout << "OBEY" << endl;
		}
		return;
	}
	long long g = __gcd(b, r);
	b /= g;
	r /= g;
	if ((b - 2) / r + 1 >= k){
		cout << "REBEL" << endl;
	}
	else{
		cout << "OBEY" << endl;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}