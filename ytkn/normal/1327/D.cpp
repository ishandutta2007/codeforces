#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

vector<int> G[200000];
int n;
int p[200000], c[200000];
bool used[200000];

void init(){
    for(int i = 0; i < n; i++) {
        G[i].clear();
        used[i] = false;
    }
}


void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    int ans = n*10;
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++){
        if(!used[i]){
            vector<int> v;
            int tmp = p[i];
            used[tmp] = true;
            v.push_back(tmp);
            while(tmp != i){
                used[tmp] = true;
                tmp = p[tmp];
                v.push_back(tmp);
            }
            int cnt = v.size();
            // cout << cnt << endl;
            for(int j = 1; j*j <= cnt; j++){
                if(cnt%j == 0){
                    for(int k = 0; k < j; k++){
                        bool ok = true;
                        int cur = c[v[k]];
                        for(int l = 1; l < cnt/j; l++){
                            int idx = j*l+k;
                            if(cur != c[v[idx]]) {
                                ok = false;
                                break;
                            }
                        }
                        if(ok) ans = min(ans, j);
                    }
                    for(int k = 0; k < cnt/j; k++){
                        bool ok = true;
                        int cur = c[v[k]];
                        for(int l = 1; l < j; l++){
                            int idx = (cnt/j)*l+k;
                            if(cur != c[v[idx]]) {
                                ok = false;
                                break;
                            }
                        }
                        if(ok) ans = min(ans, cnt/j);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    init();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        solve();
    }
}