#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

void solve(int test_ind){
	int n;
    cin >> n;
    vector<int> v(n);
    for (int i=n-1;i>=0;){
        int s = sqrtl(i + i);
        s *= s;
        int j = s - i;
        int i1 = i;
        for (int k=j;k<=i1;++k){
            v[k] = i--;
        }
    }
    for (int i: v) printf("%d ", i);
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