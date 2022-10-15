#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> A;
int a(int k){
    if (A[k-1])
        return A[k-1];
    cout << "? " << k << endl;
    fflush(stdout);
    int x;
    cin >> x;
    A[k-1] = x;
    return x;
}

void solve(int test_ind){
    int n;
    cin >> n;
    A = vector<int>(n);
    if (n == 1){
        cout << "! 1" << endl;
        fflush(stdout);
        return;
    }
    int lft = 0;
    int rgt = n + 1;
    while (lft + 2 < rgt){
        int mid = (rgt + lft) / 2;
        int m1 = mid + 1;
        if (a(m1) > a(mid))
            rgt = m1;
        else
            lft = mid;
    }
    cout << "! " << lft + 1 << endl;
    fflush(stdout);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}