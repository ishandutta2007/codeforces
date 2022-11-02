#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t, n;

string s[3];
int id[3];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < 3;i++){
            cin >> s[i];
        }
        memset(id, 0, sizeof(id));
        string ans = "";
        for(int i = 0;i < 3 * n;i++){
            vector<int> cand; 
            for(int j = 0;j < 3;j++){
                if(id[j] < 2 * n)
                    cand.push_back(j);
            }
            if(cand.size() == 0){
                ans.push_back('0');
            }else if(cand.size() == 1){
                int j = cand[0];
                ans.push_back(s[j][id[j]++]);
            }else if(cand.size() == 2){
                int j1 = cand[0];
                int j2 = cand[1];
                if(id[j1] < id[j2]){
                    ans.push_back(s[j2][id[j2]++]);
                }else{
                    ans.push_back(s[j1][id[j1]++]);
                }
            }else{
                int cnt[2] = {0, 0};
                int ch = 0;
                for(int j = 0;j < 3;j++){
                    if(s[j][id[j]] == '0'){
                        cnt[0]++;
                    }else{
                        cnt[1]++;
                    }
                }
                if(cnt[0] < cnt[1])
                    ch = 1;
                ans.push_back('0' + ch);
                for(int j = 0;j < 3;j++){
                    if(s[j][id[j]] == '0' + ch)
                        id[j]++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}