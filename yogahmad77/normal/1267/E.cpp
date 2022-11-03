#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char, int> pci;
#define sz(x) ((int)x.size())
#define f first
#define s second
#define mp make_pair

const int mx = 100;

int n, m, a[mx][mx];

int solve(int x){
    int sum = 0;
    int cnt = 0;
    vector<int> ve;
    for(int i = 0; i < m; i++){
        if(a[i][x] >= a[i][n - 1]) sum += a[i][x] - a[i][n - 1], cnt += 1;
        else ve.push_back(a[i][n - 1] - a[i][x]);
    }
    vector<int> dp(sum + 1, -1);
    dp[sum] = cnt;
    for(auto i : ve){
        for(int j = 0; j <= sum - i; j++)
            dp[j] = max(dp[j], dp[j + i] + 1);
    }
    int ret = 0;
    for(int i = 0; i <= sum; i++) ret = max(ret, dp[i]);
    return ret;
}

void bt(int x, int brp){
    vector<int> ve, ini(m);
    iota(ini.begin(), ini.end(), 0);
    for(int i = 0; i < m; i++){
        ve.push_back(a[i][n - 1] - a[i][x]);
    }
    sort(ini.begin(), ini.end(), [&](int i, int j){
        return ve[i] < ve[j];
    });
    for(int i = brp; i < m; i++) cout << ini[i] + 1 << ' ';
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int jaw = -1, di = -1;
    for(int i = 0; i < n - 1; i++){
        int aa = solve(i);
        if(aa > jaw){
            jaw = aa;
            di = i;
        }
    }
    cout << m - jaw << endl;
    bt(di, jaw);
    return 0;
}