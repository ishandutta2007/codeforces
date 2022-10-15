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
    int mx = 0;
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        cout << mx + b << " ";
        mx = max(mx, mx + b);
    }
    cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}