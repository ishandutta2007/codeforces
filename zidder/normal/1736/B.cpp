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
    vector<long long> b(n + 1);
    b[0] = a[0];
    b[n] = a[n-1];
    for (int i=1;i<n;++i){
        b[i] = a[i] * 1ll * a[i-1] / __gcd(a[i], a[i-1]);
    }
    for (int i=0;i<n;++i) {
        if (__gcd(b[i], b[i+1]) != a[i]) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}