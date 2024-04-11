#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
using P = pair<int, int>;

vector<int> get_and_compress(int n){
    vector<P> p(n);
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        p[i] = P(a, i);
    }
    sort(p.begin(), p.end());
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        auto [_, idx] = p[i];
        ans[idx] = i;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    
    auto a = get_and_compress(n);
   
    vector<int> idx(n);
    for(int i = 0; i < n; i++) idx[a[i]] = i;
    vector<vector<bool>> inv(n, vector<bool>(n, false));
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]) {
                inv[a[j]][a[i]] = true;
                cnt++;
            }
        }
    }
    auto print_vec = [&](){
        for(int x : a)cout << x << ' ';
        cout << endl;
        // for(int x : idx)cout << x << ' ';
        // cout << endl;
    };
    auto exec_swap = [&](int l, int r){
        swap(a[idx[l]], a[idx[r]]);
        swap(idx[l], idx[r]);
    };
    // print_vec();
    cout << cnt << endl;
    while(cnt--){
        bool ok = false;
        for(int d = 1; d < n; d++){
            for(int l = 0; l+d < n; l++){
                int r = l+d;
                if(idx[l] > idx[r]){
                    // cout << "swap " << l <<  ' ' << r << endl;
                    cout << min(idx[l], idx[r])+1 << ' ' << max(idx[l], idx[r])+1 << endl;
                    exec_swap(l, r);
                    // print_vec();
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
    }
}