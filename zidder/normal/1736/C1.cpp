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
    a[0] = 1;
    for (int i=1;i<n;++i) a[i] = min(a[i], a[i-1]+1);
    long long ans = 0;
    for (int i: a) ans += i;
    printf("%lld\n", ans);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}