#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int n;
int a[1000];
int b[1000];
bool used[2001];

void clear(){
    for(int i = 0; i <= 2000; i++) used[i] = false;
}

int calc_mex(){
    clear();
    for(int i = 0; i < n; i++) used[a[i]] = true;
    for(int i = 0; i <= 2000; i++) {
        if(!used[i]) return i;
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int mex = calc_mex();
    vector<int> ans;
    set<int> st;
    for(int i = 0; i < n; i++){
        if(a[i] != i) st.insert(i);
    }
    while(!st.empty()){
        if(mex == n || st.count(mex) == 0){
            int m = *st.begin();
            a[m] = mex;
            ans.push_back(m);
            mex = calc_mex();
        }else{
            a[mex] = mex;
            st.erase(mex);
            ans.push_back(mex);
            mex = calc_mex();
        }
    }
    cout << ans.size() << endl;
    for(int i : ans) cout << i+1 << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}