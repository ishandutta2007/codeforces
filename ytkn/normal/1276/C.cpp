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
set<int> st;
map<int, int> cnt;
vector<int> v[400001];
int a[400001];

int l, r;
vector<int> ret[400001];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
        if(cnt.count(a[i]) == 0) cnt[a[i]] = 1;
        else cnt[a[i]]++;
    }
    for(auto i : cnt){
        int m = i.first; int c = i.second;
        v[c].push_back(m);
    }
    int all = st.size();
    int tmp = 0;
    int sum = 0;
    int ans = 0;
    for(int i = 1; i*i <= n; i++){
        tmp += v[i].size();
        sum += i*v[i].size();
        int tmp_cnt = (all-tmp)*i+sum;
        tmp_cnt = (tmp_cnt/i)*i;
        // cout << i << ' ' << tmp_cnt << ' ' << sum << ' ' << tmp << endl;
        if(tmp_cnt > ans){
            if(tmp_cnt/i < i) continue;
            ans = tmp_cnt;
            l = i;
            r = tmp_cnt/i;
        }
    }
    cout << ans << endl;
    cout << l << ' ' << r << endl;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < r; j++) ret[i].push_back(0);
    }
    int total = 0;
    int i = 0, j = 0;
    vector<int> buf;
    for(int i = 400000; i >= 0; i--){
        int c = min(i, l);
        for(int m : v[i]){
            for(int j = 0; j < c; j++) buf.push_back(m);
        }
    }
    int sz = buf.size();
    while(total < ans){
        ret[i][j] = buf[total];
        // cout << i << ' ' << j << ' ' << buf[total] << endl;
        i++;j++;
        if(i == l) {
            j = j-l+r+1;
        }
        i %= l; j %= r;
        total++;
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < r; j++) cout << ret[i][j] << ' ';
        cout << endl;
    }
}