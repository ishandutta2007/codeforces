#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int x;
    cin >> x;
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    bool v[4] = {false};
    v[x] = true;
    if (x) x = a[x-1];
    v[x] = true;
    if (x) x = a[x-1];
    v[x] = true;
    if (x) x = a[x-1];
    v[x] = true;
    if (x) x = a[x-1];
    if (v[1] && v[2] && v[3]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}