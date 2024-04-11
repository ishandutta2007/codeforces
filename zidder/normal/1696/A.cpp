#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, z;
    cin >> n >> z;
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    int m = 0;
    for (int i: a) m = max(m, i|z);
    cout << m << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}