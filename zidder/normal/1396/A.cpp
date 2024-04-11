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
    vector<long long> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    if (n==1){
        cout << 1 << " " << 1 << endl << -a[0] << endl;
        a[0] = 0;
        cout << 1 << " " << 1 << endl << 0 << endl;
        cout << 1 << " " << 1 << endl << 0 << endl;
        return;
    }
    cout << 1 <<" " <<n - 1 << endl;
    for (int i=0; i < n - 1;++i){
        long long d = (n-1) * a[i];
        a[i] += d;
        cout << d << " ";
    }
    cout << endl;
    cout << 1 << " " << n << endl;
    for(int i =0;i<n;++i){
        if (i != n-1)
            cout << -a[i] << " ";
        else
            cout << 0 << " ";
    }
    cout << endl << n << " " << n << endl;
    cout << -a[n-1] << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}