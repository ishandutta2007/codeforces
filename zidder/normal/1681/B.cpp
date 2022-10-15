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
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    int m;
    cin >> m;
    int s;
    for (int i=0;i<m;++i) {
        int x;
        scanf("%d", &x);
        (s += x) %= n;
    }
    cout << a[s] << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}