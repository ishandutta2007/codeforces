#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long partsum(int a, int k){
    long long dmin = a / k;
    long long dmax = dmin + 1;
    int cnt = a - k * dmin;
    return dmin * dmin * (k - cnt) + dmax * dmax * cnt;
}

void solve(int test_ind){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long sa = 0;
    for(int i=0;i<n;++i){
        scanf("%d", &a[i]);
        sa += a[i];
    }
    sort(a.begin(), a.end());
    k -= n;
    set<pair<long long, int> > mp;
    vector<int> cuts(n, 1);
    for(int i=0;i<n;++i){
        long long profit = partsum(a[i], cuts[i] + 1) - partsum(a[i], cuts[i]);
        mp.emplace(profit, i);
    }
    while(k--){
        int i = mp.begin() -> second;
        mp.erase(mp.begin());
        cuts[i]++;
        long long profit = partsum(a[i], cuts[i] + 1) - partsum(a[i], cuts[i]);
        mp.emplace(profit, i);
    }

    long long sum = 0;
    for(int i=0;i<n;i++)
        sum += partsum(a[i], cuts[i]);
    cout << sum << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}