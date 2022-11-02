#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;
int n;
const int maxn = 2e3 + 5;
int a[maxn];
bool vis[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= 2 * n;i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + 2 * n);
        bool flag = false;
        vector<pi> op;
        int ans;
        for(int i = 1;i < 2 * n;i++){
            int cur = a[i] + a[2 * n];
            multiset<int> s;
            for(int j = 1;j <= 2 * n;j++){
                s.insert(a[j]);
            }
            op.clear();
            for(int j = 1;j <= n;j++){
                int val = *s.rbegin();
                int val1 = cur - val;
                auto it1 = s.find(val);
                s.erase(it1);
                if(s.find(val1) != s.end()){
                    auto it = s.find(val1);
                    s.erase(it);
                    op.push_back(mp(val1, val));
                }
                cur = max(val, val1);
            }
            if(op.size() == n){
                ans = a[i] + a[2 * n];
                flag = true;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
            cout << ans << endl;
            for(int i = 0;i < n;i++){
                cout << op[i].fi << " " << op[i].se << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}