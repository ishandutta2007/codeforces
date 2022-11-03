#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char, int> pci;
#define sz(x) ((int)x.size())
#define f first
#define s second
#define mp make_pair

long long C(int n, int k){
    if(n < k || k < 0) return 0;
    long long ret = 1;
    if(k > n - k) k = n - k;
    for(int i = 1; i <= k; i++){
        ret *= (n - k + i);
        ret /= i;
    }
    return ret;
}

void solve(){
    long long n;
    cin >> n;
    int ke = 2;
    vector<int> ve;
    while(n > 0){
        // cout << ke << ' ' << n % ke << endl;
        ve.push_back(n % ke);
        n /= ke;
        ke += 1;
    }
    sort(ve.begin(), ve.end());
    n = ve.size();
    int sampai = n + 1;
    long long ans = 1;
    for(int i = n - 1; i >= 0; i--){
        int berapa = sampai - max(ve[i], 1);
        int j = i;
        while(j - 1 >= 0 && ve[j - 1] == ve[i]) j -= 1;
        int ada = i - j + 1;
        ans *= C(berapa, ada);
        sampai -= ada;
        i = j;
    }
    if (ve[0] == 0) {
        // cout << "Maskasdasda\n";
        long long tmp = 1;
        sampai = n;
        for(int i = n - 1; i >= 1; i--){
            int berapa = sampai - max(ve[i], 1);
            int j = i;
            while(j - 1 >= 1 && ve[j - 1] == ve[i]) j -= 1;
            int ada = i - j + 1;
            tmp *= C(berapa, ada);
            sampai -= ada;
            i = j;
        }
        ans -= tmp;
    }
    cout << ans - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}