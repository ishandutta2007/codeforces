#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    long long n;
    cin >> n;
    if (n%2050 != 0){
        cout << -1 << endl;
        return;
    }
    n /= 2050;
    int c = 0;
    while (n){
        c+=n%10;
        n/=10;
    }
    cout << c << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}