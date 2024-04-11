#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    long long a, b, n;
    cin >> a >> b >> n;
    int c = 0;
    if (a < b)
        swap(a, b);
    while (a <= n && b <= n){
        b += a;
        c++;
        swap(a, b);
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