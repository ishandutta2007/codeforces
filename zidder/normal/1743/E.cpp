#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int p1, p2;
    long long t1, t2;
    cin >> p1 >> t1;
    cin >> p2 >> t2;
    int h, s;
    cin >> h >> s;
    vector<long long> dp(h + 1, t1 * h);
    dp[0] = 0;
    for (int i=1;i<=h;++i) {
        for (int j=1;j<=i;++j) {
            long long t = t1 * j;
            long long dh = j * (p1 - s);
            if (dh > i) dh = i;
            dp[i] = min(dp[i], dp[i-dh] + t);
            t = max(t, ((t-1)/t2+1) * t2);
            dh = t / t1 * (p1 - s) + t / t2 * (p2 - s) + s;
            dh = min(dh, (long long)i);
            dp[i] = min(dp[i], dp[i-dh] + t);
        }
        for (int j=1;j<=i;++j) {
            long long t = t2 * j;
            long long dh = j * (p2 - s);
            if (dh > i) dh = i;
            dp[i] = min(dp[i], dp[i-dh] + t);
            t = max(t, ((t-1)/t1+1) * t1);
            dh = t / t1 * (p1 - s) + t / t2 * (p2 - s) + s;
            dh = min(dh, (long long)i);
            dp[i] = min(dp[i], dp[i-dh] + t);
        }
    }
    cout << dp[h] << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}