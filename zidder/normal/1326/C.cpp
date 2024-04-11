#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    long long n, k, s = 0;
    cin >> n >> k;
    vector<int> p(n), v;
    for(int i=0;i<n;++i){
        cin >> p[i];
        if (p[i] > n-k){
            v.push_back(i);
            s += p[i];
        }
    }
    long long mod = 998244353;
    long long res = 1;
    for (int i=1;i<k;i++)
        (res *= (v[i] - v[i-1])) %= mod;
    cout << s << " " << res << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}