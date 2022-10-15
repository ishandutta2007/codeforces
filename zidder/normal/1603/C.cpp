// https://codeforces.com/problemset/problem/1603/C

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 998244353;
int a[100002];
void solve(){
    int n;
    cin >> n;
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    long long ans = 0;
    vector<pair<int, int> > rght(640); // num, count, sum
    for (int i=n-1;i>=0;--i){
    	vector<pair<int, int> > lft(640); // num, count, sum
        lft[0].first = 1;
        //cout << a[i] << ": ";
        if (i + 1 < n)
        for (int j=0;j<640;++j){
            int nxtval = a[i + 1] / (j + 1);
            if (j > 320) nxtval = j - 320;
	    if (nxtval == 0) continue;
            long long c = (a[i] - 1) / nxtval + 1;
            int l = a[i] / c;
            //cout << p.first << " " << p.second.first << " " << p.second.second << " " << c << endl << "   ";
            int ind = c - 1;
            if (ind > 320){
                ind = l + 320;
            }
    	    lft[ind].first = (lft[ind].first + rght[j].first) % MOD;
	        lft[ind].second = (lft[ind].second + ((c - 1) * rght[j].first + rght[j].second)) % MOD;
            (ans += (c - 1) * rght[j].first + rght[j].second) %= MOD;
        }
        //cout << endl;
        //cout << ans << endl;
        swap(lft, rght);
    }

    printf("%lld\n", ans);
}

int main(){
    int TT;
    cin >> TT;
    while (TT--){
        solve();
    }
    return 0;
}