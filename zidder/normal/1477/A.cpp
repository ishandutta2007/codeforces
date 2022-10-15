#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i=0;i<n;++i){
        scanf("%lld", &v[i]);
    }
    long long g = 0;
    sort(v.begin(), v.end());
    for (auto vv: v)
        g = __gcd(vv - v[0], g);
    if (g == 0){
        if (k == v[0])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else{
    if ((k-v[0]) % g == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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