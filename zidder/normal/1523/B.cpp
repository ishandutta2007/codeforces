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
	vector<long long> v(n);
    for (int i=0;i<n;++i)
        cin >> v[i];
    cout << 3 * n << endl;

    // i j
    // 1 i + j j
    // 2 i + j -i
    // 1 j -i
    for (int i=1;i<n;i+=2){
        cout << 1 << " " << i << " " << i + 1 << endl;
        cout << 2 << " " << i << " " << i + 1 << endl;
        cout << 1 << " " << i << " " << i + 1 << endl;
        cout << 1 << " " << i << " " << i + 1 << endl;
        cout << 2 << " " << i << " " << i + 1 << endl;
        cout << 1 << " " << i << " " << i + 1 << endl;
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