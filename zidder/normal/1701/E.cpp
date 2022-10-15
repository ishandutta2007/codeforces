#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int cnt(string s, string t) {
    int ti = t.size() - 1;
    int cnt = 0, c2 = 0;
    for (int i=s.size()-1;i>=0;--i) {
        if (ti >= 0 && s[i] == t[ti]) {
            ti--;
            c2++;
        } else {
            cnt += c2;
            c2 = 0;
            cnt++;
        }
    }
    if (ti == -1) return cnt;
    return -1;
}

void solve(int test_ind){
	int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = cnt(s, t);
    if (ans < 0) {
        cout << ans << endl;
        return;
    }

    vector<vector<short> > rk(n+1, vector<short>(m+1, -1));
    vector<vector<pair<short, short> > > lk(n+1, vector<pair<short, short> >(m+1, {-1, -1}));
    // rk[i][j] := min num moves right i passed from s and right j passed from t
    // lk[i][j] := min num moves left i passed from s and left j passed from t
    lk[0][0] = {1, 0};
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=m;++j) {
            if (lk[i-1][j].first != -1) {
                lk[i][j].first = lk[i-1][j].first + 2;
                lk[i][j].second = lk[i][j].first;
            }
            if (j && lk[i-1][j-1].first != -1 && s[i-1] == t[j-1]) {
                if (lk[i][j].first == -1) {
                    lk[i][j].first = lk[i-1][j-1].first + 1;
                    lk[i][j].second = lk[i-1][j-1].second;
                } else {
                    lk[i][j].first = min(lk[i-1][j-1].first + 1, (int)lk[i][j].first);
                    lk[i][j].second = min(lk[i-1][j-1].second, lk[i][j].second);
                }
            }
        }
    }
    rk[0][0] = 0;
    ans = min(ans, (int)lk[n][m].second);
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=m;++j) {
            if (rk[i-1][j] != -1) {
                rk[i][j] = rk[i-1][j] + 1;
            }
            if (j && rk[i-1][j-1] != -1 && s[n-i] == t[m-j]) {
                if (rk[i][j] == -1) rk[i][j] = rk[i-1][j-1] + 1;
                else rk[i][j] = min(rk[i-1][j-1] + 1, (int)rk[i][j]);
            }
            if (rk[i][j] != -1 && lk[n-i][m-j].second != -1) {
                // cout << i << " " << j << " " << rk[i][j] << " " << lk[n-i][m-j].first << " " << lk[n-i][m-j].second << endl;
                ans = min(rk[i][j] + lk[n-i][m-j].second, ans);
            }
        }
    }
    cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}