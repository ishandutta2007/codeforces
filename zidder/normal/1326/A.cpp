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
    if (n == 1){
        cout << -1 << endl;
        return;
    }
    int k = 1;
    if ((n - k) % 3 == 0)
        k++;
    for (int i=0;i<n-k;i++)
        cout << 2;
    for (int i=0;i<k;++i)
        cout << 3;
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