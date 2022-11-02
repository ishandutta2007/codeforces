#include <bits/stdc++.h>
using namespace std;

int t;
int g, h;
const int maxn = (1 << 20) + 10;
int a[maxn];
typedef pair<int, int> pi;
vector<pi> s[maxn];
int dp[maxn];
int val[maxn];
int sub[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> h >> g;
        int n = (1 << h) - 1;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            s[i].clear();
            sub[i] = 0;
        }
        int m = (1 << g) - 1;
        for(int i = n;i >= 1;i--){
            int lson = 2 * i;
            int rson = 2 * i + 1; 
            if(lson <= n and rson <= n){
                int id1 = 0, id2 = 0;
                s[lson].push_back({a[lson], 0});
                s[rson].push_back({a[rson], 1});
                while(true){
                    if(id1 < s[lson].size() and id2 < s[rson].size()){
                        if(s[lson][id1] <= s[rson][id2]){
                            s[i].push_back({s[lson][id1++].first, 0}); 
                        }else{
                            s[i].push_back({s[rson][id2++].first, 1});
                        }
                    }else if(id1 < s[lson].size() or id2 < s[rson].size()){
                        if(id1 < s[lson].size())
                            s[i].push_back({s[lson][id1++].first, 0}); 
                        else
                            s[i].push_back({s[rson][id2++].first, 1});
                    }else{
                        break;
                    }
                }
                s[lson].clear();
                s[rson].clear();
            }
            if(i > m)
                dp[i] = s[i].size() + 1;
            else{
                int l = 0, r = 0;
                dp[i] = dp[lson] + dp[rson];
                int sz = s[i].size();
                for(int j = 0;j < sz;j++){
                    if(s[i][sz - 1 - j].second == 1)
                        r++;
                    else
                        l++;
                    if(l > dp[lson] or r > dp[rson]){
                        dp[i] = j;
                        if(s[i][sz - 1 - j].second == 1){
                            r--;
                        }else{
                            l--;
                        }
                        sub[lson] += l;
                        sub[rson] += r;
                        break;
                    }
                }
                val[i] = s[i][s[i].size() - dp[i]].first;
            }
        } 
        vector<int> ans;
        for(int i = 1;i <= m;i++){
            for(int j = sub[i];j < dp[i];j++){
                ans.push_back(i);
            }
        }
        long long Ans = 0;
        for(int i = 1;i <= m;i++){
            Ans += val[i];
        }
        cout << Ans << endl;
        for(int i = 0;i < ans.size();i++){
            cout << ans[i];
            if(i == ans.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}