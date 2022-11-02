    #include <iostream>
    #include <algorithm>
    #include <iomanip>
    #include <vector>
    #include <queue>
    #include <set>
    #include <map>
     
    #define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
    #define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;
     
    using namespace std;
    typedef long long ll;
     
    void solve(){
        int n;
        string s;
        cin >> n >> s;
        int cur = 0;
        vector<int> v;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                v.push_back(i-cur);
                cur = i;
            }
        }
        v.push_back(n-cur);
        int ans = 0;
        int idx = 0;
        int cur_end = 1;
        while(idx < v.size()){
            if(v[idx] > 1){
                idx++;
            }else{
                while(cur_end < v.size() && (cur_end <= idx || v[cur_end] <= 1 )){
                    cur_end++;
                }
                if(cur_end >= v.size()) idx++;
                else v[cur_end]--;
                idx++;
            }
            ans++;
        }
       
        cout << ans << endl;
    }
     
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << setprecision(10) << fixed;
        int t; cin >> t;
        for(int i = 0; i < t; i++) solve();
    }