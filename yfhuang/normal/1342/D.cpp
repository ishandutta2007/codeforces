#include <bits/stdc++.h>
using namespace std;

int k, n;
const int maxn = 2e5 + 5;
int a[maxn];
int c[maxn];

typedef vector<int> vi;
typedef vector<vi> vii;

vii ans;

bool check(int m){
    ans = vii(m, vi(0));
    for(int i = n;i >= 1;i--){
        ans[i % m].push_back(a[i]);
    }
    for(int i = 0;i < m;i++){
        int sz = ans[i].size();
        for(int j = 0;j < sz;j++){
            if(j + 1 > c[ans[i][j]])
                return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1;i <= k;i++){
        cin >> c[i];
    }
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    check(l);
    cout << l << endl;
    for(int i = 0;i < ans.size();i++){
        cout << ans[i].size();
        for(int j = 0;j < ans[i].size();j++){
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}