#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<pair<__int128, pair<long long, long long> > > lr;
    __int128 len = n;
    for (int i=0;i<c;++i) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        l--;
        r--;
        lr.push_back({len, {l, r}});
        // cout << (long long)len << endl;
        len += (r - l + 1);
    }
    for (int i=0;i<q;++i) {
        long long k;
        scanf("%lld", &k);
        --k;
        for (int j=c-1;j>=0;--j) {
            if (lr[j].first > k) continue;
            else {
                k = k - lr[j].first + lr[j].second.first;
            }
        }
        cout << s[k] << endl;
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